/********************************************************************************
** Form generated from reading UI file 'roomdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOMDIALOG_H
#define UI_ROOMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "usershow.h"

QT_BEGIN_NAMESPACE

class Ui_RoomDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *wdg_top;
    QHBoxLayout *horizontalLayout;
    QLabel *lb_title;
    QSpacerItem *horizontalSpacer;
    QPushButton *pb_hide;
    QPushButton *pb_min;
    QPushButton *pb_max;
    QPushButton *pb_colse;
    QWidget *wdg_mid;
    QHBoxLayout *horizontalLayout_2;
    UserShow *wdg_bigShow;
    QScrollArea *sa_userList;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QWidget *wdg_userList;
    QSpacerItem *verticalSpacer;
    QWidget *wdg_bottom;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *cb_capture;
    QCheckBox *cb_audio;
    QCheckBox *cb_desk;
    QLabel *lb_moji;
    QComboBox *cbx_moji;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pb_quit;

    void setupUi(QDialog *RoomDialog)
    {
        if (RoomDialog->objectName().isEmpty())
            RoomDialog->setObjectName(QStringLiteral("RoomDialog"));
        RoomDialog->resize(801, 600);
        RoomDialog->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        RoomDialog->setFont(font);
        RoomDialog->setSizeGripEnabled(true);
        verticalLayout = new QVBoxLayout(RoomDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        wdg_top = new QWidget(RoomDialog);
        wdg_top->setObjectName(QStringLiteral("wdg_top"));
        wdg_top->setMinimumSize(QSize(100, 50));
        wdg_top->setMaximumSize(QSize(16777215, 50));
        horizontalLayout = new QHBoxLayout(wdg_top);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, 0, 10, 0);
        lb_title = new QLabel(wdg_top);
        lb_title->setObjectName(QStringLiteral("lb_title"));
        lb_title->setFont(font);

        horizontalLayout->addWidget(lb_title);

        horizontalSpacer = new QSpacerItem(495, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pb_hide = new QPushButton(wdg_top);
        pb_hide->setObjectName(QStringLiteral("pb_hide"));
        pb_hide->setMinimumSize(QSize(30, 30));
        pb_hide->setMaximumSize(QSize(30, 30));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/color.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_hide->setIcon(icon);
        pb_hide->setFlat(true);

        horizontalLayout->addWidget(pb_hide);

        pb_min = new QPushButton(wdg_top);
        pb_min->setObjectName(QStringLiteral("pb_min"));
        pb_min->setMinimumSize(QSize(30, 30));
        pb_min->setMaximumSize(QSize(30, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        pb_min->setFont(font1);
        pb_min->setFlat(true);

        horizontalLayout->addWidget(pb_min);

        pb_max = new QPushButton(wdg_top);
        pb_max->setObjectName(QStringLiteral("pb_max"));
        pb_max->setMinimumSize(QSize(30, 30));
        pb_max->setMaximumSize(QSize(30, 30));
        pb_max->setFont(font1);
        pb_max->setFlat(true);

        horizontalLayout->addWidget(pb_max);

        pb_colse = new QPushButton(wdg_top);
        pb_colse->setObjectName(QStringLiteral("pb_colse"));
        pb_colse->setMinimumSize(QSize(30, 30));
        pb_colse->setMaximumSize(QSize(30, 30));
        pb_colse->setFont(font1);
        pb_colse->setFlat(true);

        horizontalLayout->addWidget(pb_colse);


        verticalLayout->addWidget(wdg_top);

        wdg_mid = new QWidget(RoomDialog);
        wdg_mid->setObjectName(QStringLiteral("wdg_mid"));
        wdg_mid->setMinimumSize(QSize(801, 450));
        horizontalLayout_2 = new QHBoxLayout(wdg_mid);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(10, 0, 10, 0);
        wdg_bigShow = new UserShow(wdg_mid);
        wdg_bigShow->setObjectName(QStringLiteral("wdg_bigShow"));

        horizontalLayout_2->addWidget(wdg_bigShow);

        sa_userList = new QScrollArea(wdg_mid);
        sa_userList->setObjectName(QStringLiteral("sa_userList"));
        sa_userList->setMinimumSize(QSize(220, 0));
        sa_userList->setMaximumSize(QSize(220, 16777215));
        sa_userList->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 218, 497));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        wdg_userList = new QWidget(scrollAreaWidgetContents);
        wdg_userList->setObjectName(QStringLiteral("wdg_userList"));

        verticalLayout_2->addWidget(wdg_userList);

        verticalSpacer = new QSpacerItem(20, 484, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        sa_userList->setWidget(scrollAreaWidgetContents);

        horizontalLayout_2->addWidget(sa_userList);


        verticalLayout->addWidget(wdg_mid);

        wdg_bottom = new QWidget(RoomDialog);
        wdg_bottom->setObjectName(QStringLiteral("wdg_bottom"));
        horizontalLayout_3 = new QHBoxLayout(wdg_bottom);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        cb_capture = new QCheckBox(wdg_bottom);
        cb_capture->setObjectName(QStringLiteral("cb_capture"));

        horizontalLayout_3->addWidget(cb_capture);

        cb_audio = new QCheckBox(wdg_bottom);
        cb_audio->setObjectName(QStringLiteral("cb_audio"));

        horizontalLayout_3->addWidget(cb_audio);

        cb_desk = new QCheckBox(wdg_bottom);
        cb_desk->setObjectName(QStringLiteral("cb_desk"));

        horizontalLayout_3->addWidget(cb_desk);

        lb_moji = new QLabel(wdg_bottom);
        lb_moji->setObjectName(QStringLiteral("lb_moji"));

        horizontalLayout_3->addWidget(lb_moji);

        cbx_moji = new QComboBox(wdg_bottom);
        cbx_moji->setObjectName(QStringLiteral("cbx_moji"));

        horizontalLayout_3->addWidget(cbx_moji);

        horizontalSpacer_3 = new QSpacerItem(289, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pb_quit = new QPushButton(wdg_bottom);
        pb_quit->setObjectName(QStringLiteral("pb_quit"));

        horizontalLayout_3->addWidget(pb_quit);


        verticalLayout->addWidget(wdg_bottom);


        retranslateUi(RoomDialog);

        QMetaObject::connectSlotsByName(RoomDialog);
    } // setupUi

    void retranslateUi(QDialog *RoomDialog)
    {
        RoomDialog->setWindowTitle(QApplication::translate("RoomDialog", "Dialog", 0));
        lb_title->setText(QApplication::translate("RoomDialog", "\346\210\277\351\227\264\345\217\267:000000", 0));
        pb_hide->setText(QString());
        pb_min->setText(QApplication::translate("RoomDialog", "\344\270\200", 0));
        pb_max->setText(QApplication::translate("RoomDialog", "\345\217\243", 0));
        pb_colse->setText(QApplication::translate("RoomDialog", "X", 0));
        cb_capture->setText(QApplication::translate("RoomDialog", "\346\221\204\345\203\217\345\244\264", 0));
        cb_audio->setText(QApplication::translate("RoomDialog", "\351\272\246\345\205\213\351\243\216", 0));
        cb_desk->setText(QApplication::translate("RoomDialog", "\351\207\207\351\233\206\346\241\214\351\235\242", 0));
        lb_moji->setText(QApplication::translate("RoomDialog", "\346\273\244\351\225\234", 0));
        cbx_moji->clear();
        cbx_moji->insertItems(0, QStringList()
         << QApplication::translate("RoomDialog", "\346\227\240", 0)
         << QApplication::translate("RoomDialog", "\345\205\224\345\255\220\350\200\263\346\234\265", 0)
         << QApplication::translate("RoomDialog", "\345\234\243\350\257\236\345\270\275\345\255\220", 0)
        );
        pb_quit->setText(QApplication::translate("RoomDialog", "\351\200\200\345\207\272", 0));
    } // retranslateUi

};

namespace Ui {
    class RoomDialog: public Ui_RoomDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMDIALOG_H
