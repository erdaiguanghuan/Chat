#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QCloseEvent>
#include<QMessageBox>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();
signals:
    void SIG_close();
    void SIG_registerCommit(QString tel,QString passwd);
    void SIG_loginCommit(QString tel,QString passwd);
public:
    void closeEvent(QCloseEvent *event);
private slots:
    void on_pb_clear_register_clicked();

    void on_pb_commit_register_clicked();

    void on_pb_clear_clicked();

    void on_pb_commit_clicked();

private:
    Ui::LoginDialog *ui;
};

#endif // LOGINDIALOG_H
