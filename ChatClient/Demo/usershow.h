#ifndef USERSHOW_H
#define USERSHOW_H
/*用户列表每个小控件的类*/
#include <QWidget>
#include<QPaintEvent>
#include<QMouseEvent>
namespace Ui {
class UserShow;
}
class CKernel;
class RoomDialog;
class UserShow : public QWidget
{
    Q_OBJECT
signals:
    void SIG_userClicked(int id,QString name);
public:
    explicit UserShow(QWidget *parent = nullptr);
    ~UserShow();
public slots:

    void slot_setInfo(int id,QString name);
    void slot_setImage(QImage& img);
    //重写重绘事件,把每个用户的控件的背景设置为黑色
    void paintEvent(QPaintEvent *event);
    //重写鼠标点击事件
    void mousePressEvent(QMouseEvent *event);

private:
    Ui::UserShow *ui;
    int m_id;//后面涉及到点击这个人预览改变，所以需要记录id
    QString m_name;
    friend class CKernel;
    friend class RoomDialog;
    QImage m_img;
};

#endif // USERSHOW_H
