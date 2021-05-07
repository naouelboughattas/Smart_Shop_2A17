/********************************************************************************
** Form generated from reading UI file 'statistique.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTIQUE_H
#define UI_STATISTIQUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_statistique
{
public:
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_4;
    QWidget *widget_6;
    QWidget *widget;
    QWidget *widget_5;

    void setupUi(QDialog *statistique)
    {
        if (statistique->objectName().isEmpty())
            statistique->setObjectName(QStringLiteral("statistique"));
        statistique->resize(400, 300);
        label_3 = new QLabel(statistique);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(320, 130, 151, 16));
        QFont font;
        font.setFamily(QStringLiteral("Comic Sans MS"));
        font.setPointSize(10);
        label_3->setFont(font);
        label_2 = new QLabel(statistique);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(320, 100, 171, 16));
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral(""));
        label_4 = new QLabel(statistique);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(330, 160, 171, 16));
        label_4->setFont(font);
        widget_6 = new QWidget(statistique);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setGeometry(QRect(280, 120, 31, 31));
        widget_6->setStyleSheet(QLatin1String("background-image: url(:/img/ressources/carre-jaune-fond-transparent.png);\n"
"background-color: rgb(255, 255, 0);"));
        widget = new QWidget(statistique);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(280, 90, 20, 20));
        widget->setStyleSheet(QLatin1String("background-image: url(:/img/ressources/blue.jpg);\n"
"background-color: rgb(85, 0, 255);"));
        widget_5 = new QWidget(statistique);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setGeometry(QRect(290, 160, 20, 20));
        widget_5->setStyleSheet(QLatin1String("background-color: rgb(255, 0, 0);\n"
"background-image: url(:/img/ressources/rouge.jpg);"));

        retranslateUi(statistique);

        QMetaObject::connectSlotsByName(statistique);
    } // setupUi

    void retranslateUi(QDialog *statistique)
    {
        statistique->setWindowTitle(QApplication::translate("statistique", "Dialog", Q_NULLPTR));
        label_3->setText(QApplication::translate("statistique", "TextLabel", Q_NULLPTR));
        label_2->setText(QApplication::translate("statistique", "TextLabel", Q_NULLPTR));
        label_4->setText(QApplication::translate("statistique", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class statistique: public Ui_statistique {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTIQUE_H
