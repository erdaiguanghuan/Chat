#include "setuserdialog.h"
#include "ui_setuserdialog.h"

SetUserDialog::SetUserDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetUserDialog),m_iconid(0)
{
    ui->setupUi(this);
    for(int i = 0;i < 35;++i){
        ui->cbx_icon->addItem(QIcon(QString(":/tx/%1.png").arg(i)),"");
    }

}

SetUserDialog::~SetUserDialog()
{
    delete ui;
}

void SetUserDialog::on_pb_clear_clicked()
{
    ui->le_feeling->setText("");
    ui->le_name->setText("");
}
#include<QMessageBox>
void SetUserDialog::on_pb_commit_clicked()
{
    int iconid = ui->cbx_icon->currentIndex();
    QString name = ui->le_name->text();
    QString feeling = ui->le_feeling->text();

    //重复的判定
    if(m_iconid == iconid && m_name == name && feeling == m_feeling) return ;
    if(name.length() == 0 || name.length() > 20){
        QMessageBox::about(this,"tips","昵称非法");
    }
    if(feeling.length() == 0 || feeling.length() > 20){
        QMessageBox::about(this,"tips","签名非法");
    }
    this->hide();
    Q_EMIT SIG_userSetCommit(iconid,name,feeling);

    slot_setInfo(iconid,name,feeling);
}

void SetUserDialog::slot_setInfo(int iconid, QString name,QString feeling = "谁是口蘑？")
{
    m_iconid= iconid;
    m_name = name;
    m_feeling = feeling;
    ui->cbx_icon->setCurrentIndex(m_iconid);
    ui->le_feeling->setText(m_feeling);
    ui->le_name->setText(m_name);
}
