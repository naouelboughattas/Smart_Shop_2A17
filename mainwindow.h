#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include<QSqlQueryModel>
#include <QTableView>
#include <stdlib.h>
#include <facture.h>
#include <evenement.h>
#include "smtp.h"
#include "QrCode.hpp"
#include <arduino.h>
#include "produit.h"
#include "categorie.h"
#include "stock.h"
#include "depot.h"
#include "employer.h"
#include "tache.h"
#include "notif.h"
#include <QSystemTrayIcon>
#include "Livraison.h"
#include "livreur.h"
#include "Vehicule.h"




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

    void refresh();

    void refresh2();


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



    void on_lineEdit_5_textEdited(const QString &arg1);

    void on_pdff_5_clicked();

    void on_pushButton_18_clicked();

    void on_commandLinkButton_3_clicked();

    void on_pushButton_19_clicked();

    void on_pb_modifier_5_clicked();

    void on_tab_20_currentChanged(int index);

    void on_pb_supprimer_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_17_clicked();

    void on_toolButton_19_clicked();

    void on_toolButton_17_clicked();

    void on_toolButton_20_clicked();

    void on_toolButton_16_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_toolButton_25_clicked();

    void on_toolButton_26_clicked();

    void on_pdff_clicked();

    void on_tabWidget_3_currentChanged(int index);

    void on_categorie_clicked();

    void on_pushButton_5_cat_clicked();

    void on_lineEdit_2_cat_textEdited(const QString &arg1);

    void on_pb_ajouter_cat_clicked();

    void on_pb_modifier_2_cat_clicked();

    void on_pb_supprimer_2_cat_clicked();

    void on_pushButton_8_clicked();

    void on_produit_clicked();

    void on_facture_clicked();

    void on_categorie_2_clicked();

    void on_categorie_6_clicked();

    void on_stock_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_ajouter_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17z_clicked();

    void on_comboBox_2_currentTextChanged(const QString &arg1);

    void on_pushButton_23_clicked();

    void on_comboBox_3_currentIndexChanged(const QString &arg1);

    void on_pushButton_25_clicked();

    void on_pushButton_recherche_clicked();

    void on_qrcode_3_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_15_clicked();

    void on_toolButton_34_clicked();

    void on_toolButton_35_clicked();

    void on_categorie_5_clicked();

    void on_toolButton_38_clicked();

    void on_toolButton_37_clicked();

    void on_pushButton_ajouterd_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pushButton_act_clicked();

    void on_pushButton_supprimerd_clicked();

    void on_pushButton_recherche_4_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_28_clicked();

    void on_client_clicked();

    void on_pushButton_31_clicked();

    void on_toolButton_40_clicked();

    void on_toolButton_41_clicked();

    void showTime2();


    void on_pushButton_ajouter_2_clicked();

    void on_pushButton_modifier_2_clicked();

    void on_tabWidget_9_currentChanged(int index);

    void on_tableView_3_activated(const QModelIndex &index);

    void on_pushButton_32_clicked();

    void on_pushButton_33_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_pushButton_recherche_2_clicked();

    void on_pushButton_34_clicked();

    void on_sendBtn_clicked();

    void sendMail();

    void mailSent(QString);


    void on_pushButton_36_clicked();

    void on_toolButton_43_clicked();

    void on_toolButton_44_clicked();

    void on_pushButton_ajouterabo_clicked();

    void on_pushButton_modifierabo_clicked();

    void on_pushButton_supprimerabo_clicked();

    void on_pushButton_37_clicked();

    void on_pushButton_act_2_clicked();

    void on_tabWidget_typeabo_currentChanged(int index);

    void on_client_2_clicked();

    void on_abonnement_clicked();

    void on_tache_clicked();

    void on_Personnel_clicked();

    void on_Livraison_clicked();

    void on_livreur_clicked();

    void on_vehicule_clicked();

    void on_pushButton_42_clicked();

    void on_toolButton_58_clicked();

    void on_pushButton_41_clicked();

    void on_toolButton_55_clicked();

    void on_pushButton_40_clicked();

    void on_toolButton_52_clicked();

    void on_pushButton_39_clicked();

    void on_toolButton_49_clicked();

    void on_pushButton_38_clicked();

    void on_toolButton_46_clicked();

    void on_toolButton_47_clicked();

    void on_toolButton_50_clicked();

    void on_toolButton_53_clicked();

    void on_toolButton_56_clicked();

    void on_toolButton_59_clicked();

    void on_pb_ajouter_3_clicked();

    void on_pb_modifier_3_clicked();

    void on_comboBox_9_activated(const QString &arg1);

    void on_comboBox_8_activated(const QString &arg1);

    void on_pb_supprimer_clicked();

    void on_cin_3_textEdited(const QString &arg1);

    void on_trie_2_clicked();

    void on_imprimer_clicked();

    void on_pdf_2_clicked();

    void on_pb_tache_clicked();

    void on_makeShot_clicked();

    void on_modifier_currentChanged(int index);

    void on_pb_ajouter_2_clicked();

    void on_modifier_2_currentChanged(int index);

    void on_cin_4_textEdited(const QString &arg1);

    void on_trie_clicked();

    void on_comboBox_6_activated(const QString &arg1);

    void on_comboBox_7_activated(const QString &arg1);

    void on_pb_modifier_2_clicked();

    void on_checkBox_pressed();

    void on_email_6_clicked();

    void on_qrcode_5_clicked();

    void on_pb_supprimer_2_clicked();

    void readfile();

    void on_lineEdit_R_3_textEdited(const QString &arg1);

    void on_SL_clicked();

    void on_pdf_3_clicked();

    void on_reload_clicked();

    void on_Marquer_livre_clicked();

    void on_tabWidget_4_currentChanged(int index);

    void on_lineEdit_R_2_textEdited(const QString &arg1);

    void on_pushButton_S1_clicked();

    void on_pushButton_tri_2_clicked();

    void on_pdfl_clicked();

    void on_qrcode_2_clicked();

    void on_pushButton_43_clicked();

    void on_toolButton_61_clicked();

    void on_toolButton_62_clicked();

    void on_pbre_clicked();

    void on_pushButton_12_clicked();

    void on_pushmod_2_clicked();

    void on_tabWidget_5_currentChanged(int index);

    void on_tabWidget_6_currentChanged(int index);

    void on_lineEdit_R_textEdited(const QString &arg1);

    void on_pushButton_S_clicked();

    void on_pushButton_tri_clicked();

    void on_pdf_4_clicked();

    void on_res_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_44_clicked();

    void on_toolButton_64_clicked();

    void on_toolButton_65_clicked();

    void on_pushButton_45_clicked();

    void on_toolButton_67_clicked();

    void on_toolButton_68_clicked();

    void on_pushButton_VE_clicked();

    void on_qrcode_4_clicked();

    void on_pushmod_clicked();

    void on_pushButton_13_clicked();

    void on_email_7_clicked();

private:
    Ui::MainWindow *ui;
    Facture Ftemp;
    Evenement Etemp;
    Arduino Atemp;
    QString IDTemp;
    QString Rtemp;
    QString Ctemp;
    QByteArray data; // variable contenant les données reçues
    Produit P;
    Categorie C;
    STOCK tabs;
    depot tabd;
    employer tmpemployer;
    tache tmptache;
    int etat=0;
    QString valeur;
    livraison tmplivraison ;
    livreur tmpliv;
    vehicule tmpveh;
    void keyPressEvent(QKeyEvent *event);
};

#endif // MAINWINDOW_H
