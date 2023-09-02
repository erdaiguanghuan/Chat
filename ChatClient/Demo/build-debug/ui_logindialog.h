/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QLabel *lb_icon;
    QTabWidget *tw_page;
    QWidget *page1;
    QLineEdit *le_passwd_register;
    QLabel *lb_passwd_register;
    QPushButton *pb_commit_register;
    QPushButton *pb_clear_register;
    QLabel *lb_tel_register;
    QLineEdit *le_tel_register;
    QLabel *lb_confirm_register;
    QLineEdit *le_confirm_register;
    QWidget *page2;
    QLabel *lb_passwd;
    QLabel *lb_tel;
    QLineEdit *le_tel;
    QPushButton *pb_commit;
    QLineEdit *le_passwd;
    QPushButton *pb_clear;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QStringLiteral("LoginDialog"));
        LoginDialog->resize(613, 330);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(11);
        LoginDialog->setFont(font);
        lb_icon = new QLabel(LoginDialog);
        lb_icon->setObjectName(QStringLiteral("lb_icon"));
        lb_icon->setGeometry(QRect(11, 4, 191, 321));
        lb_icon->setPixmap(QPixmap(QString::fromUtf8(":/images/register.png")));
        lb_icon->setScaledContents(true);
        tw_page = new QTabWidget(LoginDialog);
        tw_page->setObjectName(QStringLiteral("tw_page"));
        tw_page->setGeometry(QRect(220, 10, 391, 321));
        page1 = new QWidget();
        page1->setObjectName(QStringLiteral("page1"));
        le_passwd_register = new QLineEdit(page1);
        le_passwd_register->setObjectName(QStringLiteral("le_passwd_register"));
        le_passwd_register->setGeometry(QRect(130, 80, 221, 30));
        le_passwd_register->setEchoMode(QLineEdit::Password);
        lb_passwd_register = new QLabel(page1);
        lb_passwd_register->setObjectName(QStringLiteral("lb_passwd_register"));
        lb_passwd_register->setGeometry(QRect(0, 80, 121, 30));
        lb_passwd_register->setAlignment(Qt::AlignCenter);
        pb_commit_register = new QPushButton(page1);
        pb_commit_register->setObjectName(QStringLiteral("pb_commit_register"));
        pb_commit_register->setGeometry(QRect(240, 210, 93, 30));
        pb_clear_register = new QPushButton(page1);
        pb_clear_register->setObjectName(QStringLiteral("pb_clear_register"));
        pb_clear_register->setGeometry(QRect(130, 210, 93, 30));
        lb_tel_register = new QLabel(page1);
        lb_tel_register->setObjectName(QStringLiteral("lb_tel_register"));
        lb_tel_register->setGeometry(QRect(-10, 10, 131, 30));
        lb_tel_register->setAlignment(Qt::AlignCenter);
        le_tel_register = new QLineEdit(page1);
        le_tel_register->setObjectName(QStringLiteral("le_tel_register"));
        le_tel_register->setGeometry(QRect(130, 10, 221, 30));
        lb_confirm_register = new QLabel(page1);
        lb_confirm_register->setObjectName(QStringLiteral("lb_confirm_register"));
        lb_confirm_register->setGeometry(QRect(0, 130, 121, 30));
        lb_confirm_register->setAlignment(Qt::AlignCenter);
        le_confirm_register = new QLineEdit(page1);
        le_confirm_register->setObjectName(QStringLiteral("le_confirm_register"));
        le_confirm_register->setGeometry(QRect(130, 130, 221, 30));
        le_confirm_register->setEchoMode(QLineEdit::Password);
        tw_page->addTab(page1, QString());
        page2 = new QWidget();
        page2->setObjectName(QStringLiteral("page2"));
        lb_passwd = new QLabel(page2);
        lb_passwd->setObjectName(QStringLiteral("lb_passwd"));
        lb_passwd->setGeometry(QRect(10, 90, 131, 30));
        lb_passwd->setAlignment(Qt::AlignCenter);
        lb_tel = new QLabel(page2);
        lb_tel->setObjectName(QStringLiteral("lb_tel"));
        lb_tel->setGeometry(QRect(10, 20, 131, 30));
        lb_tel->setAlignment(Qt::AlignCenter);
        le_tel = new QLineEdit(page2);
        le_tel->setObjectName(QStringLiteral("le_tel"));
        le_tel->setGeometry(QRect(150, 20, 221, 30));
        pb_commit = new QPushButton(page2);
        pb_commit->setObjectName(QStringLiteral("pb_commit"));
        pb_commit->setGeometry(QRect(260, 220, 93, 30));
        le_passwd = new QLineEdit(page2);
        le_passwd->setObjectName(QStringLiteral("le_passwd"));
        le_passwd->setGeometry(QRect(150, 90, 221, 30));
        le_passwd->setEchoMode(QLineEdit::Password);
        pb_clear = new QPushButton(page2);
        pb_clear->setObjectName(QStringLiteral("pb_clear"));
        pb_clear->setGeometry(QRect(150, 220, 93, 30));
        tw_page->addTab(page2, QString());
        QWidget::setTabOrder(le_tel, le_passwd);
        QWidget::setTabOrder(le_passwd, pb_commit);
        QWidget::setTabOrder(pb_commit, pb_clear);
        QWidget::setTabOrder(pb_clear, tw_page);
        QWidget::setTabOrder(tw_page, le_tel_register);
        QWidget::setTabOrder(le_tel_register, le_passwd_register);
        QWidget::setTabOrder(le_passwd_register, le_confirm_register);
        QWidget::setTabOrder(le_confirm_register, pb_commit_register);
        QWidget::setTabOrder(pb_commit_register, pb_clear_register);

        retranslateUi(LoginDialog);

        tw_page->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "Dialog", 0));
        lb_icon->setText(QString());
#ifndef QT_NO_TOOLTIP
        tw_page->setToolTip(QApplication::translate("LoginDialog", "<html><head/><body><p>\347\241\256\350\256\244\345\257\206\347\240\201</p><p><br/></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        le_passwd_register->setText(QApplication::translate("LoginDialog", "123456", 0));
        lb_passwd_register->setText(QApplication::translate("LoginDialog", "\345\257\206\347\240\201", 0));
        pb_commit_register->setText(QApplication::translate("LoginDialog", "\346\217\220\344\272\244", 0));
        pb_clear_register->setText(QApplication::translate("LoginDialog", "\346\270\205\347\251\272", 0));
        lb_tel_register->setText(QApplication::translate("LoginDialog", "\346\211\213\346\234\272\345\217\267", 0));
        le_tel_register->setText(QApplication::translate("LoginDialog", "18845279237", 0));
        lb_confirm_register->setText(QApplication::translate("LoginDialog", "\347\241\256\350\256\244\345\257\206\347\240\201", 0));
        le_confirm_register->setText(QApplication::translate("LoginDialog", "123456", 0));
        tw_page->setTabText(tw_page->indexOf(page1), QApplication::translate("LoginDialog", "\346\263\250\345\206\214", 0));
        lb_passwd->setText(QApplication::translate("LoginDialog", "\345\257\206\347\240\201", 0));
        lb_tel->setText(QApplication::translate("LoginDialog", "\346\211\213\346\234\272\345\217\267", 0));
        le_tel->setText(QApplication::translate("LoginDialog", "18845279237", 0));
        pb_commit->setText(QApplication::translate("LoginDialog", "\346\217\220\344\272\244", 0));
        le_passwd->setText(QApplication::translate("LoginDialog", "123456", 0));
        pb_clear->setText(QApplication::translate("LoginDialog", "\346\270\205\347\251\272", 0));
        tw_page->setTabText(tw_page->indexOf(page2), QApplication::translate("LoginDialog", "\347\231\273\345\275\225", 0));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
