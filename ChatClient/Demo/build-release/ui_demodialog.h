/********************************************************************************
** Form generated from reading UI file 'demodialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEMODIALOG_H
#define UI_DEMODIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DemoDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *wdg_content;
    QVBoxLayout *verticalLayout_2;
    QWidget *wdg_title;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *lb_title_icon;
    QLabel *lb_title;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pb_min;
    QPushButton *pb_close;
    QWidget *wdg_user;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pb_icon;
    QLabel *lb_name;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pb_setup;
    QWidget *wdg_room;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *pb_join;
    QToolButton *pb_create;
    QToolButton *pb_history;
    QWidget *widget_5;

    void setupUi(QDialog *DemoDialog)
    {
        if (DemoDialog->objectName().isEmpty())
            DemoDialog->setObjectName(QString::fromUtf8("DemoDialog"));
        DemoDialog->resize(400, 600);
        DemoDialog->setMinimumSize(QSize(400, 600));
        DemoDialog->setMaximumSize(QSize(400, 600));
        verticalLayout = new QVBoxLayout(DemoDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        wdg_content = new QWidget(DemoDialog);
        wdg_content->setObjectName(QString::fromUtf8("wdg_content"));
        wdg_content->setMaximumSize(QSize(400, 600));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        wdg_content->setFont(font);
        wdg_content->setStyleSheet(QString::fromUtf8("background-color: rgb(150,150,150);\n"
"color: rgb(255, 255, 255);\n"
""));
        verticalLayout_2 = new QVBoxLayout(wdg_content);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(1, 1, 1, 1);
        wdg_title = new QWidget(wdg_content);
        wdg_title->setObjectName(QString::fromUtf8("wdg_title"));
        wdg_title->setMinimumSize(QSize(100, 40));
        wdg_title->setMaximumSize(QSize(16777215, 40));
        horizontalLayout = new QHBoxLayout(wdg_title);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(115, 15, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        lb_title_icon = new QLabel(wdg_title);
        lb_title_icon->setObjectName(QString::fromUtf8("lb_title_icon"));
        lb_title_icon->setMinimumSize(QSize(30, 30));
        lb_title_icon->setMaximumSize(QSize(30, 30));
        lb_title_icon->setPixmap(QPixmap(QString::fromUtf8(":/images/12.png")));
        lb_title_icon->setScaledContents(true);

        horizontalLayout->addWidget(lb_title_icon);

        lb_title = new QLabel(wdg_title);
        lb_title->setObjectName(QString::fromUtf8("lb_title"));
        lb_title->setMinimumSize(QSize(0, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        lb_title->setFont(font1);
        lb_title->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);

        horizontalLayout->addWidget(lb_title);

        horizontalSpacer_3 = new QSpacerItem(46, 15, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        pb_min = new QPushButton(wdg_title);
        pb_min->setObjectName(QString::fromUtf8("pb_min"));
        pb_min->setMinimumSize(QSize(30, 30));
        pb_min->setMaximumSize(QSize(30, 30));
        pb_min->setFocusPolicy(Qt::NoFocus);
        pb_min->setFlat(true);

        horizontalLayout->addWidget(pb_min);

        pb_close = new QPushButton(wdg_title);
        pb_close->setObjectName(QString::fromUtf8("pb_close"));
        pb_close->setMinimumSize(QSize(30, 30));
        pb_close->setMaximumSize(QSize(30, 30));
        pb_close->setFocusPolicy(Qt::NoFocus);
        pb_close->setFlat(true);

        horizontalLayout->addWidget(pb_close);


        verticalLayout_2->addWidget(wdg_title);

        wdg_user = new QWidget(wdg_content);
        wdg_user->setObjectName(QString::fromUtf8("wdg_user"));
        wdg_user->setMinimumSize(QSize(0, 60));
        wdg_user->setMaximumSize(QSize(16777215, 60));
        horizontalLayout_2 = new QHBoxLayout(wdg_user);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pb_icon = new QPushButton(wdg_user);
        pb_icon->setObjectName(QString::fromUtf8("pb_icon"));
        pb_icon->setMinimumSize(QSize(50, 50));
        pb_icon->setMaximumSize(QSize(50, 50));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/tx/22.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_icon->setIcon(icon);
        pb_icon->setIconSize(QSize(50, 50));

        horizontalLayout_2->addWidget(pb_icon);

        lb_name = new QLabel(wdg_user);
        lb_name->setObjectName(QString::fromUtf8("lb_name"));
        lb_name->setMinimumSize(QSize(0, 50));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        lb_name->setFont(font2);

        horizontalLayout_2->addWidget(lb_name);

        horizontalSpacer_2 = new QSpacerItem(204, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pb_setup = new QPushButton(wdg_user);
        pb_setup->setObjectName(QString::fromUtf8("pb_setup"));
        pb_setup->setMinimumSize(QSize(30, 30));
        pb_setup->setMaximumSize(QSize(30, 30));
        pb_setup->setLayoutDirection(Qt::LeftToRight);
        pb_setup->setAutoFillBackground(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/sett.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_setup->setIcon(icon1);
        pb_setup->setIconSize(QSize(30, 30));
        pb_setup->setCheckable(false);
        pb_setup->setFlat(true);

        horizontalLayout_2->addWidget(pb_setup);

        pb_icon->raise();
        lb_name->raise();
        pb_setup->raise();

        verticalLayout_2->addWidget(wdg_user);

        wdg_room = new QWidget(wdg_content);
        wdg_room->setObjectName(QString::fromUtf8("wdg_room"));
        wdg_room->setMinimumSize(QSize(0, 70));
        wdg_room->setMaximumSize(QSize(16777215, 70));
        horizontalLayout_3 = new QHBoxLayout(wdg_room);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pb_join = new QToolButton(wdg_room);
        pb_join->setObjectName(QString::fromUtf8("pb_join"));
        pb_join->setMinimumSize(QSize(100, 55));
        pb_join->setMaximumSize(QSize(100, 40));
        pb_join->setFont(font2);
        pb_join->setStyleSheet(QString::fromUtf8(""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/00.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_join->setIcon(icon2);
        pb_join->setIconSize(QSize(30, 30));
        pb_join->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        pb_join->setAutoRaise(true);

        horizontalLayout_3->addWidget(pb_join);

        pb_create = new QToolButton(wdg_room);
        pb_create->setObjectName(QString::fromUtf8("pb_create"));
        pb_create->setMinimumSize(QSize(100, 55));
        pb_create->setMaximumSize(QSize(100, 40));
        pb_create->setFont(font2);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/01.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_create->setIcon(icon3);
        pb_create->setIconSize(QSize(30, 30));
        pb_create->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        pb_create->setAutoRaise(true);

        horizontalLayout_3->addWidget(pb_create);

        pb_history = new QToolButton(wdg_room);
        pb_history->setObjectName(QString::fromUtf8("pb_history"));
        pb_history->setMinimumSize(QSize(100, 55));
        pb_history->setMaximumSize(QSize(100, 40));
        pb_history->setFont(font2);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/02.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_history->setIcon(icon4);
        pb_history->setIconSize(QSize(30, 30));
        pb_history->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        pb_history->setAutoRaise(true);

        horizontalLayout_3->addWidget(pb_history);


        verticalLayout_2->addWidget(wdg_room);

        widget_5 = new QWidget(wdg_content);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));

        verticalLayout_2->addWidget(widget_5);


        verticalLayout->addWidget(wdg_content);


        retranslateUi(DemoDialog);

        QMetaObject::connectSlotsByName(DemoDialog);
    } // setupUi

    void retranslateUi(QDialog *DemoDialog)
    {
        DemoDialog->setWindowTitle(QApplication::translate("DemoDialog", "DemoDialog", nullptr));
        lb_title_icon->setText(QString());
        lb_title->setText(QApplication::translate("DemoDialog", "\345\217\243\350\230\221\344\274\232\350\256\256", nullptr));
        pb_min->setText(QApplication::translate("DemoDialog", "\342\200\224", nullptr));
        pb_close->setText(QApplication::translate("DemoDialog", "X", nullptr));
        pb_icon->setText(QString());
        lb_name->setText(QApplication::translate("DemoDialog", "\346\210\221\347\232\204\345\220\215\345\255\227", nullptr));
        pb_setup->setText(QString());
        pb_join->setText(QApplication::translate("DemoDialog", "\345\212\240\345\205\245\344\274\232\350\256\256", nullptr));
        pb_create->setText(QApplication::translate("DemoDialog", "\345\210\233\345\273\272\344\274\232\350\256\256", nullptr));
        pb_history->setText(QApplication::translate("DemoDialog", "\344\274\232\350\256\256\350\256\260\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DemoDialog: public Ui_DemoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEMODIALOG_H
