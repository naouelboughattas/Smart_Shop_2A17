#include "zeinebwindow.h"
#include "ui_zeinebwindow.h"
#include<QMessageBox>
zeinebwindow::zeinebwindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::zeinebwindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(tabs.afficherstock());
    this->setWindowTitle("Gestion Stock et depot");
    ui->comboBox_2->setModel(STOCK::afficher1());
    ui->comboBox_3->setModel(STOCK::afficher1());
    this->setWindowTitle("Gestion Stock et Depot");
    ui->comboBox_4->setModel(depot::afficher1());
    ui->tableView_2->setModel(tabd.afficherdepot());
    ui->comboBox->setModel(depot::afficher1());




}

zeinebwindow::~zeinebwindow()
{
    delete ui;
}


void zeinebwindow::on_pushButton_3_clicked()
{
    tabs.pdf();
}

void zeinebwindow::on_pushButton_ajouter_clicked()
{
    QSqlQuery qry ;
         QString   nomp,quantite,referencep,noms,references ;

            nomp=ui->lineEdit_nomp->text();
                quantite=ui->lineEdit_quantite->text();
                referencep=ui->lineEdit_referencep->text();
             noms=ui->lineEdit_noms->text();
             references=ui->lineEdit_references->text();
             ui->tableView->setModel(tabs.afficherstock());

             STOCK S(nomp,quantite,referencep,noms,references );
             bool test=S.ajouterproduit();
             if(test)
             {      ui->tableView->setModel(tabs.afficherstock());//actualisation

                 QMessageBox::information(nullptr,QObject::tr("Ajouter produit"),
                                                      QObject::tr("produit ajouté .\n"
                                                                  "Click Cancel to exit ."),QMessageBox::Cancel);
                      }
                 else
                 {
                 QMessageBox::critical(nullptr,QObject::tr("Ajouter produit"),
                                                  QObject::tr("ERooR .\n"
                                                              "Click Cancel to exit ."),QMessageBox::Cancel);
                 }
}

void zeinebwindow::on_pushButton_modifier_clicked()
{
    QSqlQuery qry ;
          QString   nomp,quantite,referencep,noms,references;

             nomp=ui->lineEdit_nomp->text();
                 quantite=ui->lineEdit_quantite->text();
                 referencep=ui->lineEdit_referencep->text();
              noms=ui->lineEdit_noms->text();
              references=ui->lineEdit_references->text();

              STOCK r(nomp,quantite,referencep,noms,references);
      bool test=tabs.modifierstock(ui->comboBox_3->currentText(),ui->lineEdit_nomp_2->text(),ui->lineEdit_quantite_2->text(),ui->lineEdit_quantite_3->text(),ui->lineEdit_quantite_4->text());
                   if (test)
                           {
                            ui->tableView->setModel(tabs.afficherstock());//actualisation

                       QMessageBox::information(nullptr,QObject::tr("Modifier stock"),
                                                        QObject::tr("stock Modifié .\n"
                                                                    "Click Cancel to exit ."),QMessageBox::Cancel);

                            }
                       else
                       {
                       QMessageBox::critical(nullptr,QObject::tr("Modifier stock"),
                                                        QObject::tr("stock Modifié .\n"
                                                                    "Click Cancel to exit ."),QMessageBox::Cancel);
                          }
}

void zeinebwindow::on_pushButton_clicked()
{



            bool test =tabs.supprimerstock(ui->comboBox_2->currentText());
            if(test)
               {
                QMessageBox::information(nullptr,QObject::tr("Supprimer stock"),
                                                 QObject::tr("stock supprimé .\n"
                                                             "Click Cancel to exit ."),QMessageBox::Cancel);

               }
            else
            {
                QMessageBox::information(nullptr,QObject::tr("Supprimer stock"),
                                                 QObject::tr("Erreur .\n"
                                                             "Click Cancel to exit ."),QMessageBox::Cancel);
               }
}

void zeinebwindow::on_tableView_activated(const QModelIndex &index)
{
    STOCK r ;
       // r.selectionnerstock(ui,index);
}

void zeinebwindow::on_tabWidget_2_currentChanged(int index)
{
   /* STOCK r;
      r.afficherstock(ui);*/
}

void zeinebwindow::on_pushButton_2_clicked()
{
    ui->tableView->setModel(tabs.afficherstock());
    ui->comboBox_2->setModel(STOCK::afficher1());


}



void zeinebwindow::on_comboBox_2_currentTextChanged(const QString &arg1)
{
    ui->comboBox_2->currentText();

}

void zeinebwindow::on_pushButton_4_clicked()
{
    STOCK * v = new STOCK(ui->lineEdit_nomp->text(),ui->lineEdit_quantite->text(),ui->lineEdit_referencep->text(),ui->lineEdit_noms->text(),ui->lineEdit_references->text());
    if(ui->radioButton->isChecked()){
       ui->tableView->setModel(v->sort1());
    }
    if(ui->radioButton_2->isChecked()){
        ui->tableView->setModel(v->sort2());    }
    delete v;
}

void zeinebwindow::on_comboBox_3_currentIndexChanged(const QString &arg1)
{
    ui->comboBox_3->currentText();

}

void zeinebwindow::on_pushButton_5_clicked()
{
    ui->comboBox_3->setModel(STOCK::afficher1());

}

void zeinebwindow::on_pushButton_recherche_clicked()
{
    bool q=tabs.search(ui->lineEdit_recherche->text());

       if( q == true){
           QMessageBox::information(nullptr,QObject::tr("OK"),
                                QObject::tr("produit trouve"),
                                QMessageBox::Ok);
       }else{
           QMessageBox::information(nullptr,QObject::tr("not OK"),
                                QObject::tr("produit non trouve "),
                                QMessageBox::Ok);
       }
}

void zeinebwindow::on_pushButton_ajouterd_clicked()
{
    depot d(ui->lineEdit_nomd->text(),ui->lineEdit_adresse->text(),ui->lineEdit_adresse_3->text());
    bool test=d.ajouterdepot();
    if(test)
    {      ui->tableView_2->setModel(tabd.afficherdepot());//actualisation

        QMessageBox::information(nullptr,QObject::tr("Ajouter produit"),
                                             QObject::tr("produit ajouté .\n"
                                                         "Click Cancel to exit ."),QMessageBox::Cancel);
             }
        else
        {
        QMessageBox::critical(nullptr,QObject::tr("Ajouter produit"),
                                         QObject::tr("ERooR .\n"
                                                     "Click Cancel to exit ."),QMessageBox::Cancel);
        }
}

void zeinebwindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    ui->comboBox->currentText();

}

void zeinebwindow::on_pushButton_act_clicked()
{
    ui->tableView_2->setModel(tabd.afficherdepot());
    ui->comboBox->setModel(depot::afficher1());

}

void zeinebwindow::on_pushButton_supprimerd_clicked()
{
    bool test =tabd.supprimerdepot(ui->comboBox->currentText());
    if(test)
       {  ui->tableView_2->setModel(tabd.afficherdepot());
        QMessageBox::information(nullptr,QObject::tr("Supprimer depot"),
                                         QObject::tr("depot supprimé .\n"
                                                     "Click Cancel to exit ."),QMessageBox::Cancel);

       }
    else
    {
        QMessageBox::information(nullptr,QObject::tr("Supprimer depot"),
                                         QObject::tr("Erreur .\n"
                                                     "Click Cancel to exit ."),QMessageBox::Cancel);
       }
}

void zeinebwindow::on_pushButton_recherche_4_clicked()
{
    bool q=tabd.search(ui->lineEdit_recherche_4->text());

       if( q == true){
           QMessageBox::information(nullptr,QObject::tr("OK"),
                                QObject::tr("produit trouve"),
                                QMessageBox::Ok);
       }else{
           QMessageBox::information(nullptr,QObject::tr("not OK"),
                                QObject::tr("produit non trouve "),
                                QMessageBox::Ok);
       }
}

void zeinebwindow::on_pushButton_13_clicked()
{
    ui->comboBox_4->setModel(depot::afficher1());
}

void zeinebwindow::on_pushButton_12_clicked()
{
    bool test=tabd.modifierdepot(ui->comboBox_4->currentText(),ui->lineEdit_adresse_2->text(),ui->lineEdit_adresse_4->text());
                 if (test)
                         {
                          ui->tableView_2->setModel(tabd.afficherdepot());//actualisation

                     QMessageBox::information(nullptr,QObject::tr("Modifier depot"),
                                                      QObject::tr("depot Modifié .\n"
                                                                  "Click Cancel to exit ."),QMessageBox::Cancel);

                          }
                     else
                     {
                     QMessageBox::critical(nullptr,QObject::tr("Modifier depot"),
                                                      QObject::tr("depot Modifié .\n"
                                                                  "Click Cancel to exit ."),QMessageBox::Cancel);
                        }
}

void zeinebwindow::on_pushButton_11_clicked()
{
    depot* d= new depot(ui->lineEdit_nomd->text(),ui->lineEdit_adresse->text(),ui->lineEdit_adresse_3->text());
    ui->tableView_2->setModel(d->sort1());

}

void zeinebwindow::on_pushButton_10_clicked()
{
    tabd.pdf();
}
