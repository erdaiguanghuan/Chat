#ifndef CKERNEL_H
#define CKERNEL_H
#include<string>
#include <QObject>
#include "logindialog.h"
#include "demodialog.h"
#include "TcpClientMediator.h"
#include "packdef.h"
#include"md5/md5.h"
#include"roomdialog.h"
#include"setuserdialog.h"
#include<map>
#include"audio_read.h"
#include"audio_write.h"
#include"video_read.h"
#include"desk_read.h"
#include"workthread.h"
using namespace std;
class CKernel;
typedef void (CKernel::*PFUN)(uint socket,char* buf,int nlen);


//为了优化发送导致的卡顿，采用多线程，让工作者线程去执行
class SendThread:public WorkThread
{
    Q_OBJECT
public:

public slots:
    void slot_threadSendData(uint socket,char* buf,int nlen);
private:
};



//单例
class CKernel : public QObject
{
    Q_OBJECT
private:
    explicit CKernel(QObject *parent = nullptr);
    ~CKernel();
    CKernel( const CKernel& kernel){}

signals:
    void SIG_sendVideoFrame(uint socket,char* buf,int nlen);
public:
    static CKernel* getInstance()
    {
        static CKernel kernel;
        return &kernel;
    }
public slots:
    //设置协议映射关系
    void setNetMap();
    //初始化配置
    void setConfig();  //设置配置文件

    //回收
    void slot_destroy();
    //网络处理
    void slot_dealData(uint socket,char* buf,int nlen);

    //网络处理函数
    void slot_dealLoginRs(uint socket,char* buf,int nlen);
    void slot_dealRegisterRs(uint socket,char* buf,int nlen);
    void slot_dealCreateRoomRs(uint socket,char* buf,int nlen);
    void slot_dealJoinRoomRs(uint socket,char* buf,int nlen);
    void slot_dealRoomMemberRq(uint socket,char* buf,int nlen);
    void slot_dealUserInfoRq(uint socket,char* buf,int nlen);
    void slot_dealLeaveRoomRq(uint socket,char* buf,int nlen);
    void slot_dealAudioFrame(uint socket,char* buf,int nlen);
    void slot_dealVideoFrame(uint socket,char* buf,int nlen);
    //客户端发送数据
    void slot_clientSendData( uint socket,char* buf,int nlen );
    //视频发送接口
    void slot_clientVideoSendData( uint socket,char* buf,int nlen );
    //音频发送接口
    void slot_clientAudioSendData( uint socket,char* buf,int nlen );
    void slot_destroyInstance();
    //注册提交槽函数
    void slot_registerCommit(QString tel,QString passwd);
    //登录提交槽函数
    void slot_loginCommit(QString tel,QString passwd);
    void slot_joinRoom();
    void slot_createRoom();
    void slot_setJoinedRoom(int roomid);
    void slot_setUser();
    void slot_userSetCommit(int iconid,QString name,QString feeling);
    void slot_quitRoom();
    //音频 视频 控制开关
    void slot_audioOpen();
    void slot_audioClose();
    void slot_captureOpen();
    void slot_captureClose();
    void slot_deskOpen();
    void slot_deskClose();

    void slot_sendAudioFrame(QByteArray& ba);
    //刷新右侧列表的图像
    void slot_refreshVideoImage(QImage img);
    void slot_sendVideoFrameData(QByteArray ba);
    //刷新左侧的大图
    void slot_refreshUserImage(int id, QImage &img);
    //处理用户点击特效的槽函数
    void slot_setFunnyPic(int picid);
private:
    //void SendData(unsigned int lSenfIp,char* buf,int nlen);
private:
    PFUN            m_netMap[DEF_PACK_BASE];
    LoginDialog*    m_loginDialog;
    DemoDialog*     m_demoDialog;
    INetMediator*   m_client;
    QString         m_serverIP;
    int m_userid;
    int m_port;
    int m_roomid;
    RoomDialog *m_roomDialog;
    QString m_name;
    QString m_sysPath;
    string getMD5(QString val);
    SetUserDialog *m_setUserDialog;
    //保存右侧列表所有人
    std::map<int,UserShow*> m_mapIDToUserShow;
    //音频
    Audio_Read *m_audioRead;
    //Audio_Write每个用户都要创建一个
    std::map<int,Audio_Write*> m_mapIDToAudioWrite;
    video_read *m_videoRead;
    Desk_Read * m_deskRead;
    QSharedPointer<SendThread> m_sendVideoThread;
    //视频和音频单独的TCP
    INetMediator* m_tcpAV[2];//0是音频 1是视频
};

#endif // CKERNEL_H
