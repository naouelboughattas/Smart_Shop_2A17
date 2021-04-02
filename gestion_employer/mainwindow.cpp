#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connexion.h"
#include "employer.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    refresh();

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::refresh()
{
  ui->tabemployer->setModel(tmpemployer.afficher_employer());
  ui->comboBox_3->setModel(tmpemployer.afficher_list());
  ui->comboBox_5->setModel(tmpemployer.afficher_list());
}

void MainWindow::on_pb_ajouter_clicked()
{
    QString cin=ui->cin->text();
    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
    QString adresse=ui->adresse->text();
    QString email=ui->email->text();
    employer e(cin,nom,prenom,adresse,email);
    bool test=e.ajouter_employer();
    if(test){
        QMessageBox::information(nullptr, QObject::tr("Personnel ajouté"),
                    QObject::tr("Personnel ajouté.\n"
                                "OK"), QMessageBox::Cancel);
}else
        QMessageBox::information(nullptr, QObject::tr("Personnel non ajouté"),
                    QObject::tr("Personnel non ajouté.\n"
                                "OK"), QMessageBox::Cancel);
    ui->tabemployer->setModel(tmpemployer.afficher_employer());
    refresh();
}

void MainWindow::on_pb_modifier_clicked()
{
    tmpemployer.setnom(ui->nom_2->text());
    tmpemployer.setprenom(ui->prenom_2->text());
    tmpemployer.setadresse(ui->adresse_2->text());
    tmpemployer.setemail(ui->email_2->text());

    bool test=tmpemployer.modifier_employer();
    refresh();

}


/*
void MainWindow::on_comboBox_3_activated(const QString &arg1)
{
    tmpemployer.setcin(arg1);
    tmpemployer.chercher();
    ui->nom_2->setText(tmpemployer.getnom());
    ui->prenom_2->setText(tmpemployer.getprenom());
    ui->adresse_2->setText(tmpemployer.getadresse());
    ui->email_2->setText(tmpemployer.getemail());
    refresh();


}
*/

void MainWindow::on_comboBox_5_activated(const QString &arg1)
{
    ui->sup->setText(arg1);
    refresh();
}



void MainWindow::on_cin_3_textChanged(const QString &arg1)
{
    ui->tabemployer->setModel(tmpemployer.recherche(arg1,etat));
    valeur=arg1;
    refresh();
}



void MainWindow::on_checkBox_2_stateChanged(int arg1)
{

    etat=arg1;
    ui->tabemployer->setModel(tmpemployer.recherche(valeur,etat));
    refresh();
}






void MainWindow::on_pb_supprimer_clicked()
{
    //QString cin = ui->cin->text();
     employer e;
     e.setcin(ui->cin->text());
     bool test=e.supprimer_employer();
     if(test){
         QMessageBox::information(nullptr, QObject::tr("Personnel Supprimé"),
                     QObject::tr("Personnel ajouté.\n"
                                 "OK"), QMessageBox::Cancel);
 }else
         QMessageBox::information(nullptr, QObject::tr("Personnel non Supprimé"),
                     QObject::tr("Personnel non ajouté.\n"
                                 "OK"), QMessageBox::Cancel);
    ui->tabemployer->setModel(tmpemployer.afficher_employer());
    refresh();
}


void MainWindow::on_comboBox_3_activated(int index)
{
    tmpemployer.setcin(ui->cin->text());
    tmpemployer.chercher();
    ui->nom_2->setText(tmpemployer.getnom());
    ui->prenom_2->setText(tmpemployer.getprenom());
    ui->adresse_2->setText(tmpemployer.getadresse());
    ui->email_2->setText(tmpemployer.getemail());
    refresh();
}
