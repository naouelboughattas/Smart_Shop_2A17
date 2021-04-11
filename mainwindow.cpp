#include "mainwindow.h"
#include "ui_mainwindow.h"

#include"client.h"
#include"abonnement.h"

#include<QMessageBox>
#include"statistique.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_ajouter_clicked()
{
    QSqlQuery qry ;
      QString   cin,nom,prenom,adresse,numero ;

         cin=ui->lineEdit_cin->text();
             nom=ui->lineEdit_nom->text();
             prenom=ui->lineEdit_prenom->text();
          adresse=ui->lineEdit_adresse->text();
          numero=ui->lineEdit_num->text();

          CLIENT C( cin , nom, prenom, adresse, numero);
          bool test=C.ajouterclient();
          if(test)
          {
              QMessageBox::information(nullptr,QObject::tr("Ajouter client"),
                                                   QObject::tr("client ajouté .\n"
                                                               "Click Cancel to exit ."),QMessageBox::Cancel);
                   }
              else
              {
              QMessageBox::critical(nullptr,QObject::tr("Ajouter client"),
                                               QObject::tr("ERooR .\n"
                                                           "Click Cancel to exit ."),QMessageBox::Cancel);
              }

         }

void MainWindow::on_pushButton_modifier_clicked()
{
    QSqlQuery qry ;
      QString   cin,nom,prenom,adresse,numero ;

         cin=ui->lineEdit_cin->text();
             nom=ui->lineEdit_nom->text();
             prenom=ui->lineEdit_prenom->text();
          adresse=ui->lineEdit_adresse->text();
          numero=ui->lineEdit_num->text();

          CLIENT r( cin , nom, prenom, adresse, numero);
          bool test=r.modifierclient();
               if (test)
                       {
                   QMessageBox::information(nullptr,QObject::tr("Modifier client"),
                                                    QObject::tr("client Modifié .\n"
                                                                "Click Cancel to exit ."),QMessageBox::Cancel);

                        }
                   else
                   {
                   QMessageBox::critical(nullptr,QObject::tr("Modifier client"),
                                                    QObject::tr("client Modifié .\n"
                                                                "Click Cancel to exit ."),QMessageBox::Cancel);
                      }
}

void MainWindow::on_tabWidget_2_currentChanged(int index)
{

    CLIENT r;
    r.afficherclient(ui);
}

void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    CLIENT r ;
       r.selectionnerclient(ui,index);
}


void MainWindow::on_pushButton_clicked()
{
   QSqlQuery qry;
       CLIENT r;


        bool test =r.supprimerclient(ui);
        if(test)
           {
            QMessageBox::information(nullptr,QObject::tr("Supprimer client"),
                                             QObject::tr("client supprimé .\n"
                                                         "Click Cancel to exit ."),QMessageBox::Cancel);

           }
        else
        {
            QMessageBox::information(nullptr,QObject::tr("Supprimer client"),
                                             QObject::tr("Erreur .\n"
                                                         "Click Cancel to exit ."),QMessageBox::Cancel);
           }

}



void MainWindow::on_pushButton_2_clicked()
{
    CLIENT r;
    r.afficherclient(ui);

}

void MainWindow::on_pushButton_3_clicked()
{
statistique s ;
s.exec();




}

void MainWindow::on_radioButton_clicked()
{
    CLIENT c ;
       c.TRI1(ui);
}

void MainWindow::on_radioButton_2_clicked()
{
    CLIENT c ;
       c.TRI1(ui);
}

void MainWindow::on_pushButton_recherche_clicked()
{
    CLIENT c;
        c.recherche(ui);
}

void MainWindow::on_pushButton_ajouterabo_clicked()
{
  QSqlQuery qry ;
      QString  id,cinabo,type;

         id=ui->lineEdit_idabo->text();
             cinabo=ui->lineEdit_cinabo->text();
             type=ui->comboBox->currentText();


          abonnement C( id , cinabo, type);
          bool test=C.ajouterabonnement();
          if(test)
          {
              QMessageBox::information(nullptr,QObject::tr("Ajouter abonnement"),
                                                   QObject::tr("client abonnement .\n"
                                                               "Click Cancel to exit ."),QMessageBox::Cancel);
                   }
              else
              {
              QMessageBox::critical(nullptr,QObject::tr("Ajouter abonnement"),
                                               QObject::tr("ERooR .\n"
                                                           "Click Cancel to exit ."),QMessageBox::Cancel);
              }
}

void MainWindow::on_pushButton_modifierabo_clicked()
{
 QSqlQuery qry ;
      QString  id,cinabo,type;

         id=ui->lineEdit_idabo->text();
             cinabo=ui->lineEdit_cinabo->text();
             type=ui->comboBox->currentText();



          abonnement C( id , cinabo, type);
          bool test=C.modifierabonnement();
          if(test)
          {
              QMessageBox::information(nullptr,QObject::tr("modifier abonnement"),
                                                   QObject::tr("client abonnement .\n"
                                                               "Click Cancel to exit ."),QMessageBox::Cancel);
                   }
              else
              {
              QMessageBox::critical(nullptr,QObject::tr("modifier abonnement"),
                                               QObject::tr("ERooR .\n"
                                                           "Click Cancel to exit ."),QMessageBox::Cancel);
              }

}

void MainWindow::on_tabWidget_typeabo_currentChanged(int index)
{

    abonnement r;
    r.afficherabonnement(ui);
}

void MainWindow::on_pushButton_supprimerabo_clicked()
{
   QSqlQuery qry;
       abonnement r;


        bool test =r.supprimerabonnement(ui);
        if(test)
           {
            QMessageBox::information(nullptr,QObject::tr("Supprimer abonnement"),
                                             QObject::tr("abonnement supprimé .\n"
                                                         "Click Cancel to exit ."),QMessageBox::Cancel);

           }
        else
        {
            QMessageBox::information(nullptr,QObject::tr("Supprimer abonnement"),
                                             QObject::tr("Erreur .\n"
                                                         "Click Cancel to exit ."),QMessageBox::Cancel);
           }

}

void MainWindow::on_pushButton_act_clicked()
{
    abonnement r;
    r.afficherabonnement(ui);
}

void MainWindow::on_tableView_2_activated(const QModelIndex &index)
{
    abonnement r ;
       r.selectionnerabonnement(ui,index);
}

void MainWindow::on_pushButton_statistiqueabo_clicked()
{
    QString str;
               str.append("<!DOCTYPE html><html lang='en'><head><style>#ipi-table > thead > tr, #ipi-table > thead > tr > td {font-size: .9em;font-weight: 400;background: #51596a;text-transform: uppercase;color: #ffffff;}#ipi-table > tbody > tr > td {max-height: 200px;vertical-align: middle!important;}</style></head><body><div class='container'><div class='row'><div class='col-md-12'><p>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  &nbsp; &nbsp; &nbsp; TABLEAU GESTION EVENEMENTS  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;</p></div></div></div><div class='container'><div class='card' id='TableSorterCard'><div class='row'><div class='col-12'><div><table class='table table tablesorter' id='ipi-table'><thead class='thead-dark'><tr><th>Column 1</th><th class='sorter-false'>ID_EVENEMENT &nbsp; &nbsp;</th><th class='filter-false'>NOM_EVENEMENT &nbsp; &nbsp;</th><th class='filter-false sorter-false'>TYPE &nbsp; &nbsp;</th><th class='filter-false sorter-false'>BUDGET &nbsp; &nbsp;</th><th class='filter-false sorter-false'>LIEU &nbsp; &nbsp;</th><th class='filter-false sorter-false'>NOMBRE INVITES &nbsp; &nbsp;</th></tr></thead><tbody>");




               QSqlQuery* query=new QSqlQuery();
               query->exec("SELECT * FROM CLIENT");

               while(query->next())
               {
               str.append("<tr><td>");
               str.append(query->value(0).toString()) ;
               str.append("</td><td>") ;
               str.append(query->value(1).toString());
               str.append("</td><td>") ;
               str.append(query->value(2).toString());
               str.append("</td><td>") ;
               str.append(query->value(3).toString());
               str.append("</td><td>") ;
               str.append(query->value(4).toString());
               str.append("</td><td>") ;
               str.append(query->value(5).toString());
               str.append("</td></td>");



               }
}
