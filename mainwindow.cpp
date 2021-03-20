#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QGridLayout>
#include <QTableView>
#include <QPdfWriter>
#include"QTextDocumentWriter"
#include"QDesktopServices"
#include <QPixmap>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   ui->tableView_vehicule->setModel(tmpveh.afficher_veh());
   // ui->stackedWidget->setCurrentIndex(6);
//
  //  ui->comboBox_Matricule->setModel(tmpveh.afficher_veh());


}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_clicked()
{
    QString matricule = ui->le_Mat->text();
    QString marque = ui->lineEdit_Marq->text();
    QString couleur = ui->lineEdit_Cou->text();
     QString date_ent = ui->lineEdit_De->text();


    vehicule v(matricule,marque,couleur,date_ent);
    bool test=v.ajouter_veh();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Ajouter une vehicule"),
                          QObject::tr("vehicule ajouté.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
      //  ui->stackedWidget->setCurrentIndex(0);

        QString objet="AJOUT VEHICULE";
        QString message=" Votre vehicule a été ajouté avec succés" ;



    }

    ui->tableView_vehicule->setModel(tmpveh.afficher_veh());

}

void MainWindow::on_pushmod_clicked()
{
    QString matricule = ui->le_Mat_M->text();
    QString marque = ui->lineEdit_Marq_M->text();
    QString couleur = ui->lineEdit_Cou_M->text();
    QString date_ent = ui->lineEdit_De_M->text();
    vehicule v;
    bool test=v.modifier_veh(matricule,marque,couleur,date_ent);

    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("modifie une vehicule"),
                          QObject::tr("vehicule modifie.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("non modifie"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

     ui->tableView_vehicule->setModel(tmpveh.afficher_veh());

}

void MainWindow::on_pushButton_S_clicked()
{
    QString id =ui->tableView_vehicule->model()->index(ui->tableView_vehicule->currentIndex().row(),0).data().toString();
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "Supprimer", "Etes vous sur de supprimer cette vehicule?",
                                    QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes) {
          bool test=tmpveh.supprimer_veh(id);
          if(test)
          {
              ui->tableView_vehicule->setModel(tmpveh.afficher_veh());
              QMessageBox::information(nullptr,"Suppression","Vehicule supprimé");

          }
      }

}
void MainWindow::on_pushButton_tri_clicked()
{
    ui->tableView_vehicule->setModel(tmpveh.tri_veh());
}

void MainWindow::on_lineEdit_R(const QString &arg1)
{
    vehicule a;
    ui->tableView_vehicule->setModel(tmpveh.rechercher_veh_dynamique(arg1));
}
