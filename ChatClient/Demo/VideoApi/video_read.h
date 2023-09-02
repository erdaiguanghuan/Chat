#ifndef VIDEO_READ_H
#define VIDEO_READ_H
#include"video_common.h"
#include<QMessageBox>
#include <QObject>
#include<QTimer>
#include<QBuffer>
#include"myfacedetect.h"
//采集摄像头视频
class video_read : public QObject
{
    Q_OBJECT
public:
    explicit video_read(QObject *parent = nullptr);
    ~video_read();
    enum funnyPic_type{ fp_tuer = 1 , fp_hat };
    void setFunnyPic(int newFunnyPic);

signals:
    //直接用来显示我的照片的信号（不发给服务器），也可以通过下面那个信号，采集到后先发给服务器，然后服务器再转发回来
    void SIG_videoFrame(QImage image);
    //数据信号,将我的图像发出去给服务器的信号(发送的是压缩后的图像)
    void SIG_videoFrameData(QByteArray bt);

public slots:
    void start();
    void pause();
    void slot_readMore();
private:
    cv::VideoCapture cap;
    QTimer *m_timer;
    int m_funnyPic; // 用于存储当前的萌拍效果 1 兔耳朵 2 帽子

    QImage m_tuer;
    QImage m_hat;
    std::vector<Rect>m_vecLastFace;//用来存储上一次的人脸
};

#endif // VIDEO_READ_H
