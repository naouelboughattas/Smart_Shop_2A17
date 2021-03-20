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


    vehicule v(matricule,marque,couleur);
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

void MainWindow::on_pushButton1_clicked()
{
    QString matricule = ui->le_Mat_M->text();
    QString marque = ui->lineEdit_Marq_M->text();
    QString couleur = ui->lineEdit_Cou_M->text();
    vehicule v;
    bool test=v.modifier_veh(matricule,marque,couleur);

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

