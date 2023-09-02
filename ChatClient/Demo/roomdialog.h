#ifndef ROOMDIALOG_H
#define ROOMDIALOG_H

#include <QDialog>
#include<QVBoxLayout>
#include"customwidget.h"
#include"usershow.h"
namespace Ui {
class RoomDialog;
}

class RoomDialog : public CustomMoveDialog//无边框涉及
{
    Q_OBJECT

public:
    explicit RoomDialog(QWidget *parent = 0);
    ~RoomDialog();
signals:
    void SIG_quitRoom();
    //摄像头 音频 桌面
    void SIG_audioOpen();
    void SIG_audioClose();
    void SIG_captureOpen();
    void SIG_captureClose();
    void SIG_deskOpen();
    void SIG_deskClose();
    void SIG_setFunnyPic(int picid);

public slots:
    void slot_setRoomID(int roomid);
    //添加用户和移除用户
    void slot_addUser(QWidget *user);
    void slot_removeUser(QWidget *user);
    void slot_setRoomClear();
    void slot_setBigImage(int userid,QImage& img);
    //设置左侧大图的信息
    void slot_setBigImageInfo(int id,QString name);
private slots:
    void on_pb_colse_clicked();

    void on_pb_max_clicked();

    void on_pb_min_clicked();

    void on_pb_hide_clicked();//隐藏或显示右侧列表

    void on_pb_quit_clicked();

    void on_cb_audio_clicked();

    void on_cb_capture_clicked();

    void on_cb_desk_clicked();
    //特效对应的槽函数
    void on_cbx_moji_currentIndexChanged(int index);

private:
    Ui::RoomDialog *ui;
    //用户列表的布局,想要往QWidget上添加控件需要添加一个布局，然后往布局上添加控件，
    //由于用户是一个一个往下，所以添加一个垂直布局
    QVBoxLayout *m_userLayout;
};

#endif // ROOMDIALOG_H
