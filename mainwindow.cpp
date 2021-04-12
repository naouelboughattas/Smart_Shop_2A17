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
    ui->tableView_livreur->setModel(tmpliv.afficher_liv());
     ui->tableView_livraisons->setModel(tmplivraison.afficher_livraison());
    ui->stackedWidget->setCurrentIndex(2);
//
  // ui->comboBox_Matricule->setModel(tmpveh.afficher_veh());


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
     ui->stackedWidget->setCurrentIndex(1);
    ui->tableView_vehicule->setModel(tmpveh.afficher_veh());

}


void MainWindow::on_pushButton_4_clicked()
{
    QString cin = ui->le_cin->text();
    QString nom = ui->lineEdit_nom->text();
    QString prenom = ui->lineEdit_pr->text();
    QString statue = ui->comboBox->currentText();


    livreur l(cin,nom,prenom,statue);
    bool test=l.ajouter_liv();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Ajouter un livreur"),
                          QObject::tr("livreur ajouté.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
      //  ui->stackedWidget->setCurrentIndex(0);

        QString objet="AJOUT LIVREUR";
        QString message=" livreur a été ajouté avec succés" ;



    }

    ui->tableView_livreur->setModel(tmpliv.afficher_liv());

}





void MainWindow::on_pushmod_clicked()
{
    QString matricule = ui->comboBox_4->currentText();
    QString date_ent = ui->lineEdit_De_M->text();
    vehicule v;
    bool test=v.modifier_veh(matricule,date_ent);

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


void MainWindow::on_pushButton_8_clicked()
{
    QString matricule = ui->le->text();
    QString marque = ui->li->text();
    QString couleur = ui->lc->text();
    vehicule v;
    bool test=v.resaisie_veh(matricule,marque,couleur);

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

    ui->stackedWidget->setCurrentIndex(0);
    ui->tableView_vehicule->setModel(tmpveh.afficher_veh());

}


void MainWindow::on_pushmod_2_clicked()
{
    QString cin = ui->comboBox_3->currentText();

    QString statue = ui->comboBox_2->currentText();

    livreur l;
    bool test=l.modifier_liv(cin,statue);

    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("modifie un livreur"),
                          QObject::tr("livreur modifie.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("non modifie"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

     ui->tableView_livreur->setModel(tmpliv.afficher_liv());

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



void MainWindow::on_pushButton_S1_clicked()
{
    QString id =ui->tableView_livreur->model()->index(ui->tableView_livreur->currentIndex().row(),0).data().toString();
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "Supprimer", "Etes vous sur de supprimer ce livreur?",
                                    QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes) {
          bool test=tmpliv.supprimer_liv(id);
          if(test)
          {
              ui->tableView_livreur->setModel(tmpliv.afficher_liv());
              QMessageBox::information(nullptr,"Suppression","Livreur supprimé");

          }
      }

}

void MainWindow::on_pushButton_VE_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    ui->tableView_vehicule_EN->setModel(tmpveh.ent_veh());
}

void MainWindow::on_pushButton_tri_clicked()
{
    ui->tableView_vehicule->setModel(tmpveh.tri_veh());
}

void MainWindow::on_pushButton_tri_2_clicked()
{
    ui->tableView_livreur->setModel(tmpliv.tri_liv());
}

void MainWindow::on_lineEdit_R_textEdited(const QString &arg1)
{
    vehicule a;
    ui->tableView_vehicule->setModel(tmpveh.rechercher_veh_dynamique(arg1));
}

void MainWindow::on_lineEdit_R_2_textEdited(const QString &arg1)
{
    livreur a;
    ui->tableView_livreur->setModel(tmpliv.rechercher_liv_dynamique(arg1));
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->tableView_vehicule->setModel(tmpveh.afficher_veh());
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    ui->tableView_livreur->setModel(tmpliv.afficher_liv());
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::on_pushButton_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_res_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->tableView_livraisons->setModel(tmplivraison.afficher_livraison());
}




void MainWindow::on_tabWidget_2_currentChanged(int index)
{
    ui->comboBox_3->clear();
    ui->comboBox_3->addItems(tmpliv.recherche_liv());
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    ui->comboBox_4->clear();
    ui->comboBox_4->addItems(tmpveh.recherche_veh());

}
