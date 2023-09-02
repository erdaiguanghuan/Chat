#include "roomdialog.h"
#include "ui_roomdialog.h"

RoomDialog::RoomDialog(QWidget *parent) :
    CustomMoveDialog(parent),
    ui(new Ui::RoomDialog)
{
    ui->setupUi(this);
    m_userLayout=new QVBoxLayout;
    //用户列表垂直布局
    ui->wdg_userList->setLayout(m_userLayout);
    //设置边距
    m_userLayout->setContentsMargins(0,0,0,0);
    m_userLayout->setSpacing(5);
    //可以通过addWidget添加控件

/*    //添加测试用户
    UserShow *user1=new UserShow;
    user1->slot_setInfo(1,"路人1");
    UserShow *user2=new UserShow;
    user2->slot_setInfo(2,"路人1");
    UserShow *user3=new UserShow;
    user3->slot_setInfo(3,"路人3");
    UserShow *user4=new UserShow;
    user4->slot_setInfo(4,"路人4");
    UserShow *user5=new UserShow;
    user5->slot_setInfo(5,"路人5");

    slot_addUser(user1);
    slot_addUser(user2);
    slot_addUser(user3);
    slot_addUser(user4);
    slot_addUser(user5)*/;


}

RoomDialog::~RoomDialog()
{
    delete ui;
}

void RoomDialog::slot_setRoomID(int roomid)
{
    ui->lb_title->setText(QString("房间号[%1]").arg(roomid));
}

void RoomDialog::slot_addUser(QWidget *user)
{
    m_userLayout->addWidget(user);
}

void RoomDialog::slot_removeUser(QWidget *user)
{
    user->hide();
    m_userLayout->removeWidget(user);
    delete user;
}

void RoomDialog::slot_setRoomClear()
{
    //设置ui
    ui->cb_audio->setChecked(false);
    ui->cb_capture->setChecked(false);
    ui->cb_desk->setChecked(false);

    //发信号
    Q_EMIT SIG_audioClose();
    Q_EMIT SIG_captureClose();
    Q_EMIT SIG_deskClose();

}

void RoomDialog::slot_setBigImage(int userid, QImage& img)
{
    //判断 如果是自己的话再把图片显示上去
    if(ui->wdg_bigShow->m_id==userid)
        ui->wdg_bigShow->slot_setImage(img);
}

void RoomDialog::slot_setBigImageInfo(int id,QString name)
{
    ui->wdg_bigShow->slot_setInfo(id,name);

}

void RoomDialog::on_pb_colse_clicked()
{
    on_pb_quit_clicked();

}


void RoomDialog::on_pb_max_clicked()
{
    this->slot_showMax();
}


void RoomDialog::on_pb_min_clicked()
{
    this->slot_showMin();

}


void RoomDialog::on_pb_hide_clicked()
{
    if(ui->sa_userList->isHidden()){
        ui->sa_userList->show();
    }else{
        ui->sa_userList->hide();
    }
}
#include<qDebug>

#include<QMessageBox>
void RoomDialog::on_pb_quit_clicked()
{
    if(QMessageBox::question(this,"tips","是否退出房间？") == QMessageBox::Yes){
        qDebug() << __func__;
        Q_EMIT SIG_quitRoom();
        this->close();
    }

}


void RoomDialog::on_cb_audio_clicked()
{
    //判断是否被勾选
    if(ui->cb_audio->isChecked()){

        //ui->cb_audio->setChecked(false);
        //发送开启信号
        Q_EMIT SIG_audioOpen();
        //发送关闭信号
        Q_EMIT SIG_audioClose();
    }
    else{
        //ui->cb_audio->setChecked(true);
        //发送关闭信号
        Q_EMIT SIG_audioClose();
    }

}


void RoomDialog::on_cb_capture_clicked()
{
    if(ui->cb_capture->isChecked()){
        //关闭摄像头
//        ui->cb_capture->setChecked(false);
        ui->cb_desk->setChecked(false);
        //发送摄像头开启、桌面采集关闭信号
        Q_EMIT SIG_captureOpen();
        Q_EMIT SIG_deskClose();


    }else{
        //开启摄像头，关闭桌面采集
//        ui->cb_capture->setChecked(true);
        //发送关闭信号
        Q_EMIT SIG_captureClose();
    }

}


void RoomDialog::on_cb_desk_clicked()
{
    if(ui->cb_desk->isChecked()){
        //关闭桌面采集
//        ui->cb_desk->setChecked(false);
        ui->cb_capture->setChecked(false);
        //发送桌面采集开启、摄像头关闭信号
        Q_EMIT SIG_deskOpen();
        Q_EMIT SIG_captureClose();



    }else{
        //开启桌面采集，关闭摄像头
//        ui->cb_desk->setChecked(true);
        //发送桌面采集关闭信号
        Q_EMIT SIG_deskClose();
    }

}


void RoomDialog::on_cbx_moji_currentIndexChanged(int index)
{
    //1和2分别代表耳朵和帽子，如果选择了1或2，就发信号出去
    if(index==1||index==2){
        Q_EMIT SIG_setFunnyPic(index);
    }

}

