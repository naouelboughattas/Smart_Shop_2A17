#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include<QSqlQueryModel>
#include <stdlib.h>
#include <facture.h>
#include <evenement.h>
#include <QTableView>
#include "smtp.h"
#include "QrCode.hpp"
#include <arduino.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void arduino();   // slot permettant la mise à jour du label état de la lampe 1,

    void on_pb_ajouter_clicked();

    void on_pushButton_clicked();

    void on_supp_clicked();

    void on_pb_modifier_clicked();

    void on_lineEdit_textEdited(const QString &arg1);

    void on_pdf_clicked();

    void on_impr_clicked();

    void on_modif_box_currentTextChanged(const QString &arg1);

    void on_tabWidget_currentChanged(int index);

    void on_supr_box_currentIndexChanged(int index);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_modif_le_client_activated(const QString &arg1);

    void on_modif_box_currentIndexChanged(const QString &arg1);

    void on_supr_box_currentTextChanged(const QString &arg1);

    void on_bt_login_clicked();

    void on_commandLinkButton_clicked();

    void on_commandLinkButton_2_clicked();

    void on_ajout_ev_clicked();

    void on_tabWidget_2_currentChanged(int index);

    void on_supp_ev_clicked();

    void on_supp_ev_2_clicked();

    void on_pdf_ev_clicked();

    void on_impr_ev_clicked();

    void on_tri_ev_clicked();

    void on_recherche_ev_textEdited(const QString &arg1);

    void on_modif_ev_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_toolButton_2_clicked();

    void on_toolButton_clicked();

    void on_ajout_ev_2_clicked();

    void on_qrcode_clicked();

    void on_toolButton_5_clicked();

    void on_toolButton_4_clicked();

    void on_actionAbout_us_triggered();

    void showTime();



private:
    Ui::MainWindow *ui;
    Facture Ftemp;
    Evenement Etemp;
    Arduino Atemp;
    QString IDTemp;
    QString Rtemp;
    QString Ctemp;
    QByteArray data; // variable contenant les données reçues
    void keyPressEvent(QKeyEvent *event);
};

#endif // MAINWINDOW_H
