#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "categorie.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QTextBrowser>
#include <QTextStream>
#include <QPlainTextEdit>
#include <QFile>
#include <QString>

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


void MainWindow::on_pb_ajouter_clicked()
{
    int ID_cat=ui->le_id->text().toInt();
    QString Nom_cat=ui->le_nom->text();

    Categorie C(ID_cat,Nom_cat);
    bool test=C.ajouter();
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Ajout avec succes.");
        ui->tab_catgorie->setModel(C.afficher());
       }
    else
        msgBox.setText("Echec d'ajout");
    msgBox.exec();

}

void MainWindow::on_pb_modifier_clicked()
{
    int ID_cat=ui->id_mod->text().toInt();
    QString Nom_cat=ui->nom_mod->text();

       Categorie C2;
       bool test=C2.modifier(ID_cat,Nom_cat);

       if(test)
       {
         ui->id_mod->clear();
         ui->nom_mod->clear();
           QMessageBox::information(nullptr, QObject::tr("Modification effectue"),
                             QObject::tr("Produit modifie.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
       }
       else
           QMessageBox::critical(nullptr, QObject::tr("Modification echoue"),
                       QObject::tr("Erreur !.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
     ui->tab_catgorie->setModel(C2.afficher());

}

void MainWindow::on_pb_supprimer_clicked()
{
    Categorie C1; C1.setID_cat(ui->id_supp->text().toInt());
    bool test=C1.supprimer(C1.getID_cat());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Suppression avec succes.");
        ui->tab_catgorie->setModel(C.afficher());

       }
    else
        msgBox.setText("Echec de suppression");
    msgBox.exec();

}
