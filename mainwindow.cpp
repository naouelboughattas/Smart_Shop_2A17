#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "produit.h"
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
    ui->le_id->setValidator(new QIntValidator(100,9999999,this));
    ui->tab_produit->setModel(P.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int id_P=ui->le_id->text().toInt();
    QString nom_P=ui->le_nom->text();
    QString type=ui->le_type->text();
    int prix=ui->le_prix->text().toInt();

    Produit P(id_P,nom_P,type,prix);
    bool test=P.ajouter();
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Ajout avec succes.");
        ui->tab_produit->setModel(P.afficher());

       }
    else
        msgBox.setText("Echec d'ajout");
    msgBox.exec();
}

void MainWindow::on_pb_supprimer_clicked()
{
    Produit P1; P1.setid_P(ui->id_supp->text().toInt());
    bool test=P1.supprimer(P1.getid_P());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Suppression avec succes.");
        ui->tab_produit->setModel(P.afficher());

       }
    else
        msgBox.setText("Echec de suppression");
    msgBox.exec();
}

void MainWindow::on_pb_modifier_clicked()
{
    int id_P=ui->id_mod->text().toInt();
    QString nom_P=ui->nom_mod->text();
    QString type=ui->type_mod->text();
    int prix=ui->prix_mod->text().toInt();

       Produit P2;
       bool test=P2.modifier(id_P,nom_P,type,prix);

       if(test)
       {
          ui->id_mod->clear();
         ui->nom_mod->clear();
         ui->type_mod->clear();
         ui->prix_mod->clear();
           QMessageBox::information(nullptr, QObject::tr("Modification effectue"),
                             QObject::tr("Produit modifie.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
       }
       else
           QMessageBox::critical(nullptr, QObject::tr("Modification echoue"),
                       QObject::tr("Erreur !.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
     ui->tab_produit->setModel(P2.afficher());
}

