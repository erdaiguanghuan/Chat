#include "clogic.h"

void CLogic::setNetPackMap()
{
    NetPackMap(DEF_PACK_REGISTER_RQ)    = &CLogic::RegisterRq;
    NetPackMap(DEF_PACK_LOGIN_RQ)       = &CLogic::LoginRq;
    NetPackMap(DEF_PACK_CREATEROOM_RQ)  = &CLogic::CreateRoomRq;
    NetPackMap(DEF_PACK_JOINROOM_RQ)    = &CLogic::JoinRoomRq;
    NetPackMap(DEF_PACK_USER_INFO_RQ)   = &CLogic::UserInfoRq;
    NetPackMap(DEF_PACK_LEAVEROOM_RQ)   = &CLogic::LeaveRoomRq;
    NetPackMap(DEF_PACK_AUDIO_FRAME)  = &CLogic::AudioFrame;
    NetPackMap(DEF_PACK_VIDEO_FRAME)   = &CLogic::VideoFrame;
    NetPackMap(DEF_PACK_AUDIO_REGISTER)  = &CLogic::AudioRegister;
    NetPackMap(DEF_PACK_VIDEO_REGISTER)   = &CLogic::VideoRegister;
}

//注册
void CLogic::RegisterRq(sock_fd clientfd,char* szbuf,int nlen)
{
    printf("clientfd:%d RegisterRq\n", clientfd);
    STRU_REGISTER_RQ *rq=(STRU_REGISTER_RQ*)szbuf;
    list<string> lstRes;
    char strsql[1024];
    sprintf(strsql,"select tel from t_user where tel='%s';",rq->m_tel);
    m_sql->SelectMysql(strsql,1,lstRes);
    STRU_REGISTER_RS rs;
    if(lstRes.size()>0){
        rs.m_lResult=tel_is_exist;
    }else{
        rs.m_lResult=register_success;
        sprintf(strsql,"insert into t_user(tel,password,name,icon,feeling) "
                       "values('%s','%s','%s',5,'谁是口蘑啊?');",
                rq->m_tel,rq->m_password,rq->m_tel);
        if(!m_sql->UpdataMysql(strsql)){
            printf("Update fail:%s\n",strsql);
        }
    }
    SendData(clientfd,(char*)&rs,sizeof(rs));
}

//登录
void CLogic::LoginRq(sock_fd clientfd ,char* szbuf,int nlen)
{
    printf("clientfd:%d LoginRq\n", clientfd);

//    STRU_LOGIN_RS rs;
//    rs.m_lResult = password_error;
//    SendData( clientfd , (char*)&rs , sizeof rs );

    //拆包  tel  passwd
    STRU_LOGIN_RQ *rq = (STRU_LOGIN_RQ*)szbuf;
    STRU_LOGIN_RS rs;

    //查数据库 条件是手机号  查passwd  id  name
    char sqlstr[1024] = "";
    list<string> lstRes;
    sprintf(sqlstr,"select id,password from t_user where tel = '%s';",rq->m_tel);
    bool res=m_sql->SelectMysql(sqlstr,3,lstRes);
    if(!res)
        printf("select error:%s\n",sqlstr);

    if( lstRes.size()==0 )
    {
        //没有结果  ->  user_not_exist
        rs.m_lResult = user_not_exist;
    }
    else
    {

        int id=atoi(lstRes.front().c_str());
        lstRes.pop_front();
        string strPasswd=lstRes.front();
        lstRes.pop_front();
        if(strcmp(strPasswd.c_str(),rq->m_password)!=0){
            rs.m_lResult=password_error;
        }else{
            rs.m_lResult=login_success;
            rs.m_userid=id;
            UserInfo *user=NULL;
            //保存用户对应的socket，方便以后进行通信。
            if(m_mapIdToUserInfo.find(id,user)){
                //查到了
                //要不要，强制上一个登陆的人下线
                //写一个协议包

                //find会完成赋值

                delete user;
         }
            user=new UserInfo;
            user->m_id=id;
            user->m_sockfd=clientfd;
            //user->
            m_mapIdToUserInfo.insert(id,user);
            SendData(clientfd,(char*)&rs,sizeof(rs));
            //同步这个人的状态信息，让登陆者知道自己的info
            GetUserInfoAndSend(id);
            //todo 聊天软件 ->好友列表 离线信息  多媒体->媒体列表
            //微博 推送的消息

            return;
        }



    }
    //发送回复包
    SendData(clientfd,(char*)&rs,sizeof(rs));
}

void CLogic::CreateRoomRq(sock_fd clientfd, char *szbuf, int nlen)
{
    printf("clientfd:%d CreateRoomRq\n", clientfd);
    STRU_CREATEROOM_RQ *rq = (STRU_CREATEROOM_RQ*)szbuf;
    int roomid = 0;
    do{
        roomid = (random()%9+1)*100000 +  random()%100000;
        printf("%d\n",roomid);
    }while(m_mapRoomIDToUserList.IsExist(roomid));  //保存一个房间和成员列表的映射 成员列表 list<int> 为什么不用UserInfo*
    list<int> lst;
    lst.push_back(rq->m_UserID);
    m_mapRoomIDToUserList.insert(roomid,lst);
    //回复
    STRU_CREATEROOM_RS rs;
    rs.m_RoomId = roomid;
    rs.m_lResult = 1;
    SendData(clientfd,(char*)&rs,sizeof(rs));

}

void CLogic::JoinRoomRq(sock_fd clientfd, char *szbuf, int nlen)
{
    printf("clientfd:%d JoinRoomRq\n", clientfd);
    //1.拆包
    STRU_JOINROOM_RQ *rq=(STRU_JOINROOM_RQ*)szbuf;
    STRU_JOINROOM_RS rs;
    //2.判断房间是否存在
    list<int> lst;
    rs.m_RoomID=rq->m_RoomID;//需要给客户端返回房间id，因为客户端发送完加入房间请求后函数结束后房间id就没了
    if(!m_mapRoomIDToUserList.find(rq->m_RoomID,lst)){
        //房间不存在
        rs.m_lResult=room_no_exist;
    }else{
        //存在
        rs.m_lResult=join_success;

    }
    SendData(clientfd,(char*)&rs,sizeof(rs));
    //加入人的信息:包括id和名字（需要去map里查）
    STRU_ROOM_MEMBER_RQ joinrq;
    UserInfo *joinInfo=nullptr;
    if(!m_mapIdToUserInfo.find(rq->m_UserID,joinInfo))//需要知道加入人的姓名
        return ;
    joinrq.m_UserID=rq->m_UserID;
    strcpy(joinrq.m_szUser,joinInfo->m_userName);

    //3.遍历房间成员列表
    for(auto ite=lst.begin();ite!=lst.end();ite++){
        int memid=*ite;
        UserInfo *memInfo=nullptr;
        //可能房间里的人出现异常不在线了
        if(!m_mapIdToUserInfo.find(memid,memInfo))
            continue;//跳过
        //获取每个成员的信息
        STRU_ROOM_MEMBER_RQ memrq;
        memrq.m_UserID=memid;
        strcpy(memrq.m_szUser,memInfo->m_userName);
        //3.1加入人的信息发给房间每个人
        SendData(memInfo->m_sockfd,(char *)&joinrq,sizeof(joinrq));
        //3.2房间里成员的信息发给加入人
        SendData(joinInfo->m_sockfd,(char *)&memrq,sizeof(memrq));
    }

    //4.加入人添加到房间成员列表
    lst.push_back(joinInfo->m_id);
    //5.更新房间列表
    m_mapRoomIDToUserList.insert(rq->m_RoomID,lst);

}

void CLogic::UserInfoRq(sock_fd clientfd, char *szbuf, int nlen)
{
    printf("clientfd:%d UserInfoRq\n", clientfd);
    //拆包
    STRU_USER_INFO_RQ *rq = (STRU_USER_INFO_RQ*)szbuf;
    //mysql修改信息
    rq->m_UserID;
    char sqlstr[1024] = "";
    sprintf(sqlstr,"update t_user set icon = %d,name = '%s',feeling = '%s' where id = %d;"
            ,rq->m_iconid,rq->m_szUser,rq->m_userFeeling,rq->m_UserID);
    m_sql->UpdataMysql(sqlstr);
    GetUserInfoAndSend(rq->m_UserID);


}

void CLogic::LeaveRoomRq(sock_fd clientfd, char *szbuf, int nlen)
{
    printf("clientfd:%d LeaveRoomRq\n", clientfd);
    //拆包
    STRU_LEAVEROOM_RQ *rq = (STRU_LEAVEROOM_RQ*)szbuf;
    list<int> lst;
    if(!m_mapRoomIDToUserList.find(rq->m_RoomId,lst)) return ;
    //根据房间id 获取列表  发给房间里每个人
    for(auto ite = lst.begin();ite != lst.end();){
        int id = *ite;
        if(id == rq->m_nUserId){
            //该人从列表移除
            ite = lst.erase(ite);
        }else{
            //转发
            UserInfo *user = nullptr;
            if(!m_mapIdToUserInfo.find(id,user)) continue;
            SendData(user->m_sockfd,szbuf,nlen);
            ++ite;
        }
    }
    //列表为空，map中移除 不为空更新
    if(lst.size() == 0){
        m_mapRoomIDToUserList.erase(rq->m_RoomId);
    }
    else{
        m_mapRoomIDToUserList.insert(rq->m_RoomId,lst);
    }



}

void CLogic::GetUserInfoAndSend(int id)
{
    //获取信息 from sql
    char sqlstr[1024] = "";
    sprintf(sqlstr,"select name,icon,feeling from t_user where id = %d;",
            id);
    list<string> lst;
    m_sql->SelectMysql(sqlstr,3,lst);
    if(lst.size() != 3) return ;
    string name = lst.front();
    lst.pop_front();
    string iconid = lst.front();
    lst.pop_front();
    string feeling = lst.front();
    lst.pop_front();
    //设置信息UserInfo
    UserInfo * user = nullptr;
    if(!m_mapIdToUserInfo.find(id,user)){
        return;
    }

    strcpy(user->m_userName,name.c_str());
    //发送给客户端
    STRU_USER_INFO_RQ rq;
    rq.m_UserID = id;
    rq.m_iconid = atoi(iconid.c_str());
    strcpy(rq.m_szUser,name.c_str());
    strcpy(rq.m_userFeeling,feeling.c_str());
    SendData(user->m_sockfd,(char*)&rq,sizeof(rq));
}

void CLogic::AudioFrame(sock_fd clientfd, char *szbuf, int nlen)
{
    printf("clientfd:%d AudioFrame\n", clientfd);
    //拆包
    char *tmp=szbuf;
    tmp+=sizeof(int);
    int userid=*(int*)tmp;
    tmp+=sizeof(int);
    int roomid=*(int*)tmp;
    tmp+=sizeof(int);
    //判断房间是否存在
    list<int>lst;
    if(!m_mapRoomIDToUserList.find(roomid,lst))
        return ;
    //遍历房间成员
    for(auto ite=lst.begin();ite!=lst.end();ite++)
    {
        int id=*ite;
        //判断是不是自己，如果不是自己进行转发
        if(id!=userid){
            UserInfo *user=nullptr;
            if(!m_mapIdToUserInfo.find(id,user)) continue;
            SendData(user->m_audiofd,szbuf,nlen);
        }
    }

}

void CLogic::VideoFrame(sock_fd clientfd, char *szbuf, int nlen)
{
    printf("clientfd:%d VideoFrame\n", clientfd);
    //拆包
    char *tmp=szbuf;
    tmp+=sizeof(int);
    int userid=*(int*)tmp;
    tmp+=sizeof(int);
    int roomid=*(int*)tmp;
    tmp+=sizeof(int);
    //判断房间是否存在
    list<int>lst;
    if(!m_mapRoomIDToUserList.find(roomid,lst))
        return ;
    //遍历房间成员
    for(auto ite=lst.begin();ite!=lst.end();ite++)
    {
        int id=*ite;
        //判断是不是自己，如果不是自己进行转发
        if(id!=userid){
            UserInfo *user=nullptr;
            if(!m_mapIdToUserInfo.find(id,user)) continue;
            SendData(user->m_videofd,szbuf,nlen);
        }
    }

}

void CLogic::AudioRegister(sock_fd clientfd, char *szbuf, int nlen)
{
    printf("clientfd:%d AudioRegister\n", clientfd);
    //拆包
    STRU_AUDIO_REGISTER *rq=(STRU_AUDIO_REGISTER *)szbuf;
    //根据id去map里找到对应的用户信息
    UserInfo *user=nullptr;
    if(!m_mapIdToUserInfo.find(rq->m_userid,user)) return ;
    //将音频fd保存到用户信息结构体里
    user->m_audiofd=clientfd;
}

void CLogic::VideoRegister(sock_fd clientfd, char *szbuf, int nlen)
{
    printf("clientfd:%d VideoRegister\n", clientfd);
    //拆包
    STRU_VIDEO_REGISTER *rq=(STRU_VIDEO_REGISTER *)szbuf;
    //根据id去map里找到对应的用户信息
    UserInfo *user=nullptr;
    if(!m_mapIdToUserInfo.find(rq->m_userid,user)) return ;
    //将音频fd保存到用户信息结构体里
    user->m_videofd=clientfd;
}
