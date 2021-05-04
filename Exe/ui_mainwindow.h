/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout_us;
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *LOGIN;
    QPushButton *bt_login;
    QLineEdit *user;
    QLineEdit *pass;
    QWidget *Menu;
    QCommandLinkButton *commandLinkButton;
    QCommandLinkButton *commandLinkButton_2;
    QLabel *label_31;
    QLabel *label_32;
    QLabel *label_35;
    QLabel *label_40;
    QLabel *label_41;
    QWidget *factures;
    QGroupBox *groupBox;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QPushButton *pushButton_4;
    QLabel *Date_2;
    QLabel *Timer_2;
    QLabel *label_36;
    QLabel *label_37;
    QTabWidget *tabWidget;
    QWidget *tab_4;
    QGroupBox *groupBox_3;
    QTableView *tab_fact;
    QPushButton *pushButton;
    QLabel *label_10;
    QLineEdit *lineEdit;
    QPushButton *pdf;
    QPushButton *impr;
    QPushButton *pushButton_2;
    QPushButton *pushButton_5;
    QWidget *tab;
    QGroupBox *groupBox_2;
    QLineEdit *le_id_f;
    QLineEdit *le_ttc_f;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pb_ajouter;
    QDateTimeEdit *date_box;
    QLabel *label_11;
    QComboBox *le_client;
    QLabel *label_14;
    QLabel *label_16;
    QComboBox *le_mode_f;
    QLabel *label_4;
    QWidget *tab_3;
    QGroupBox *groupBox_5;
    QLineEdit *modif_ttc_f;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *pb_modifier;
    QLabel *label_9;
    QComboBox *modif_box;
    QDateTimeEdit *modif_date_f_box;
    QLabel *label_13;
    QLabel *label_15;
    QComboBox *modif_le_client;
    QLabel *label_17;
    QComboBox *modif_le_mode_f;
    QLabel *Lb_client;
    QWidget *tab_2;
    QLabel *label_5;
    QGroupBox *groupBox_4;
    QPushButton *supp;
    QLabel *label_12;
    QComboBox *supr_box;
    QLabel *infos;
    QWidget *tab_5;
    QCustomPlot *widget;
    QWidget *evenements;
    QStackedWidget *stackedWidget_2;
    QWidget *page_4;
    QGroupBox *groupBox_6;
    QToolButton *toolButton_4;
    QToolButton *toolButton_5;
    QToolButton *toolButton_6;
    QPushButton *pushButton_3;
    QLabel *Timer;
    QLabel *Date;
    QLabel *label_39;
    QLabel *label_38;
    QTabWidget *tabWidget_2;
    QWidget *tab_7;
    QGroupBox *groupBox_7;
    QTableView *tab_ev;
    QPushButton *tri_ev;
    QLabel *label_18;
    QLineEdit *recherche_ev;
    QPushButton *pdf_ev;
    QPushButton *impr_ev;
    QPushButton *supp_ev_2;
    QWidget *tab_8;
    QGroupBox *groupBox_8;
    QLineEdit *id_ev;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QPushButton *ajout_ev;
    QDateTimeEdit *dat_fin;
    QLabel *label_23;
    QLabel *label_24;
    QLineEdit *nom_ev;
    QDateTimeEdit *dat_deb;
    QComboBox *produit_inclus;
    QCheckBox *checkBox;
    QLabel *label_25;
    QWidget *tab_9;
    QGroupBox *groupBox_9;
    QLabel *label_29;
    QDateTimeEdit *modif_dat_fin;
    QLabel *label_27;
    QLineEdit *modif_titre_ev;
    QDateTimeEdit *modif_dat_deb;
    QPushButton *modif_ev;
    QComboBox *modif_produit_inclus;
    QLabel *label_30;
    QLabel *label_26;
    QLabel *label_22;
    QLabel *label_28;
    QComboBox *modif_id_ev;
    QLabel *Lb_client_2;
    QWidget *tab_10;
    QLabel *label_33;
    QGroupBox *groupBox_10;
    QPushButton *supp_ev;
    QLabel *label_34;
    QComboBox *supr_ev;
    QLabel *infos_2;
    QProgressBar *progressBar;
    QWidget *page_5;
    QPushButton *qrcode;
    QLabel *qrlabel;
    QMenuBar *menuBar;
    QMenu *menuAbout;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;
    QToolBar *toolBar_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1026, 601);
        actionAbout_us = new QAction(MainWindow);
        actionAbout_us->setObjectName(QStringLiteral("actionAbout_us"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 0, 1011, 531));
        LOGIN = new QWidget();
        LOGIN->setObjectName(QStringLiteral("LOGIN"));
        bt_login = new QPushButton(LOGIN);
        bt_login->setObjectName(QStringLiteral("bt_login"));
        bt_login->setGeometry(QRect(340, 360, 341, 61));
        bt_login->setStyleSheet(QLatin1String("QPushButton {\n"
"background: #11cc95;\n"
"border: 2px solid #029d70;\n"
"border-bottom-color: #029d70; /* same as the pane color */\n"
"border-top-left-radius: 10px;\n"
"border-top-right-radius: 10px;\n"
"min-width: 80px;\n"
"border-radius: 30px;\n"
"color: black;\n"
"font-size:16px;\n"
"font-family:Arial, Helvetica, sans-serif;\n"
"\n"
"\n"
"}\n"
"QPushButton:hover {\n"
"color:#fff;\n"
"background:#029d70;\n"
"border: none;\n"
"\n"
"}\n"
""));
        user = new QLineEdit(LOGIN);
        user->setObjectName(QStringLiteral("user"));
        user->setGeometry(QRect(340, 181, 341, 61));
        QFont font;
        font.setPointSize(10);
        user->setFont(font);
        user->setAutoFillBackground(false);
        user->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
" border-width: 1px;\n"
"border-style: solid;\n"
"border-color: black;\n"
"  border-radius: 30px;\n"
"padding:0 8;\n"
"}"));
        user->setAlignment(Qt::AlignCenter);
        pass = new QLineEdit(LOGIN);
        pass->setObjectName(QStringLiteral("pass"));
        pass->setGeometry(QRect(340, 260, 341, 61));
        pass->setFont(font);
        pass->setAutoFillBackground(false);
        pass->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
" border-width: 1px;\n"
"border-style: solid;\n"
"border-color: black;\n"
"  border-radius: 30px;\n"
"padding:0 8;\n"
"}"));
        pass->setEchoMode(QLineEdit::Password);
        pass->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(LOGIN);
        Menu = new QWidget();
        Menu->setObjectName(QStringLiteral("Menu"));
        commandLinkButton = new QCommandLinkButton(Menu);
        commandLinkButton->setObjectName(QStringLiteral("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(300, 160, 181, 191));
        commandLinkButton->setStyleSheet(QLatin1String("QPushButton{\n"
" border-width: 2px;\n"
"border-style: outset;\n"
"border-color: white;\n"
"border-radius: 20px;\n"
"padding:0 8;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"background:#f5f5f5;\n"
"}\n"
"QPushButton:pressed{\n"
"border-style: inset;\n"
"border-radius: 20px;\n"
"padding:0 8;\n"
"background:#eeeeee;\n"
"}"));
        QIcon icon;
        icon.addFile(QStringLiteral("FOND13 - Copie.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton->setIcon(icon);
        commandLinkButton->setIconSize(QSize(300, 300));
        commandLinkButton_2 = new QCommandLinkButton(Menu);
        commandLinkButton_2->setObjectName(QStringLiteral("commandLinkButton_2"));
        commandLinkButton_2->setGeometry(QRect(520, 160, 181, 191));
        commandLinkButton_2->setStyleSheet(QLatin1String("QPushButton{\n"
" border-width: 2px;\n"
"border-style: outset;\n"
"border-color: white;\n"
"border-radius: 20px;\n"
"padding:0 8;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"background:#f5f5f5;\n"
"}\n"
"QPushButton:pressed{\n"
"border-style: inset;\n"
"border-radius: 20px;\n"
"padding:0 8;\n"
"background:#eeeeee;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("FOND13.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton_2->setIcon(icon1);
        commandLinkButton_2->setIconSize(QSize(300, 300));
        label_31 = new QLabel(Menu);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(110, 20, 131, 121));
        label_32 = new QLabel(Menu);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setGeometry(QRect(360, 360, 56, 16));
        label_35 = new QLabel(Menu);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setGeometry(QRect(580, 360, 71, 16));
        label_40 = new QLabel(Menu);
        label_40->setObjectName(QStringLiteral("label_40"));
        label_40->setGeometry(QRect(10, 490, 241, 16));
        label_41 = new QLabel(Menu);
        label_41->setObjectName(QStringLiteral("label_41"));
        label_41->setGeometry(QRect(10, 510, 241, 16));
        stackedWidget->addWidget(Menu);
        factures = new QWidget();
        factures->setObjectName(QStringLiteral("factures"));
        groupBox = new QGroupBox(factures);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 181, 531));
        toolButton = new QToolButton(groupBox);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(20, 240, 131, 31));
        toolButton->setStyleSheet(QLatin1String("QToolButton {\n"
"background: #dfe3ee;\n"
"border: 2px solid #dfe3ee;\n"
"border-bottom-color: #aaa5a5; /* same as the pane color */\n"
"border-top-left-radius: 7px;\n"
"border-top-right-radius: 7px;\n"
"min-width: 80px;\n"
"border-radius: 8px;\n"
"color: black;\n"
"font-size:12px;\n"
"font-family:Arial, Helvetica, sans-serif;\n"
"\n"
"\n"
"}\n"
"QToolButton:hover {\n"
"color:#fff;\n"
"background:#8b9dc3;\n"
"border: none;\n"
"\n"
"}\n"
""));
        toolButton_2 = new QToolButton(groupBox);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setGeometry(QRect(20, 340, 131, 31));
        toolButton_2->setStyleSheet(QLatin1String("QToolButton {\n"
"background: #dfe3ee;\n"
"border: 2px solid #dfe3ee;\n"
"border-bottom-color: #aaa5a5; /* same as the pane color */\n"
"border-top-left-radius: 7px;\n"
"border-top-right-radius: 7px;\n"
"min-width: 80px;\n"
"border-radius: 8px;\n"
"color: black;\n"
"font-size:12px;\n"
"font-family:Arial, Helvetica, sans-serif;\n"
"\n"
"\n"
"}\n"
"QToolButton:hover {\n"
"color:#fff;\n"
"background:#8b9dc3;\n"
"border: none;\n"
"\n"
"}\n"
""));
        toolButton_3 = new QToolButton(groupBox);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        toolButton_3->setGeometry(QRect(20, 290, 131, 31));
        toolButton_3->setStyleSheet(QLatin1String("QToolButton {\n"
"background: #dfe3ee;\n"
"border: 2px solid #dfe3ee;\n"
"border-bottom-color: #aaa5a5; /* same as the pane color */\n"
"border-top-left-radius: 7px;\n"
"border-top-right-radius: 7px;\n"
"min-width: 80px;\n"
"border-radius: 8px;\n"
"color: black;\n"
"font-size:12px;\n"
"font-family:Arial, Helvetica, sans-serif;\n"
"\n"
"\n"
"}\n"
"QToolButton:hover {\n"
"color:#fff;\n"
"background:#8b9dc3;\n"
"border: none;\n"
"\n"
"}\n"
""));
        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(90, 50, 84, 28));
        pushButton_4->setStyleSheet(QLatin1String("QPushButton {\n"
"background: #dfe3ee;\n"
"border: 2px solid #dfe3ee;\n"
"border-bottom-color: #aaa5a5; /* same as the pane color */\n"
"border-top-left-radius: 7px;\n"
"border-top-right-radius: 7px;\n"
"min-width: 80px;\n"
"border-radius: 8px;\n"
"color: black;\n"
"font-size:12px;\n"
"font-family:Arial, Helvetica, sans-serif;\n"
"\n"
"\n"
"}\n"
"QPushButton:hover {\n"
"color:#fff;\n"
"background:#8b9dc3;\n"
"border: none;\n"
"\n"
"}\n"
""));
        Date_2 = new QLabel(groupBox);
        Date_2->setObjectName(QStringLiteral("Date_2"));
        Date_2->setGeometry(QRect(36, 140, 121, 31));
        QFont font1;
        font1.setPointSize(11);
        Date_2->setFont(font1);
        Date_2->setCursor(QCursor(Qt::ArrowCursor));
        Timer_2 = new QLabel(groupBox);
        Timer_2->setObjectName(QStringLiteral("Timer_2"));
        Timer_2->setGeometry(QRect(56, 120, 81, 31));
        Timer_2->setFont(font1);
        Timer_2->setCursor(QCursor(Qt::ArrowCursor));
        label_36 = new QLabel(groupBox);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setGeometry(QRect(30, 107, 141, 16));
        label_37 = new QLabel(groupBox);
        label_37->setObjectName(QStringLiteral("label_37"));
        label_37->setGeometry(QRect(30, 157, 141, 16));
        tabWidget = new QTabWidget(factures);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(180, 10, 821, 521));
        tabWidget->setStyleSheet(QLatin1String("#QWidget {\n"
"\n"
"}\n"
"QTabWidget::pane { /* The tab widget frame */\n"
"border-top: 5px  ;\n"
"}\n"
"QTabWidget::tab-bar {\n"
"left: 0px; /* move to the right by 5px */\n"
"}\n"
"/* Style the tab using the tab sub-control. Note that it reads QTabBar _not_ QTabWidget */\n"
"QTabBar::tab {\n"
"background: #FFFFFF;\n"
"border: 2px  ;\n"
"border-bottom-color: ; /* same as the pane color */\n"
"border-top-left-radius: 7px;\n"
"border-top-right-radius: 7px;\n"
"min-width: 145px;\n"
"padding: 4px;\n"
"color: black;\n"
"font-size:13px;\n"
"font-family:Arial, Helvetica, sans-serif;\n"
"}\n"
"QTabBar::tab:selected, QTabBar::tab:hover {\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #DCDCDC, stop: 0.4 #C0C0C0, stop: 0.5 #A9A9A9, stop: 1.0 #A9A9A9);\n"
"}\n"
"QTabBar::tab:selected {\n"
"border-color: #9B9B9B;\n"
"border-bottom-color: #FFD700; /* same as pane color */\n"
"color: #FFFFFF;\n"
"font-size:15px;\n"
"font-family:Arial, Helvetica, sans-serif;\n"
"}\n"
"QTabBar::tab:!selected {\n"
"margin-"
                        "top: 2px; /* make non-selected tabs look smaller */\n"
"\n"
"}"));
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        groupBox_3 = new QGroupBox(tab_4);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 30, 741, 421));
        tab_fact = new QTableView(groupBox_3);
        tab_fact->setObjectName(QStringLiteral("tab_fact"));
        tab_fact->setEnabled(true);
        tab_fact->setGeometry(QRect(90, 180, 641, 241));
        tab_fact->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        tab_fact->setMouseTracking(false);
        tab_fact->setStyleSheet(QLatin1String("QTableView\n"
"{\n"
" border-width: 1px;\n"
"border-style: solid;\n"
"border-color: black;\n"
"  border-radius: 10px;\n"
"padding:0 5;\n"
"}"));
        pushButton = new QPushButton(groupBox_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setEnabled(true);
        pushButton->setGeometry(QRect(0, 260, 84, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial"));
        font2.setBold(false);
        font2.setWeight(50);
        pushButton->setFont(font2);
        pushButton->setStyleSheet(QLatin1String("QPushButton {\n"
"background: #dfe3ee;\n"
"border: 2px solid #dfe3ee;\n"
"border-bottom-color: #aaa5a5; /* same as the pane color */\n"
"border-top-left-radius: 7px;\n"
"border-top-right-radius: 7px;\n"
"min-width: 80px;\n"
"border-radius: 8px;\n"
"color: black;\n"
"font-size:12px;\n"
"font-family:Arial, Helvetica, sans-serif;\n"
"\n"
"\n"
"}\n"
"QPushButton:hover {\n"
"color:#fff;\n"
"background:#8b9dc3;\n"
"border: none;\n"
"\n"
"}\n"
""));
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(340, 30, 109, 109));
        label_10->setPixmap(QPixmap(QString::fromUtf8("img/affich.png")));
        lineEdit = new QLineEdit(groupBox_3);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setEnabled(true);
        lineEdit->setGeometry(QRect(120, 150, 571, 22));
        lineEdit->setFocusPolicy(Qt::WheelFocus);
        lineEdit->setContextMenuPolicy(Qt::PreventContextMenu);
        lineEdit->setAutoFillBackground(false);
        lineEdit->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
" border-width: 1px;\n"
"border-style: solid;\n"
"border-color: black;\n"
"  border-radius: 10px;\n"
"padding:0 8;\n"
"}"));
        lineEdit->setAlignment(Qt::AlignCenter);
        lineEdit->setClearButtonEnabled(false);
        pdf = new QPushButton(groupBox_3);
        pdf->setObjectName(QStringLiteral("pdf"));
        pdf->setEnabled(true);
        pdf->setGeometry(QRect(0, 310, 84, 31));
        pdf->setFont(font2);
        pdf->setStyleSheet(QLatin1String("QPushButton {\n"
"background: #dfe3ee;\n"
"border: 2px solid #dfe3ee;\n"
"border-bottom-color: #aaa5a5; /* same as the pane color */\n"
"border-top-left-radius: 7px;\n"
"border-top-right-radius: 7px;\n"
"min-width: 80px;\n"
"border-radius: 8px;\n"
"color: black;\n"
"font-size:12px;\n"
"font-family:Arial, Helvetica, sans-serif;\n"
"\n"
"\n"
"}\n"
"QPushButton:hover {\n"
"color:#fff;\n"
"background:#8b9dc3;\n"
"border: none;\n"
"\n"
"}\n"
""));
        impr = new QPushButton(groupBox_3);
        impr->setObjectName(QStringLiteral("impr"));
        impr->setEnabled(true);
        impr->setGeometry(QRect(0, 360, 84, 31));
        impr->setFont(font2);
        impr->setStyleSheet(QLatin1String("QPushButton {\n"
"background: #dfe3ee;\n"
"border: 2px solid #dfe3ee;\n"
"border-bottom-color: #aaa5a5; /* same as the pane color */\n"
"border-top-left-radius: 7px;\n"
"border-top-right-radius: 7px;\n"
"min-width: 80px;\n"
"border-radius: 8px;\n"
"color: black;\n"
"font-size:12px;\n"
"font-family:Arial, Helvetica, sans-serif;\n"
"\n"
"\n"
"}\n"
"QPushButton:hover {\n"
"color:#fff;\n"
"background:#8b9dc3;\n"
"border: none;\n"
"\n"
"}\n"
""));
        pushButton_2 = new QPushButton(groupBox_3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(0, 210, 84, 31));
        pushButton_2->setContextMenuPolicy(Qt::DefaultContextMenu);
        pushButton_2->setLayoutDirection(Qt::LeftToRight);
        pushButton_2->setStyleSheet(QLatin1String("QPushButton {\n"
"background: #dfe3ee;\n"
"border: 2px solid #dfe3ee;\n"
"border-bottom-color: #aaa5a5; /* same as the pane color */\n"
"border-top-left-radius: 7px;\n"
"border-top-right-radius: 7px;\n"
"min-width: 80px;\n"
"border-radius: 8px;\n"
"color: black;\n"
"font-size:12px;\n"
"font-family:Arial, Helvetica, sans-serif;\n"
"\n"
"\n"
"}\n"
"QPushButton:hover {\n"
"color:#fff;\n"
"background:#8b9dc3;\n"
"border: none;\n"
"\n"
"}\n"
""));
        pushButton_5 = new QPushButton(groupBox_3);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(10, 140, 93, 28));
        tabWidget->addTab(tab_4, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 60, 751, 351));
        le_id_f = new QLineEdit(groupBox_2);
        le_id_f->setObjectName(QStringLiteral("le_id_f"));
        le_id_f->setEnabled(false);
        le_id_f->setGeometry(QRect(310, 158, 191, 21));
        le_id_f->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
" border-width: 1px;\n"
"border-style: solid;\n"
"border-color: black;\n"
"  border-radius: 10px;\n"
"padding:0 8;\n"
"}"));
        le_ttc_f = new QLineEdit(groupBox_2);
        le_ttc_f->setObjectName(QStringLiteral("le_ttc_f"));
        le_ttc_f->setGeometry(QRect(310, 280, 191, 22));
        le_ttc_f->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
" border-width: 1px;\n"
"border-style: solid;\n"
"border-color: black;\n"
"  border-radius: 10px;\n"
"padding:0 8;\n"
"}"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(220, 158, 71, 21));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(250, 248, 41, 31));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(220, 280, 81, 31));
        pb_ajouter = new QPushButton(groupBox_2);
        pb_ajouter->setObjectName(QStringLiteral("pb_ajouter"));
        pb_ajouter->setGeometry(QRect(410, 310, 100, 28));
        pb_ajouter->setStyleSheet(QLatin1String("QPushButton {\n"
"background: #dfe3ee;\n"
"border: 2px solid #dfe3ee;\n"
"border-bottom-color: #aaa5a5; /* same as the pane color */\n"
"border-top-left-radius: 7px;\n"
"border-top-right-radius: 7px;\n"
"min-width: 80px;\n"
"border-radius: 8px;\n"
"color: black;\n"
"font-size:12px;\n"
"font-family:Arial, Helvetica, sans-serif;\n"
"\n"
"\n"
"}\n"
"QPushButton:hover {\n"
"color:#fff;\n"
"background:#8b9dc3;\n"
"border: none;\n"
"\n"
"}\n"
""));
        date_box = new QDateTimeEdit(groupBox_2);
        date_box->setObjectName(QStringLiteral("date_box"));
        date_box->setGeometry(QRect(310, 248, 194, 22));
        date_box->setStyleSheet(QLatin1String("QDateTimeEdit\n"
"{\n"
" border-width: 1px;\n"
"border-style: solid;\n"
"border-color: black;\n"
"  border-radius: 10px;\n"
"padding:0 8;\n"
"}"));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(460, 270, 31, 41));
        QFont font3;
        font3.setPointSize(8);
        font3.setBold(true);
        font3.setWeight(75);
        label_11->setFont(font3);
        le_client = new QComboBox(groupBox_2);
        le_client->setObjectName(QStringLiteral("le_client"));
        le_client->setGeometry(QRect(310, 188, 191, 22));
        le_client->setStyleSheet(QLatin1String("QComboBox\n"
"{\n"
" border-width: 1px;\n"
"border-style: solid;\n"
"border-color: black;\n"
"  border-radius: 10px;\n"
"padding:0 8;\n"
"}"));
        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(245, 188, 81, 21));
        label_16 = new QLabel(groupBox_2);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(180, 218, 121, 21));
        le_mode_f = new QComboBox(groupBox_2);
        le_mode_f->setObjectName(QStringLiteral("le_mode_f"));
        le_mode_f->setGeometry(QRect(310, 218, 191, 21));
        le_mode_f->setStyleSheet(QLatin1String("QComboBox\n"
"{\n"
" border-width: 1px;\n"
"border-style: solid;\n"
"border-color: black;\n"
"  border-radius: 10px;\n"
"padding:0 8;\n"
"}"));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(360, 80, 111, 111));
        label_4->setPixmap(QPixmap(QString::fromUtf8("img/ajou.png")));
        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        groupBox_5 = new QGroupBox(tab_3);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(20, 60, 751, 351));
        modif_ttc_f = new QLineEdit(groupBox_5);
        modif_ttc_f->setObjectName(QStringLiteral("modif_ttc_f"));
        modif_ttc_f->setGeometry(QRect(320, 280, 191, 22));
        modif_ttc_f->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
" border-width: 1px;\n"
"border-style: solid;\n"
"border-color: black;\n"
"  border-radius: 10px;\n"
"padding:0 8;\n"
"}"));
        label_6 = new QLabel(groupBox_5);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(230, 153, 71, 31));
        label_7 = new QLabel(groupBox_5);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(260, 248, 41, 31));
        label_8 = new QLabel(groupBox_5);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(230, 280, 81, 31));
        pb_modifier = new QPushButton(groupBox_5);
        pb_modifier->setObjectName(QStringLiteral("pb_modifier"));
        pb_modifier->setGeometry(QRect(420, 310, 100, 28));
        pb_modifier->setStyleSheet(QLatin1String("QPushButton {\n"
"background: #dfe3ee;\n"
"border: 2px solid #dfe3ee;\n"
"border-bottom-color: #aaa5a5; /* same as the pane color */\n"
"border-top-left-radius: 7px;\n"
"border-top-right-radius: 7px;\n"
"min-width: 80px;\n"
"border-radius: 8px;\n"
"color: black;\n"
"font-size:12px;\n"
"font-family:Arial, Helvetica, sans-serif;\n"
"\n"
"\n"
"}\n"
"QPushButton:hover {\n"
"color:#fff;\n"
"background:#8b9dc3;\n"
"border: none;\n"
"\n"
"}\n"
""));
        label_9 = new QLabel(groupBox_5);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(350, 20, 111, 121));
        label_9->setPixmap(QPixmap(QString::fromUtf8("img/modif..png")));
        label_9->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_9->setWordWrap(false);
        label_9->setMargin(0);
        label_9->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
        modif_box = new QComboBox(groupBox_5);
        modif_box->setObjectName(QStringLiteral("modif_box"));
        modif_box->setGeometry(QRect(320, 157, 191, 22));
        modif_box->setStyleSheet(QLatin1String("QComboBox\n"
"{\n"
" border-width: 1px;\n"
"border-style: solid;\n"
"border-color: black;\n"
"  border-radius: 10px;\n"
"padding:0 8;\n"
"}"));
        modif_date_f_box = new QDateTimeEdit(groupBox_5);
        modif_date_f_box->setObjectName(QStringLiteral("modif_date_f_box"));
        modif_date_f_box->setGeometry(QRect(320, 248, 194, 22));
        modif_date_f_box->setStyleSheet(QLatin1String("QDateTimeEdit\n"
"{\n"
" border-width: 1px;\n"
"border-style: solid;\n"
"border-color: black;\n"
"  border-radius: 10px;\n"
"padding:0 8;\n"
"}"));
        label_13 = new QLabel(groupBox_5);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(470, 270, 31, 41));
        label_13->setFont(font3);
        label_15 = new QLabel(groupBox_5);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(255, 189, 81, 21));
        modif_le_client = new QComboBox(groupBox_5);
        modif_le_client->setObjectName(QStringLiteral("modif_le_client"));
        modif_le_client->setGeometry(QRect(320, 188, 191, 22));
        modif_le_client->setStyleSheet(QLatin1String("QComboBox\n"
"{\n"
" border-width: 1px;\n"
"border-style: solid;\n"
"border-color: black;\n"
"  border-radius: 10px;\n"
"padding:0 8;\n"
"}"));
        label_17 = new QLabel(groupBox_5);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(190, 218, 121, 21));
        modif_le_mode_f = new QComboBox(groupBox_5);
        modif_le_mode_f->setObjectName(QStringLiteral("modif_le_mode_f"));
        modif_le_mode_f->setGeometry(QRect(320, 218, 191, 21));
        modif_le_mode_f->setStyleSheet(QLatin1String("QComboBox\n"
"{\n"
" border-width: 1px;\n"
"border-style: solid;\n"
"border-color: black;\n"
"  border-radius: 10px;\n"
"padding:0 8;\n"
"}"));
        Lb_client = new QLabel(tab_3);
        Lb_client->setObjectName(QStringLiteral("Lb_client"));
        Lb_client->setGeometry(QRect(550, 250, 181, 20));
        QFont font4;
        font4.setFamily(QStringLiteral("Arial"));
        font4.setBold(true);
        font4.setWeight(75);
        Lb_client->setFont(font4);
        Lb_client->setContextMenuPolicy(Qt::PreventContextMenu);
        Lb_client->setStyleSheet(QLatin1String("QLabel {\n"
"\n"
"color: green;\n"
"font-size:12px;\n"
"font-family:Arial, Helvetica, sans-serif;\n"
"\n"
"\n"
"}"));
        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(350, 140, 101, 81));
        label_5->setPixmap(QPixmap(QString::fromUtf8("img/supprime.png")));
        groupBox_4 = new QGroupBox(tab_2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(40, 100, 731, 261));
        supp = new QPushButton(groupBox_4);
        supp->setObjectName(QStringLiteral("supp"));
        supp->setGeometry(QRect(380, 190, 101, 31));
        supp->setStyleSheet(QLatin1String("QPushButton {\n"
"background: #dfe3ee;\n"
"border: 2px solid #dfe3ee;\n"
"border-bottom-color: #aaa5a5; /* same as the pane color */\n"
"border-top-left-radius: 7px;\n"
"border-top-right-radius: 7px;\n"
"min-width: 80px;\n"
"border-radius: 8px;\n"
"color: black;\n"
"font-size:12px;\n"
"font-family:Arial, Helvetica, sans-serif;\n"
"\n"
"\n"
"}\n"
"QPushButton:hover {\n"
"color:#fff;\n"
"background:#8b9dc3;\n"
"border: none;\n"
"\n"
"}\n"
""));
        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(250, 150, 71, 31));
        supr_box = new QComboBox(groupBox_4);
        supr_box->setObjectName(QStringLiteral("supr_box"));
        supr_box->setGeometry(QRect(330, 150, 141, 22));
        supr_box->setStyleSheet(QLatin1String("QComboBox\n"
"{\n"
" border-width: 1px;\n"
"border-style: solid;\n"
"border-color: black;\n"
"  border-radius: 10px;\n"
"padding:0 8;\n"
"}"));
        infos = new QLabel(tab_2);
        infos->setObjectName(QStringLiteral("infos"));
        infos->setGeometry(QRect(90, 370, 631, 20));
        QFont font5;
        font5.setFamily(QStringLiteral("Myanmar Text"));
        font5.setBold(true);
        font5.setWeight(75);
        infos->setFont(font5);
        tabWidget->addTab(tab_2, QString());
        groupBox_4->raise();
        label_5->raise();
        infos->raise();
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        widget = new QCustomPlot(tab_5);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 10, 761, 461));
        tabWidget->addTab(tab_5, QString());
        stackedWidget->addWidget(factures);
        evenements = new QWidget();
        evenements->setObjectName(QStringLiteral("evenements"));
        stackedWidget_2 = new QStackedWidget(evenements);
        stackedWidget_2->setObjectName(QStringLiteral("stackedWidget_2"));
        stackedWidget_2->setGeometry(QRect(-10, -10, 941, 551));
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        groupBox_6 = new QGroupBox(page_4);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(10, 10, 181, 531));
        toolButton_4 = new QToolButton(groupBox_6);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        toolButton_4->setGeometry(QRect(20, 240, 131, 31));
        toolButton_4->setStyleSheet(QLatin1String("QToolButton {\n"
"background: #dfe3ee;\n"
"border: 2px solid #dfe3ee;\n"
"border-bottom-color: #aaa5a5; /* same as the pane color */\n"
"border-top-left-radius: 7px;\n"
"border-top-right-radius: 7px;\n"
"min-width: 80px;\n"
"border-radius: 8px;\n"
"color: black;\n"
"font-size:12px;\n"
"font-family:Arial, Helvetica, sans-serif;\n"
"\n"
"\n"
"}\n"
"QToolButton:hover {\n"
"color:#fff;\n"
"background:#8b9dc3;\n"
"border: none;\n"
"\n"
"}\n"
""));
        toolButton_5 = new QToolButton(groupBox_6);
        toolButton_5->setObjectName(QStringLiteral("toolButton_5"));
        toolButton_5->setGeometry(QRect(20, 340, 131, 31));
        toolButton_5->setStyleSheet(QLatin1String("QToolButton {\n"
"background: #dfe3ee;\n"
"border: 2px solid #dfe3ee;\n"
"border-bottom-color: #aaa5a5; /* same as the pane color */\n"
"border-top-left-radius: 7px;\n"
"border-top-right-radius: 7px;\n"
"min-width: 80px;\n"
"border-radius: 8px;\n"
"color: black;\n"
"font-size:12px;\n"
"font-family:Arial, Helvetica, sans-serif;\n"
"\n"
"\n"
"}\n"
"QToolButton:hover {\n"
"color:#fff;\n"
"background:#8b9dc3;\n"
"border: none;\n"
"\n"
"}\n"
""));
        toolButton_6 = new QToolButton(groupBox_6);
        toolButton_6->setObjectName(QStringLiteral("toolButton_6"));
        toolButton_6->setGeometry(QRect(20, 290, 131, 31));
        toolButton_6->setStyleSheet(QLatin1String("QToolButton {\n"
"background: #dfe3ee;\n"
"border: 2px solid #dfe3ee;\n"
"border-bottom-color: #aaa5a5; /* same as the pane color */\n"
"border-top-left-radius: 7px;\n"
"border-top-right-radius: 7px;\n"
"min-width: 80px;\n"
"border-radius: 8px;\n"
"color: black;\n"
"font-size:12px;\n"
"font-family:Arial, Helvetica, sans-serif;\n"
"\n"
"\n"
"}\n"
"QToolButton:hover {\n"
"color:#fff;\n"
"background:#8b9dc3;\n"
"border: none;\n"
"\n"
"}\n"
""));
        pushButton_3 = new QPushButton(groupBox_6);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(90, 50, 84, 28));
        pushButton_3->setStyleSheet(QLatin1String("QPushButton {\n"
"background: #dfe3ee;\n"
"border: 2px solid #dfe3ee;\n"
"border-bottom-color: #aaa5a5; /* same as the pane color */\n"
"border-top-left-radius: 7px;\n"
"border-top-right-radius: 7px;\n"
"min-width: 80px;\n"
"border-radius: 8px;\n"
"color: black;\n"
"font-size:12px;\n"
"font-family:Arial, Helvetica, sans-serif;\n"
"\n"
"\n"
"}\n"
"QPushButton:hover {\n"
"color:#fff;\n"
"background:#8b9dc3;\n"
"border: none;\n"
"\n"
"}\n"
""));
        Timer = new QLabel(groupBox_6);
        Timer->setObjectName(QStringLiteral("Timer"));
        Timer->setGeometry(QRect(56, 120, 81, 31));
        Timer->setFont(font1);
        Timer->setCursor(QCursor(Qt::ArrowCursor));
        Date = new QLabel(groupBox_6);
        Date->setObjectName(QStringLiteral("Date"));
        Date->setGeometry(QRect(36, 140, 121, 31));
        Date->setFont(font1);
        Date->setCursor(QCursor(Qt::ArrowCursor));
        label_39 = new QLabel(groupBox_6);
        label_39->setObjectName(QStringLiteral("label_39"));
        label_39->setGeometry(QRect(30, 157, 141, 16));
        label_38 = new QLabel(groupBox_6);
        label_38->setObjectName(QStringLiteral("label_38"));
        label_38->setGeometry(QRect(30, 107, 141, 16));
        tabWidget_2 = new QTabWidget(page_4);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(190, 20, 811, 461));
        tabWidget_2->setStyleSheet(QLatin1String("#QWidget {\n"
"\n"
"}\n"
"QTabWidget::pane { /* The tab widget frame */\n"
"border-top: 5px  ;\n"
"}\n"
"QTabWidget::tab-bar {\n"
"left: 0px; /* move to the right by 5px */\n"
"}\n"
"/* Style the tab using the tab sub-control. Note that it reads QTabBar _not_ QTabWidget */\n"
"QTabBar::tab {\n"
"background: #FFFFFF;\n"
"border: 2px  ;\n"
"border-bottom-color: ; /* same as the pane color */\n"
"border-top-left-radius: 7px;\n"
"border-top-right-radius: 7px;\n"
"min-width: 145px;\n"
"padding: 4px;\n"
"color: black;\n"
"font-size:13px;\n"
"font-family:Arial, Helvetica, sans-serif;\n"
"}\n"
"QTabBar::tab:selected, QTabBar::tab:hover {\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #DCDCDC, stop: 0.4 #C0C0C0, stop: 0.5 #A9A9A9, stop: 1.0 #A9A9A9);\n"
"}\n"
"QTabBar::tab:selected {\n"
"border-color: #9B9B9B;\n"
"border-bottom-color: #FFD700; /* same as pane color */\n"
"color: #FFFFFF;\n"
"font-size:15px;\n"
"font-family:Arial, Helvetica, sans-serif;\n"
"}\n"
"QTabBar::tab:!selected {\n"
"margin-"
                        "top: 2px; /* make non-selected tabs look smaller */\n"
"\n"
"}"));
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        groupBox_7 = new QGroupBox(tab_7);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(20, 30, 791, 421));
        tab_ev = new QTableView(groupBox_7);
        tab_ev->setObjectName(QStringLiteral("tab_ev"));
        tab_ev->setEnabled(true);
        tab_ev->setGeometry(QRect(90, 180, 471, 221));
        tab_ev->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        tab_ev->setMouseTracking(false);
        tab_ev->setStyleSheet(QLatin1String("QTableView\n"
"{\n"
" border-width: 1px;\n"
"border-style: solid;\n"
"border-color: black;\n"
"  border-radius: 10px;\n"
"padding:0 5;\n"
"}"));
        tri_ev = new QPushButton(groupBox_7);
        tri_ev->setObjectName(QStringLiteral("tri_ev"));
        tri_ev->setEnabled(true);
        tri_ev->setGeometry(QRect(0, 260, 84, 31));
        tri_ev->setFont(font2);
        tri_ev->setStyleSheet(QLatin1String("QPushButton {\n"
"background: #dfe3ee;\n"
"border: 2px solid #dfe3ee;\n"
"border-bottom-color: #aaa5a5; /* same as the pane color */\n"
"border-top-left-radius: 7px;\n"
"border-top-right-radius: 7px;\n"
"min-width: 80px;\n"
"border-radius: 8px;\n"
"color: black;\n"
"font-size:12px;\n"
"font-family:Arial, Helvetica, sans-serif;\n"
"\n"
"\n"
"}\n"
"QPushButton:hover {\n"
"color:#fff;\n"
"background:#8b9dc3;\n"
"border: none;\n"
"\n"
"}\n"
""));
        label_18 = new QLabel(groupBox_7);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(230, 30, 109, 109));
        label_18->setPixmap(QPixmap(QString::fromUtf8("../../../affich.png")));
        label_18->setScaledContents(false);
        recherche_ev = new QLineEdit(groupBox_7);
        recherche_ev->setObjectName(QStringLiteral("recherche_ev"));
        recherche_ev->setEnabled(true);
        recherche_ev->setGeometry(QRect(120, 150, 391, 22));
        recherche_ev->setFocusPolicy(Qt::WheelFocus);
        recherche_ev->setContextMenuPolicy(Qt::PreventContextMenu);
        recherche_ev->setAutoFillBackground(false);
        recherche_ev->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
" border-width: 1px;\n"
"border-style: solid;\n"
"border-color: black;\n"
"  border-radius: 10px;\n"
"padding:0 8;\n"
"}"));
        recherche_ev->setAlignment(Qt::AlignCenter);
        recherche_ev->setClearButtonEnabled(false);
        pdf_ev = new QPushButton(groupBox_7);
        pdf_ev->setObjectName(QStringLiteral("pdf_ev"));
        pdf_ev->setEnabled(true);
        pdf_ev->setGeometry(QRect(0, 310, 84, 31));
        pdf_ev->setFont(font2);
        pdf_ev->setStyleSheet(QLatin1String("QPushButton {\n"
"background: #dfe3ee;\n"
"border: 2px solid #dfe3ee;\n"
"border-bottom-color: #aaa5a5; /* same as the pane color */\n"
"border-top-left-radius: 7px;\n"
"border-top-right-radius: 7px;\n"
"min-width: 80px;\n"
"border-radius: 8px;\n"
"color: black;\n"
"font-size:12px;\n"
"font-family:Arial, Helvetica, sans-serif;\n"
"\n"
"\n"
"}\n"
"QPushButton:hover {\n"
"color:#fff;\n"
"background:#8b9dc3;\n"
"border: none;\n"
"\n"
"}\n"
""));
        impr_ev = new QPushButton(groupBox_7);
        impr_ev->setObjectName(QStringLiteral("impr_ev"));
        impr_ev->setEnabled(true);
        impr_ev->setGeometry(QRect(0, 360, 84, 31));
        impr_ev->setFont(font2);
        impr_ev->setStyleSheet(QLatin1String("QPushButton {\n"
"background: #dfe3ee;\n"
"border: 2px solid #dfe3ee;\n"
"border-bottom-color: #aaa5a5; /* same as the pane color */\n"
"border-top-left-radius: 7px;\n"
"border-top-right-radius: 7px;\n"
"min-width: 80px;\n"
"border-radius: 8px;\n"
"color: black;\n"
"font-size:12px;\n"
"font-family:Arial, Helvetica, sans-serif;\n"
"\n"
"\n"
"}\n"
"QPushButton:hover {\n"
"color:#fff;\n"
"background:#8b9dc3;\n"
"border: none;\n"
"\n"
"}\n"
""));
        supp_ev_2 = new QPushButton(groupBox_7);
        supp_ev_2->setObjectName(QStringLiteral("supp_ev_2"));
        supp_ev_2->setGeometry(QRect(0, 210, 84, 31));
        supp_ev_2->setContextMenuPolicy(Qt::DefaultContextMenu);
        supp_ev_2->setLayoutDirection(Qt::LeftToRight);
        supp_ev_2->setStyleSheet(QLatin1String("QPushButton {\n"
"background: #dfe3ee;\n"
"border: 2px solid #dfe3ee;\n"
"border-bottom-color: #aaa5a5; /* same as the pane color */\n"
"border-top-left-radius: 7px;\n"
"border-top-right-radius: 7px;\n"
"min-width: 80px;\n"
"border-radius: 8px;\n"
"color: black;\n"
"font-size:12px;\n"
"font-family:Arial, Helvetica, sans-serif;\n"
"\n"
"\n"
"}\n"
"QPushButton:hover {\n"
"color:#fff;\n"
"background:#8b9dc3;\n"
"border: none;\n"
"\n"
"}\n"
""));
        tabWidget_2->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QStringLiteral("tab_8"));
        groupBox_8 = new QGroupBox(tab_8);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setGeometry(QRect(20, 60, 551, 351));
        id_ev = new QLineEdit(groupBox_8);
        id_ev->setObjectName(QStringLiteral("id_ev"));
        id_ev->setEnabled(false);
        id_ev->setGeometry(QRect(210, 158, 191, 21));
        id_ev->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
" border-width: 1px;\n"
"border-style: solid;\n"
"border-color: black;\n"
"  border-radius: 10px;\n"
"padding:0 8;\n"
"}"));
        label_19 = new QLabel(groupBox_8);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(120, 158, 71, 21));
        label_20 = new QLabel(groupBox_8);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(110, 248, 81, 31));
        label_21 = new QLabel(groupBox_8);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(90, 280, 111, 31));
        ajout_ev = new QPushButton(groupBox_8);
        ajout_ev->setObjectName(QStringLiteral("ajout_ev"));
        ajout_ev->setGeometry(QRect(310, 310, 100, 28));
        ajout_ev->setStyleSheet(QLatin1String("QPushButton {\n"
"background: #dfe3ee;\n"
"border: 2px solid #dfe3ee;\n"
"border-bottom-color: #aaa5a5; /* same as the pane color */\n"
"border-top-left-radius: 7px;\n"
"border-top-right-radius: 7px;\n"
"min-width: 80px;\n"
"border-radius: 8px;\n"
"color: black;\n"
"font-size:12px;\n"
"font-family:Arial, Helvetica, sans-serif;\n"
"\n"
"\n"
"}\n"
"QPushButton:hover {\n"
"color:#fff;\n"
"background:#8b9dc3;\n"
"border: none;\n"
"\n"
"}\n"
""));
        dat_fin = new QDateTimeEdit(groupBox_8);
        dat_fin->setObjectName(QStringLiteral("dat_fin"));
        dat_fin->setGeometry(QRect(210, 250, 194, 22));
        dat_fin->setStyleSheet(QLatin1String("QDateTimeEdit\n"
"{\n"
" border-width: 1px;\n"
"border-style: solid;\n"
"border-color: black;\n"
"  border-radius: 10px;\n"
"padding:0 8;\n"
"}"));
        label_23 = new QLabel(groupBox_8);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(145, 188, 81, 21));
        label_24 = new QLabel(groupBox_8);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(90, 218, 131, 21));
        nom_ev = new QLineEdit(groupBox_8);
        nom_ev->setObjectName(QStringLiteral("nom_ev"));
        nom_ev->setEnabled(true);
        nom_ev->setGeometry(QRect(210, 190, 191, 21));
        nom_ev->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
" border-width: 1px;\n"
"border-style: solid;\n"
"border-color: black;\n"
"  border-radius: 10px;\n"
"padding:0 8;\n"
"}"));
        dat_deb = new QDateTimeEdit(groupBox_8);
        dat_deb->setObjectName(QStringLiteral("dat_deb"));
        dat_deb->setGeometry(QRect(210, 220, 194, 22));
        dat_deb->setStyleSheet(QLatin1String("QDateTimeEdit\n"
"{\n"
" border-width: 1px;\n"
"border-style: solid;\n"
"border-color: black;\n"
"  border-radius: 10px;\n"
"padding:0 8;\n"
"}"));
        produit_inclus = new QComboBox(groupBox_8);
        produit_inclus->setObjectName(QStringLiteral("produit_inclus"));
        produit_inclus->setGeometry(QRect(211, 281, 191, 22));
        produit_inclus->setStyleSheet(QLatin1String("QComboBox\n"
"{\n"
" border-width: 1px;\n"
"border-style: solid;\n"
"border-color: black;\n"
"  border-radius: 10px;\n"
"padding:0 8;\n"
"}"));
        checkBox = new QCheckBox(groupBox_8);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(418, 314, 141, 20));
        QFont font6;
        font6.setPointSize(7);
        checkBox->setFont(font6);
        label_25 = new QLabel(tab_8);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(260, 80, 111, 111));
        label_25->setPixmap(QPixmap(QString::fromUtf8("../../../ajou.png")));
        tabWidget_2->addTab(tab_8, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName(QStringLiteral("tab_9"));
        groupBox_9 = new QGroupBox(tab_9);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        groupBox_9->setGeometry(QRect(20, 60, 551, 351));
        label_29 = new QLabel(groupBox_9);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(240, 20, 111, 121));
        label_29->setPixmap(QPixmap(QString::fromUtf8("../../../modif..png")));
        label_29->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_29->setWordWrap(false);
        label_29->setMargin(0);
        label_29->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
        modif_dat_fin = new QDateTimeEdit(groupBox_9);
        modif_dat_fin->setObjectName(QStringLiteral("modif_dat_fin"));
        modif_dat_fin->setGeometry(QRect(210, 250, 194, 22));
        modif_dat_fin->setStyleSheet(QLatin1String("QDateTimeEdit\n"
"{\n"
" border-width: 1px;\n"
"border-style: solid;\n"
"border-color: black;\n"
"  border-radius: 10px;\n"
"padding:0 8;\n"
"}"));
        label_27 = new QLabel(groupBox_9);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(110, 248, 81, 31));
        modif_titre_ev = new QLineEdit(groupBox_9);
        modif_titre_ev->setObjectName(QStringLiteral("modif_titre_ev"));
        modif_titre_ev->setEnabled(true);
        modif_titre_ev->setGeometry(QRect(210, 190, 191, 21));
        modif_titre_ev->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
" border-width: 1px;\n"
"border-style: solid;\n"
"border-color: black;\n"
"  border-radius: 10px;\n"
"padding:0 8;\n"
"}"));
        modif_dat_deb = new QDateTimeEdit(groupBox_9);
        modif_dat_deb->setObjectName(QStringLiteral("modif_dat_deb"));
        modif_dat_deb->setGeometry(QRect(210, 220, 194, 22));
        modif_dat_deb->setStyleSheet(QLatin1String("QDateTimeEdit\n"
"{\n"
" border-width: 1px;\n"
"border-style: solid;\n"
"border-color: black;\n"
"  border-radius: 10px;\n"
"padding:0 8;\n"
"}"));
        modif_ev = new QPushButton(groupBox_9);
        modif_ev->setObjectName(QStringLiteral("modif_ev"));
        modif_ev->setGeometry(QRect(310, 310, 100, 28));
        modif_ev->setStyleSheet(QLatin1String("QPushButton {\n"
"background: #dfe3ee;\n"
"border: 2px solid #dfe3ee;\n"
"border-bottom-color: #aaa5a5; /* same as the pane color */\n"
"border-top-left-radius: 7px;\n"
"border-top-right-radius: 7px;\n"
"min-width: 80px;\n"
"border-radius: 8px;\n"
"color: black;\n"
"font-size:12px;\n"
"font-family:Arial, Helvetica, sans-serif;\n"
"\n"
"\n"
"}\n"
"QPushButton:hover {\n"
"color:#fff;\n"
"background:#8b9dc3;\n"
"border: none;\n"
"\n"
"}\n"
""));
        modif_produit_inclus = new QComboBox(groupBox_9);
        modif_produit_inclus->setObjectName(QStringLiteral("modif_produit_inclus"));
        modif_produit_inclus->setGeometry(QRect(211, 281, 191, 22));
        modif_produit_inclus->setStyleSheet(QLatin1String("QComboBox\n"
"{\n"
" border-width: 1px;\n"
"border-style: solid;\n"
"border-color: black;\n"
"  border-radius: 10px;\n"
"padding:0 8;\n"
"}"));
        label_30 = new QLabel(groupBox_9);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(90, 218, 131, 21));
        label_26 = new QLabel(groupBox_9);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(145, 188, 81, 21));
        label_22 = new QLabel(groupBox_9);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(120, 158, 71, 21));
        label_28 = new QLabel(groupBox_9);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(90, 280, 111, 31));
        modif_id_ev = new QComboBox(groupBox_9);
        modif_id_ev->setObjectName(QStringLiteral("modif_id_ev"));
        modif_id_ev->setGeometry(QRect(210, 157, 191, 22));
        modif_id_ev->setStyleSheet(QLatin1String("QComboBox\n"
"{\n"
" border-width: 1px;\n"
"border-style: solid;\n"
"border-color: black;\n"
"  border-radius: 10px;\n"
"padding:0 8;\n"
"}"));
        Lb_client_2 = new QLabel(tab_9);
        Lb_client_2->setObjectName(QStringLiteral("Lb_client_2"));
        Lb_client_2->setGeometry(QRect(430, 250, 181, 20));
        Lb_client_2->setFont(font4);
        Lb_client_2->setContextMenuPolicy(Qt::PreventContextMenu);
        Lb_client_2->setStyleSheet(QLatin1String("QLabel {\n"
"\n"
"color: green;\n"
"font-size:12px;\n"
"font-family:Arial, Helvetica, sans-serif;\n"
"\n"
"\n"
"}"));
        tabWidget_2->addTab(tab_9, QString());
        tab_10 = new QWidget();
        tab_10->setObjectName(QStringLiteral("tab_10"));
        label_33 = new QLabel(tab_10);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setGeometry(QRect(240, 140, 101, 81));
        label_33->setPixmap(QPixmap(QString::fromUtf8("../../../supprime.png")));
        groupBox_10 = new QGroupBox(tab_10);
        groupBox_10->setObjectName(QStringLiteral("groupBox_10"));
        groupBox_10->setGeometry(QRect(40, 100, 491, 261));
        supp_ev = new QPushButton(groupBox_10);
        supp_ev->setObjectName(QStringLiteral("supp_ev"));
        supp_ev->setGeometry(QRect(270, 190, 101, 31));
        supp_ev->setStyleSheet(QLatin1String("QPushButton {\n"
"background: #dfe3ee;\n"
"border: 2px solid #dfe3ee;\n"
"border-bottom-color: #aaa5a5; /* same as the pane color */\n"
"border-top-left-radius: 7px;\n"
"border-top-right-radius: 7px;\n"
"min-width: 80px;\n"
"border-radius: 8px;\n"
"color: black;\n"
"font-size:12px;\n"
"font-family:Arial, Helvetica, sans-serif;\n"
"\n"
"\n"
"}\n"
"QPushButton:hover {\n"
"color:#fff;\n"
"background:#8b9dc3;\n"
"border: none;\n"
"\n"
"}\n"
""));
        label_34 = new QLabel(groupBox_10);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setGeometry(QRect(140, 150, 71, 31));
        supr_ev = new QComboBox(groupBox_10);
        supr_ev->setObjectName(QStringLiteral("supr_ev"));
        supr_ev->setGeometry(QRect(220, 150, 141, 22));
        supr_ev->setStyleSheet(QLatin1String("QComboBox\n"
"{\n"
" border-width: 1px;\n"
"border-style: solid;\n"
"border-color: black;\n"
"  border-radius: 10px;\n"
"padding:0 8;\n"
"}"));
        infos_2 = new QLabel(tab_10);
        infos_2->setObjectName(QStringLiteral("infos_2"));
        infos_2->setGeometry(QRect(60, 370, 631, 20));
        infos_2->setFont(font5);
        tabWidget_2->addTab(tab_10, QString());
        progressBar = new QProgressBar(page_4);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(200, 500, 701, 23));
        progressBar->setStyleSheet(QLatin1String("QProgressBar\n"
"{\n"
" border-width: 1px;\n"
"border-style: solid;\n"
"border-color: black;\n"
"  border-radius: 10px;\n"
"padding:0 8;\n"
"}"));
        progressBar->setValue(24);
        stackedWidget_2->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        stackedWidget_2->addWidget(page_5);
        qrcode = new QPushButton(evenements);
        qrcode->setObjectName(QStringLiteral("qrcode"));
        qrcode->setGeometry(QRect(825, 350, 93, 28));
        qrcode->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"    color: #b1b1b1;\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #565656, stop: 0.1 #525252, stop: 0.5 #4e4e4e, stop: 0.9 #4a4a4a, stop: 1 #464646);\n"
"    border-width: 1px;\n"
"    border-color: #1e1e1e;\n"
"    border-style: solid;\n"
"    border-radius: 6;\n"
"    padding: 3px;\n"
"    font-size: 12px;\n"
"    padding-left: 5px;\n"
"    padding-right: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #2d2d2d, stop: 0.1 #2b2b2b, stop: 0.5 #292929, stop: 0.9 #282828, stop: 1 #252525);\n"
"}\n"
"QComboBox:hover,QPushButton:hover\n"
"{\n"
"    border: 2px solid QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"}\n"
""));
        qrlabel = new QLabel(evenements);
        qrlabel->setObjectName(QStringLiteral("qrlabel"));
        qrlabel->setGeometry(QRect(765, 135, 211, 211));
        qrlabel->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
" border-width: 1px;\n"
"border-style: solid;\n"
"border-color: black;\n"
"  border-radius: 10px;\n"
"padding:0 5;\n"
"}"));
        stackedWidget->addWidget(evenements);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1026, 26));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(MainWindow);
        toolBar_2->setObjectName(QStringLiteral("toolBar_2"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_2);
        toolBar_3 = new QToolBar(MainWindow);
        toolBar_3->setObjectName(QStringLiteral("toolBar_3"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_3);

        menuBar->addAction(menuAbout->menuAction());
        menuAbout->addAction(actionAbout_us);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);
        tabWidget->setCurrentIndex(0);
        stackedWidget_2->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestion des Factures", Q_NULLPTR));
        actionAbout_us->setText(QApplication::translate("MainWindow", "About us", Q_NULLPTR));
        bt_login->setText(QApplication::translate("MainWindow", "Login", Q_NULLPTR));
        user->setPlaceholderText(QApplication::translate("MainWindow", "USERNAME", Q_NULLPTR));
        pass->setPlaceholderText(QApplication::translate("MainWindow", "PASSWORD", Q_NULLPTR));
        commandLinkButton->setText(QString());
        commandLinkButton_2->setText(QString());
        commandLinkButton_2->setDescription(QString());
        label_31->setText(QString());
        label_32->setText(QApplication::translate("MainWindow", "Factures", Q_NULLPTR));
        label_35->setText(QApplication::translate("MainWindow", "Evenements", Q_NULLPTR));
        label_40->setText(QApplication::translate("MainWindow", "<html><head/><body><p>*Tappez &quot;<span style=\" color:#ff0000;\">F</span>&quot; Pour allez au factures</p></body></html>", Q_NULLPTR));
        label_41->setText(QApplication::translate("MainWindow", "<html><head/><body><p>*Tappez &quot;<span style=\" color:#ff0000;\">E</span>&quot; Pour allez au evenements</p></body></html>", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Hash-tech", Q_NULLPTR));
        toolButton->setText(QApplication::translate("MainWindow", "Home", Q_NULLPTR));
        toolButton_2->setText(QApplication::translate("MainWindow", "Log out", Q_NULLPTR));
        toolButton_3->setText(QApplication::translate("MainWindow", "Settings", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "<----", Q_NULLPTR));
        Date_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Date</p></body></html>", Q_NULLPTR));
        Timer_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Time</p></body></html>", Q_NULLPTR));
        label_36->setText(QApplication::translate("MainWindow", "__________________", Q_NULLPTR));
        label_37->setText(QApplication::translate("MainWindow", "__________________", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        tabWidget->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Afficher", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Trier", Q_NULLPTR));
        label_10->setText(QString());
        lineEdit->setText(QString());
        lineEdit->setPlaceholderText(QApplication::translate("MainWindow", "Rechercher ...", Q_NULLPTR));
        pdf->setText(QApplication::translate("MainWindow", "PDF", Q_NULLPTR));
        impr->setText(QApplication::translate("MainWindow", "Imprimer", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pushButton_2->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_2->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_2->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        pushButton_2->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_ACCESSIBILITY
        pushButton_2->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        pushButton_2->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Afficher les factures", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        le_id_f->setText(QString());
        label->setText(QApplication::translate("MainWindow", "R\303\251f\303\251rence :", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Date :", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Total TTC :", Q_NULLPTR));
        pb_ajouter->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "DT", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "Client :", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "Mode de paiement :", Q_NULLPTR));
        le_mode_f->clear();
        le_mode_f->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Especes", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Cheque", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Carte bancaire", Q_NULLPTR)
        );
        label_4->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Ajouter une facture", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "R\303\251f\303\251rence :", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Date :", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Total TTC :", Q_NULLPTR));
        pb_modifier->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        label_9->setText(QString());
        label_13->setText(QApplication::translate("MainWindow", "DT", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "Client :", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "Mode de paiement :", Q_NULLPTR));
        modif_le_mode_f->clear();
        modif_le_mode_f->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Especes", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Cheque", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Carte bancaire", Q_NULLPTR)
        );
        Lb_client->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Modifier les factures", Q_NULLPTR));
        label_5->setText(QString());
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        supp->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "R\303\251f\303\251rence :", Q_NULLPTR));
        infos->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Supprimer les factures", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "Statistiques", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "Hash-tech", Q_NULLPTR));
        toolButton_4->setText(QApplication::translate("MainWindow", "Home", Q_NULLPTR));
        toolButton_5->setText(QApplication::translate("MainWindow", "Log out", Q_NULLPTR));
        toolButton_6->setText(QApplication::translate("MainWindow", "Settings", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "<----", Q_NULLPTR));
        Timer->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Time</p></body></html>", Q_NULLPTR));
        Date->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Date</p></body></html>", Q_NULLPTR));
        label_39->setText(QApplication::translate("MainWindow", "__________________", Q_NULLPTR));
        label_38->setText(QApplication::translate("MainWindow", "__________________", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        tabWidget_2->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        groupBox_7->setTitle(QApplication::translate("MainWindow", "Afficher", Q_NULLPTR));
        tri_ev->setText(QApplication::translate("MainWindow", "Trier", Q_NULLPTR));
        label_18->setText(QString());
        recherche_ev->setText(QString());
        recherche_ev->setPlaceholderText(QApplication::translate("MainWindow", "Rechercher ...", Q_NULLPTR));
        pdf_ev->setText(QApplication::translate("MainWindow", "PDF", Q_NULLPTR));
        impr_ev->setText(QApplication::translate("MainWindow", "Imprimer", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        supp_ev_2->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        supp_ev_2->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        supp_ev_2->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        supp_ev_2->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_ACCESSIBILITY
        supp_ev_2->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        supp_ev_2->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_7), QApplication::translate("MainWindow", "Afficher les evenements", Q_NULLPTR));
        groupBox_8->setTitle(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        id_ev->setText(QString());
        label_19->setText(QApplication::translate("MainWindow", "R\303\251f\303\251rence :", Q_NULLPTR));
        label_20->setText(QApplication::translate("MainWindow", "Date de fin :", Q_NULLPTR));
        label_21->setText(QApplication::translate("MainWindow", " Produit Inclus :", Q_NULLPTR));
        ajout_ev->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        label_23->setText(QApplication::translate("MainWindow", " Titre :", Q_NULLPTR));
        label_24->setText(QApplication::translate("MainWindow", " Date de d\303\251but :", Q_NULLPTR));
        nom_ev->setText(QString());
        checkBox->setText(QApplication::translate("MainWindow", "Inform\303\251 vos clients", Q_NULLPTR));
        label_25->setText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_8), QApplication::translate("MainWindow", "Ajouter un evenement", Q_NULLPTR));
        groupBox_9->setTitle(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        label_29->setText(QString());
        label_27->setText(QApplication::translate("MainWindow", "Date de fin :", Q_NULLPTR));
        modif_titre_ev->setText(QString());
        modif_ev->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        label_30->setText(QApplication::translate("MainWindow", " Date de d\303\251but :", Q_NULLPTR));
        label_26->setText(QApplication::translate("MainWindow", " Titre :", Q_NULLPTR));
        label_22->setText(QApplication::translate("MainWindow", "R\303\251f\303\251rence :", Q_NULLPTR));
        label_28->setText(QApplication::translate("MainWindow", " Produit Inclus :", Q_NULLPTR));
        Lb_client_2->setText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_9), QApplication::translate("MainWindow", "Modifier les evenements", Q_NULLPTR));
        label_33->setText(QString());
        groupBox_10->setTitle(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        supp_ev->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        label_34->setText(QApplication::translate("MainWindow", "R\303\251f\303\251rence :", Q_NULLPTR));
        infos_2->setText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_10), QApplication::translate("MainWindow", "Supprimer des evenements", Q_NULLPTR));
        qrcode->setText(QApplication::translate("MainWindow", "QrCode", Q_NULLPTR));
        qrlabel->setText(QString());
        menuAbout->setTitle(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
        toolBar_2->setWindowTitle(QApplication::translate("MainWindow", "toolBar_2", Q_NULLPTR));
        toolBar_3->setWindowTitle(QApplication::translate("MainWindow", "toolBar_3", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
