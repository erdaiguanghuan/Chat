/********************************************************************************
** Form generated from reading UI file 'setuserdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETUSERDIALOG_H
#define UI_SETUSERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SetUserDialog
{
public:
    QPushButton *pb_clear;
    QPushButton *pb_commit;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *lb_icon;
    QComboBox *cbx_icon;
    QLabel *lb_name;
    QLineEdit *le_name;
    QLabel *lb_feeling;
    QLineEdit *le_feeling;

    void setupUi(QDialog *SetUserDialog)
    {
        if (SetUserDialog->objectName().isEmpty())
            SetUserDialog->setObjectName(QString::fromUtf8("SetUserDialog"));
        SetUserDialog->resize(360, 287);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        SetUserDialog->setFont(font);
        pb_clear = new QPushButton(SetUserDialog);
        pb_clear->setObjectName(QString::fromUtf8("pb_clear"));
        pb_clear->setGeometry(QRect(160, 250, 93, 28));
        pb_clear->setMinimumSize(QSize(93, 28));
        pb_clear->setMaximumSize(QSize(93, 28));
        pb_commit = new QPushButton(SetUserDialog);
        pb_commit->setObjectName(QString::fromUtf8("pb_commit"));
        pb_commit->setGeometry(QRect(260, 250, 93, 28));
        pb_commit->setMinimumSize(QSize(93, 28));
        pb_commit->setMaximumSize(QSize(93, 28));
        widget = new QWidget(SetUserDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 20, 341, 211));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lb_icon = new QLabel(widget);
        lb_icon->setObjectName(QString::fromUtf8("lb_icon"));
        lb_icon->setMinimumSize(QSize(0, 30));
        lb_icon->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(lb_icon, 0, 0, 1, 1);

        cbx_icon = new QComboBox(widget);
        cbx_icon->setObjectName(QString::fromUtf8("cbx_icon"));
        cbx_icon->setMinimumSize(QSize(90, 60));
        cbx_icon->setMaximumSize(QSize(90, 60));
        cbx_icon->setIconSize(QSize(60, 60));

        gridLayout->addWidget(cbx_icon, 0, 1, 1, 1);

        lb_name = new QLabel(widget);
        lb_name->setObjectName(QString::fromUtf8("lb_name"));
        lb_name->setMinimumSize(QSize(0, 30));
        lb_name->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(lb_name, 1, 0, 1, 1);

        le_name = new QLineEdit(widget);
        le_name->setObjectName(QString::fromUtf8("le_name"));
        le_name->setMinimumSize(QSize(0, 30));
        le_name->setMaximumSize(QSize(16777215, 30));
        le_name->setClearButtonEnabled(true);

        gridLayout->addWidget(le_name, 1, 1, 1, 1);

        lb_feeling = new QLabel(widget);
        lb_feeling->setObjectName(QString::fromUtf8("lb_feeling"));
        lb_feeling->setMinimumSize(QSize(0, 30));
        lb_feeling->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(lb_feeling, 2, 0, 1, 1);

        le_feeling = new QLineEdit(widget);
        le_feeling->setObjectName(QString::fromUtf8("le_feeling"));
        le_feeling->setMinimumSize(QSize(0, 30));
        le_feeling->setMaximumSize(QSize(16777215, 30));
        le_feeling->setClearButtonEnabled(true);

        gridLayout->addWidget(le_feeling, 2, 1, 1, 1);


        retranslateUi(SetUserDialog);

        QMetaObject::connectSlotsByName(SetUserDialog);
    } // setupUi

    void retranslateUi(QDialog *SetUserDialog)
    {
        SetUserDialog->setWindowTitle(QApplication::translate("SetUserDialog", "Dialog", nullptr));
        pb_clear->setText(QApplication::translate("SetUserDialog", "\346\270\205\347\251\272", nullptr));
        pb_commit->setText(QApplication::translate("SetUserDialog", "\346\217\220\344\272\244", nullptr));
        lb_icon->setText(QApplication::translate("SetUserDialog", "\347\224\250\346\210\267\345\244\264\345\203\217", nullptr));
        lb_name->setText(QApplication::translate("SetUserDialog", "\347\224\250\346\210\267\346\230\265\347\247\260", nullptr));
        lb_feeling->setText(QApplication::translate("SetUserDialog", "\344\270\252\346\200\247\347\255\276\345\220\215", nullptr));
        le_feeling->setText(QApplication::translate("SetUserDialog", "\350\260\201\346\230\257\345\217\243\350\230\221\357\274\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SetUserDialog: public Ui_SetUserDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETUSERDIALOG_H
