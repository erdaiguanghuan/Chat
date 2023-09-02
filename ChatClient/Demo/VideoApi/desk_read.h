#ifndef DESK_READ_H
#define DESK_READ_H

#include <QObject>
#include<QTimer>
#include<QApplication>
#include<QDesktopWidget>
#include<QBuffer>
#include<QScreen>
#include<QImage>
#include"video_common.h"
#include"workthread.h"
class Desk_Read;
class DeskReadThread:public WorkThread{
    Q_OBJECT
public:


    void setDeksRead(Desk_Read *newDeskRead);

public slots:
    void slot_threadReadMore();

private:
    Desk_Read *m_deskRead;
};


class Desk_Read : public QObject
{
    Q_OBJECT
public:
    explicit Desk_Read(QObject *parent = nullptr);
    ~Desk_Read();
signals:
    //开启桌面采集的人需要用的信号（发送出去核心类处理，左侧大图和右侧小图显示）
    void SIG_screenFrame(QImage img);//因为避免影响主线程，采用多线程，参数不能是引用
    //发送出去给服务器，显示到别人的界面上的信号
    void SIG_screenFrameData(QByteArray ba);//同理


public slots:
    void start();
    void pause();
    //获取桌面截图
    void slot_getScreeenFrame();

private:
    QTimer *m_timer;
    QSharedPointer<DeskReadThread> m_deskReadThread;
};

#endif // DESK_READ_H
