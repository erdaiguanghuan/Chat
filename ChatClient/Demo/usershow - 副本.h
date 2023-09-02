#ifndef USERSHOW_H
#define USERSHOW_H
/*用户列表每个小控件的类*/
#include <QWidget>
#include<QPaintEvent>
namespace Ui {
class UserShow;
}
class CKernel;
class UserShow : public QWidget
{
    Q_OBJECT

public:
    explicit UserShow(QWidget *parent = nullptr);
    ~UserShow();
    void slot_setInfo(int id,QString name);
    //重写重绘事件,把每个用户的控件的背景设置为黑色
    void paintEvent(QPaintEvent *event);
private:
    Ui::UserShow *ui;
    int m_id;//后面涉及到点击这个人预览改变，所以需要记录id
    QString m_name;
    friend class CKernel;
};

#endif // USERSHOW_H
