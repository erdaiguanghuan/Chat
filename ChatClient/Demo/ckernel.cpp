#include "ckernel.h"
#include"qDebug"
#include<QCoreApplication>
#include<QSettings>
#include<QFileInfo>
#include<QDir>


//通过宏定义化简
#define NetMap(x)  m_netMap[ x - _DEF_PROTOCOL_BASE ]


//协议映射关系
void CKernel::setNetMap()
{
    memset( m_netMap , 0 , sizeof(PFUN ));

    //    m_netMap[ _DEF_PACK_LOGIN_RS - _DEF_PROTOCOL_BASE ] = &CKernel::slot_dealLoginRs;
    NetMap(DEF_PACK_LOGIN_RS) = &CKernel::slot_dealLoginRs;
    NetMap(DEF_PACK_REGISTER_RS) = &CKernel::slot_dealRegisterRs;
    //房间
    NetMap(DEF_PACK_CREATEROOM_RS) = &CKernel::slot_dealCreateRoomRs;
    NetMap(DEF_PACK_JOINROOM_RS) = &CKernel::slot_dealJoinRoomRs;
    NetMap(DEF_PACK_ROOM_MEMBER) =&CKernel::slot_dealRoomMemberRq;
    NetMap(DEF_PACK_USER_INFO_RQ) = &CKernel::slot_dealUserInfoRq;
    NetMap(DEF_PACK_LEAVEROOM_RQ) = &CKernel::slot_dealLeaveRoomRq;
    NetMap(DEF_PACK_AUDIO_FRAME) = &CKernel::slot_dealAudioFrame;
    NetMap(DEF_PACK_VIDEO_FRAME) = &CKernel::slot_dealVideoFrame;
}
#include<QSettings>
#include<QApplication>
#include<QFileInfo>
void CKernel::setConfig()
{

    m_serverIP=_DEF_SERVER_IP;

    QString path=QApplication::applicationDirPath()+"config.ini";
    //判断文件是否存在
    QFileInfo info(path);
    qDebug()<<path;
    QSettings settings(path,QSettings::IniFormat,NULL);
    if(info.exists()){
        //加载配置文件，将ip设置为配置文件里的ip
        settings.beginGroup("Net");
        QVariant ip=settings.value("ip");
        QString strIp=ip.toString();
        settings.endGroup();
        if(!strIp.isEmpty()){
            m_serverIP=strIp;

        }

    }else{
        //没有，创建配置文件，写入默认的ip
        settings.beginGroup("Net");
        settings.setValue("ip",m_serverIP);
        settings.endGroup();
    }
    qDebug()<<m_serverIP;

}

#define MD5_KEY "1234"
string CKernel::getMD5(QString val)
{
    QString str = QString("%1_%2").arg(val).arg(MD5_KEY);   //加盐，是其隐私性更高
    MD5 md = (str.toStdString());
    qDebug() << str << "MD5：" << md.toString().c_str();
    return md.toString();
}




CKernel::CKernel(QObject *parent) : QObject(parent),m_userid(0)
  ,m_roomid(0),m_sendVideoThread(new SendThread)
{
    //设置协议映射关系
    setNetMap();
    setConfig();

    m_loginDialog   = new LoginDialog;
    m_demoDialog    = new DemoDialog;

    m_client        = new TcpClientMediator;
    connect( m_client , SIGNAL(SIG_ReadyData(uint,char*,int))
             , this , SLOT( slot_dealData(uint,char*,int)) );
    //构造音频和视频的TCP连接
    for(int i=0;i<2;i++){
        m_tcpAV[i]=new TcpClientMediator;
        connect( m_tcpAV[i] , SIGNAL(SIG_ReadyData(uint,char*,int))
                 , this , SLOT( slot_dealData(uint,char*,int)) );
        m_tcpAV[i]->OpenNet( m_serverIP.toStdString().c_str() );
    }
    connect( m_loginDialog , SIGNAL(SIG_close())
             ,this , SLOT(slot_destroy()) );

    connect( m_demoDialog , SIGNAL(SIG_close())
             ,this , SLOT(slot_destroy()) );
    connect(m_loginDialog,SIGNAL(SIG_registerCommit(QString,QString)),
            this,SLOT(slot_registerCommit(QString,QString)));
    connect(m_loginDialog,SIGNAL(SIG_loginCommit(QString,QString)),
            this,SLOT(slot_loginCommit(QString,QString)));
    connect(m_demoDialog,SIGNAL(SIG_createRoom()),
            this,SLOT(slot_createRoom()));
    connect(m_demoDialog,SIGNAL(SIG_joinRoom()),
            this,SLOT(slot_joinRoom()));
    connect(m_demoDialog,SIGNAL(SIG_setUser()),
            this,SLOT(slot_setUser()));

    m_client->OpenNet( m_serverIP.toStdString().c_str() );

    m_loginDialog->show();
    m_roomDialog = new RoomDialog;
    m_setUserDialog = new SetUserDialog;

    connect(m_roomDialog,SIGNAL(SIG_quitRoom()),
            this,SLOT(slot_quitRoom()));

    //todo
    connect(m_setUserDialog,SIGNAL(SIG_userSetCommit(int,QString,QString)),
            this,SLOT(slot_userSetCommit(int,QString,QString)));

    //    //测试 登录 验证与服务器的链接
    //    STRU_LOGIN_RQ rq;
    //    strcpy( rq.tel , "123" );
    //    strcpy( rq.password , "123");

    //    m_client->SendData( 0 , (char*)&rq , sizeof(rq) );
    m_audioRead=new Audio_Read;
    m_videoRead=new video_read;
    m_deskRead=new Desk_Read;
    connect(m_audioRead,SIGNAL(SIG_audioFrame(QByteArray&)),
            this,SLOT(slot_sendAudioFrame(QByteArray&)));

    connect(m_videoRead,SIGNAL(SIG_videoFrame(QImage)),
            this,SLOT(slot_refreshVideoImage(QImage)));
    connect(m_videoRead,SIGNAL(SIG_videoFrameData(QByteArray)),
            this,SLOT(slot_sendVideoFrameData(QByteArray)));
    connect(m_deskRead,SIGNAL(SIG_screenFrame(QImage)),
            this,SLOT(slot_refreshVideoImage(QImage)));
    connect(m_deskRead,SIGNAL(SIG_screenFrameData(QByteArray)),
            this,SLOT(slot_sendVideoFrameData(QByteArray)));

    connect(m_roomDialog,SIGNAL(SIG_audioOpen()),
            this,SLOT(slot_audioOpen()));
    connect(m_roomDialog,SIGNAL(SIG_audioClose()),
            this,SLOT(slot_audioClose()));
    connect(m_roomDialog,SIGNAL(SIG_captureOpen()),
            this,SLOT(slot_captureOpen()));
    connect(m_roomDialog,SIGNAL(SIG_captureClose()),
            this,SLOT(slot_captureClose()));
    connect(m_roomDialog,SIGNAL(SIG_deskOpen()),
            m_deskRead,SLOT(start()));
    connect(m_roomDialog,SIGNAL(SIG_deskClose()),
            m_deskRead,SLOT(pause()));
    connect(m_roomDialog,SIGNAL(SIG_setFunnyPic(int)),
            this,SLOT(slot_setFunnyPic(int)));
    connect(this,SIGNAL(SIG_sendVideoFrame(uint,char*,int)),
            m_sendVideoThread.get(),SLOT(slot_threadSendData(uint,char*,int)));
}


CKernel::~CKernel()
{
    //    slot_destroy();
}



void CKernel::slot_destroy()
{
    qDebug() << __func__;

    if( m_loginDialog ){
        m_loginDialog->hide(); //不写close 不然会触发关闭事件会死循环
        delete m_loginDialog; m_loginDialog = NULL;
    }
    if( m_demoDialog ){
        m_demoDialog->hide();
        delete m_demoDialog; m_demoDialog = NULL;
    }
    if(m_audioRead){
        delete m_audioRead;
        m_audioRead=nullptr;
    }
    if(m_videoRead){
        delete m_videoRead;
        m_videoRead=nullptr;
    }
    if( m_client ){
        m_client->CloseNet();
        delete m_client; m_client = NULL;
    }
    if(m_roomDialog){
        m_roomDialog->hide();
        delete m_roomDialog;m_roomDialog = NULL;
    }

    if(m_setUserDialog){
        m_setUserDialog->hide();
        delete m_setUserDialog;m_setUserDialog = NULL;
    }
}

void CKernel::slot_dealData(uint socket, char *buf, int nlen)
{
    //协议映射表
    int type = *(int*)buf;
    if( type >= _DEF_PROTOCOL_BASE && type < _DEF_PROTOCOL_BASE + DEF_PACK_BASE )
    {
        PFUN pf = NetMap(type);
        if( pf )
            (this->*pf)( socket , buf , nlen );
    }

    delete[] buf;
}
//#define user_not_exist		(0)
//#define password_error		(1)
//#define login_success		(2)
void CKernel::slot_dealLoginRs(uint socket, char *buf, int nlen)
{
    qDebug() << __func__;
    STRU_LOGIN_RS *rs=(STRU_LOGIN_RS*)buf;
    switch (rs->result) {
    case user_not_exist:
        QMessageBox::about(m_loginDialog,"提示","用户不存在");
        break;
    case password_error:
        QMessageBox::about(m_loginDialog,"提示","密码错误");
        break;
    case login_success:
        //QMessageBox::about(m_loginDialog,"提示","登录成功");
        qDebug()<<"login_success";
        //todo
        m_userid=rs->userid;
        m_loginDialog->hide();
        m_demoDialog->showNormal();
        //注册视频和音频
        STRU_AUDIO_REGISTER audiorq;
        audiorq.m_userid=m_userid;
        slot_clientAudioSendData(0,(char *)&audiorq,sizeof(audiorq));

        STRU_AUDIO_REGISTER videorq;
        videorq.m_userid=m_userid;
        slot_clientAudioSendData(0,(char *)&videorq,sizeof(videorq));

        break;
    }

}
#include<QMessageBox>
void CKernel::slot_dealRegisterRs(uint socket, char *buf, int nlen)
{
    STRU_REGISTER_RS *rs=(STRU_REGISTER_RS*)buf;
    switch (rs->result) {
    case tel_is_exist:
        QMessageBox::about(m_loginDialog,"提示","用户已存在，注册失败");
        break;
    case register_success:
        QMessageBox::about(m_loginDialog,"提示","注册成功");
        break;
    }

}

void CKernel::slot_dealCreateRoomRs(uint socket, char *buf, int nlen)
{
    //100%成功
    STRU_CREATEROOM_RS *rs = (STRU_CREATEROOM_RS*)buf;
    slot_setJoinedRoom(rs->m_RoomId);

}

void CKernel::slot_dealJoinRoomRs(uint socket, char *buf, int nlen)
{
    //100%成功
    STRU_JOINROOM_RS *rs = (STRU_JOINROOM_RS*)buf;
    if(rs->m_lResult != join_success){
        QMessageBox::about(this->m_demoDialog,"提示","房间不存在，加入失败");
        return;
    }
    slot_setJoinedRoom(rs->m_RoomID);
}

void CKernel::slot_dealRoomMemberRq(uint socket, char *buf, int nlen)
{

    //拆包
    STRU_ROOM_MEMBER_RQ *rq=(STRU_ROOM_MEMBER_RQ*)buf;
    //添加自己到房间显示
    UserShow *user=new UserShow;
    user->slot_setInfo(rq->m_UserID,QString::fromStdString(rq->m_szUser));
    //绑定点击右侧控件的信号的槽函数
    connect(user,SIGNAL(SIG_userClicked(int,QString)),
            m_roomDialog,SLOT(slot_setBigImageInfo(int,QString)));
    //查重
    if(m_mapIDToUserShow.count(rq->m_UserID)>0){
        UserShow *old=m_mapIDToUserShow[rq->m_UserID];
        m_mapIDToUserShow.erase(rq->m_UserID);
        m_roomDialog->slot_removeUser(old);
    }
    m_mapIDToUserShow[rq->m_UserID] = user;
    m_roomDialog->slot_addUser(user);
    //创建音频对象
    if(m_mapIDToAudioWrite.count(rq->m_UserID)>0){
        Audio_Write *aw=m_mapIDToAudioWrite[rq->m_UserID];
        m_mapIDToAudioWrite.erase(rq->m_UserID);
        delete aw;
    }
    Audio_Write *aw=new Audio_Write;
    m_mapIDToAudioWrite[rq->m_UserID]=aw;

}

void CKernel::slot_dealUserInfoRq(uint socket, char *buf, int nlen)
{
    //拆包
    STRU_USER_INFO_RQ *rq = (STRU_USER_INFO_RQ*)buf;
    //更新ui
    m_name = QString::fromStdString(rq->m_szUser);
    m_demoDialog->slot_setInfo(m_name,rq->m_iconid);
    //更新设置ui
    m_setUserDialog->slot_setInfo(rq->m_iconid,m_name,
                                  QString::fromStdString(rq->m_userFeeling));
}

void CKernel::slot_dealLeaveRoomRq(uint socket, char *buf, int nlen)
{
    //拆包
    STRU_LEAVEROOM_RQ *rq = (STRU_LEAVEROOM_RQ*)buf;
    //删除特定的人
    if(m_mapIDToUserShow.count(rq->m_nUserId) == 0) return ;
    UserShow *user = m_mapIDToUserShow[rq->m_nUserId];
    m_mapIDToUserShow.erase(user->m_id);
    m_roomDialog->slot_removeUser(user);



    //todo  音频map中去掉这个人
    m_mapIDToAudioWrite.erase(user->m_id);

}

void CKernel::slot_setJoinedRoom(int roomid){
    m_roomid = roomid;

    //可以写成原界面隐藏  或者  按钮失效
    //m_demoDialog->hide();  按键变灰代替窗口隐藏
    m_demoDialog->slot_setPushButton_enable(false);
    m_roomDialog->showNormal();
    //初始化状态，清空等操作，可以复用
    //todo
    m_roomDialog->slot_setRoomID(roomid);
    //添加自己到房间显示
    UserShow *user=new UserShow;
    user->slot_setInfo(m_userid,m_name);
    connect(user,SIGNAL(SIG_userClicked(int,QString)),
            m_roomDialog,SLOT(slot_setBigImageInfo(int,QString)));

    m_mapIDToUserShow[m_userid] = user;
    m_roomDialog->slot_addUser(user);
}

//弹出框
void CKernel::slot_setUser()
{
    m_setUserDialog->show();
}

void CKernel::slot_userSetCommit(int iconid, QString name, QString feeling)
{
    //发包
    //中文兼容 utf8
    std::string strName = name.toStdString();
    std::string strfeeling = feeling.toStdString();
    STRU_USER_INFO_RQ rq;
    rq.m_iconid = iconid;
    rq.m_UserID = m_userid;
    strcpy(rq.m_userFeeling,strfeeling.c_str());
    strcpy(rq.m_szUser,strName.c_str());
    slot_clientSendData(0,(char*)&rq,sizeof(rq));

    QMessageBox::about(this->m_demoDialog,"提示","用户信息设置成功");
}

void CKernel::slot_quitRoom()
{
    qDebug() << __func__;
    //发包
    STRU_LEAVEROOM_RQ rq;
    rq.m_nUserId = m_userid;
    rq.m_RoomId = m_roomid;

    slot_clientSendData(0,(char*)&rq,sizeof(rq));
    m_roomid = 0;
    m_demoDialog->slot_setPushButton_enable(true);
    //声音关闭  ui  后台
    m_roomDialog->slot_setRoomClear();


    //视频回收
    for(auto ite = m_mapIDToUserShow.begin();ite != m_mapIDToUserShow.end();/*++ite*/){
        UserShow *user = ite->second;
        ite=m_mapIDToUserShow.erase(ite);
        m_roomDialog->slot_removeUser(user);
    }
    //音频播放的回收
    for(auto ite = m_mapIDToAudioWrite.begin();ite != m_mapIDToAudioWrite.end();/*++ite*/){
        Audio_Write* user = ite->second;
        ite=m_mapIDToAudioWrite.erase(ite);
        delete user;

    }

}

void CKernel::slot_audioOpen()
{
    m_audioRead->start();

}

void CKernel::slot_audioClose()
{
    m_audioRead->pause();

}

void CKernel::slot_captureOpen()
{
    m_videoRead->start();

}

void CKernel::slot_captureClose()
{

    m_videoRead->pause();
}

void CKernel::slot_deskOpen()
{

}

void CKernel::slot_deskClose()
{

}
#include<QTime>
void CKernel::slot_sendAudioFrame(QByteArray &ba)
{
    ///音频数据帧
    /// 成员描述
    /// int type;
    /// int userId;
    /// int roomId;
    /// int hour;
    /// int min;
    /// int sec;
    /// int msec;
    /// QByteArray audioFrame;  --> char frame[]; 柔性数组
    ///
    int type=DEF_PACK_AUDIO_FRAME;
    int userid=m_userid;
    int roomid=m_roomid;
    QTime tm=QTime::currentTime();
    int hour=tm.hour();
    int min=tm.minute();
    int sec=tm.second();
    int msec=tm.msec();
    char *audioData=ba.data();
    int len=ba.size();
    //序列化数据(指把数据一个一个的装到一个连续的缓冲区里)
    char *buf=new char[sizeof(int)*7+len];
    char *tmp=buf;
    *(int*)tmp=type;
    tmp+=sizeof(int);
    *(int*)tmp=userid;
    tmp+=sizeof(int);
    *(int*)tmp=roomid;
    tmp+=sizeof(int);
    *(int*)tmp=hour;
    tmp+=sizeof(int);
    *(int*)tmp=min;
    tmp+=sizeof(int);
    *(int*)tmp=sec;
    tmp+=sizeof(int);
    *(int*)tmp=msec;
    tmp+=sizeof(int);
    memcpy(tmp,audioData,len);

    slot_clientAudioSendData(0,buf,sizeof(int)*7+len);
    delete []buf;
}
//刷新画面  主要使用在采集
void CKernel::slot_refreshVideoImage(QImage img)
{
    slot_refreshUserImage(m_userid,img);

}
//显示某个用户
void CKernel::slot_refreshUserImage(int id, QImage &img)
{
    //左侧预览图显示
    m_roomDialog->slot_setBigImage(id,img);
    //右侧列表图显示
    if(m_mapIDToUserShow.count(id)>0){
        UserShow *user=m_mapIDToUserShow[id];
        user->slot_setImage(img);
    }

}

void CKernel::slot_setFunnyPic(int picid)
{
    m_videoRead->setFunnyPic(picid);
}

void CKernel::slot_sendVideoFrameData(QByteArray ba)
{
    ///视频数据帧
    /// 成员描述
    /// int type;
    /// int userId;
    /// int roomId;
    /// int hour;
    /// int min;
    /// int sec;
    /// int msec;
    /// QByteArray videoFrame;
    ///
    int type=DEF_PACK_VIDEO_FRAME;
    int userid=m_userid;
    int roomid=m_roomid;
    QTime tm=QTime::currentTime();
    int hour=tm.hour();
    int min=tm.minute();
    int sec=tm.second();
    int msec=tm.msec();
    char *audioData=ba.data();
    int len=ba.size();
    //序列化数据(指把数据一个一个的装到一个连续的缓冲区里)
    char *buf=new char[sizeof(int)*7+len];
    char *tmp=buf;
    *(int*)tmp=type;
    tmp+=sizeof(int);
    *(int*)tmp=userid;
    tmp+=sizeof(int);
    *(int*)tmp=roomid;
    tmp+=sizeof(int);
    *(int*)tmp=hour;
    tmp+=sizeof(int);
    *(int*)tmp=min;
    tmp+=sizeof(int);
    *(int*)tmp=sec;
    tmp+=sizeof(int);
    *(int*)tmp=msec;
    tmp+=sizeof(int);
    memcpy(tmp,audioData,len);

//    slot_clientSendData(0,buf,sizeof(int)*7+len);
//    delete []buf;
    //替换为发送信号
    Q_EMIT SIG_sendVideoFrame(0,buf,sizeof(int)*7+len);


}
void CKernel::slot_dealAudioFrame(uint socket, char *buf, int nlen)
{
    //反序列化

    int type;
    int userid;
    int roomid;
    int hour;
    int min;
    int sec;
    int msec;
    //反序列化数据
    char *tmp=buf;
    *(int*)tmp=type;
    tmp+=sizeof(int);
    userid=*(int*)tmp;
    tmp+=sizeof(int);
    roomid=*(int*)tmp;
    tmp+=sizeof(int);

    tmp+=sizeof(int);

    tmp+=sizeof(int);

    tmp+=sizeof(int);

    tmp+=sizeof(int);

    int audioLen=nlen-7*sizeof(int);
    //音频数据
    QByteArray ba(tmp,audioLen);
    if(m_mapIDToAudioWrite.count(userid)>0){
        Audio_Write *aw=m_mapIDToAudioWrite[userid];
        aw->slot_net_rx(ba);//解压并进行格式转换
    }

}

void CKernel::slot_dealVideoFrame(uint socket, char *buf, int nlen)
{
    int type;
    int userid;
    int roomid;
    int hour;
    int min;
    int sec;
    int msec;
    //反序列化数据
    char *tmp=buf;
    *(int*)tmp=type;
    tmp+=sizeof(int);
    userid=*(int*)tmp;
    tmp+=sizeof(int);
    roomid=*(int*)tmp;
    tmp+=sizeof(int);

    tmp+=sizeof(int);

    tmp+=sizeof(int);

    tmp+=sizeof(int);

    tmp+=sizeof(int);

    int imageLen=nlen-7*sizeof(int);
    QImage img;
    img.loadFromData((const uchar *)tmp,imageLen);

    slot_refreshUserImage(userid,img);
}
void CKernel::slot_clientSendData(uint socket, char *buf, int nlen)
{
    m_client->SendData( socket , buf , nlen );
}

void CKernel::slot_clientVideoSendData(uint socket, char *buf, int nlen)
{
    m_tcpAV[1]->SendData(socket , buf , nlen );
}

void CKernel::slot_clientAudioSendData(uint socket, char *buf, int nlen)
{
    m_tcpAV[0]->SendData(socket , buf , nlen );
}

void CKernel::slot_destroyInstance()
{
    qDebug() << __func__ ;

    //回收网络
    //m_quit = true;
    m_client->CloseNet();
    //    m_tcpServer->CloseNet();
    delete m_client;
    //    delete m_tcpServer;

    //m_mainDialog->hide();  //隐藏
    //delete m_mainDialog;
    delete m_loginDialog;

}

void CKernel::slot_registerCommit(QString tel, QString passwd)
{
    STRU_REGISTER_RQ rq;
    std::string telStr = tel.toStdString();
    strcpy_s(rq.tel,telStr.c_str());

    //将明文变成密文  MD5值
    // MD5 信息摘要算法第5版
    std::string passwordStr = getMD5(passwd);/*passwd.toStdString();*/
    strcpy_s(rq.password,passwordStr.c_str());

    slot_clientSendData(0,(char*)&rq,sizeof(rq));

}

void CKernel::slot_loginCommit(QString tel, QString passwd)
{
    STRU_LOGIN_RQ rq;
    std::string telStr = tel.toStdString();
    strcpy_s(rq.tel,telStr.c_str());

    std::string passwordStr = getMD5(passwd);/*passwd.toStdString();*/
    strcpy_s(rq.password,passwordStr.c_str());

    slot_clientSendData(0,(char*)&rq,sizeof(rq));

}

#include<QInputDialog>
//加入房间
void CKernel::slot_joinRoom()
{
    if(m_roomid != 0){
        QMessageBox::about(this->m_demoDialog,"提示",
                           "已在房间中，加入失败");
    }
    //要加入什么房间
    int roomid = QInputDialog::getInt(this->m_demoDialog,"加入房间",
                                      "房间号:");
    //格式 房间号 100000~999999 6位房间号
    if(roomid < 100000 || roomid > 999999){
        QMessageBox::about(this->m_demoDialog,"提示","输入的房间号非法，加入失败");
        return ;
    }
    qDebug() << roomid;

    //发送请求
    STRU_JOINROOM_RQ rq;
    rq.m_UserID = m_userid;
    rq.m_RoomID = roomid;
    slot_clientSendData(0,(char*)&rq,sizeof(rq));
}

//创建房间
void CKernel::slot_createRoom()
{
    //发送请求
    STRU_CREATEROOM_RQ rq;
    rq.m_UserID = m_userid;
    slot_clientSendData(0,(char*)&rq,sizeof(rq));
}


void SendThread::slot_threadSendData(uint socket, char *buf, int nlen)
{
    //判断是否延迟  丢包
    char *tmp=buf;
//类型
    tmp+=sizeof(int);
//用户id
    tmp+=sizeof(int);
//房间id
    tmp+=sizeof(int);
    int hour=*(int*)tmp;
    tmp+=sizeof(int);
    int min=*(int*)tmp;
    tmp+=sizeof(int);
    int sec=*(int*)tmp;
    tmp+=sizeof(int);
    int msec=*(int*)tmp;
    tmp+=sizeof(int);

    QTime tm(hour,min,sec,msec);
    //判断延迟超过200ms，丢弃包
    if(tm.msecsTo(QTime::currentTime())<=200)
        CKernel::getInstance()->slot_clientVideoSendData(socket,buf,nlen);
        //CKernel::getInstance()->slot_clientSendData(socket,buf,nlen);
    delete []buf;
}
