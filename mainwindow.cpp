#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "facture.h"
#include "evenement.h"
#include <QMessageBox>
#include <QPixmap>
#include <QIntValidator>
#include <QTableView>
#include <QPainter>
#include <QPdfWriter>
#include "QTextDocumentWriter"
#include <QTextStream>
#include "QDesktopServices"
#include <QFileDialog>
#include <QPrinter>
#include "QFont"
#include "QPen"
#include <QPainter>
#include <QTextDocument>
#include <QDate>
#include <QPrintDialog>
#include <QPropertyAnimation>
#include <QDateTime>
#include <QResizeEvent>
#include <QDebug>
#include <QDesktopWidget>
#include <QListWidget>
#include <QKeyEvent>
#include "QrCode.hpp"
#include <QMediaPlayer>
#include <QDebug>
#include <QTimer>
#include "exportexcelobjet.h"
#include <QFileDialog>
#include "client.h"
#include "abonnement.h"
#include "statistique.h"



using namespace qrcodegen;

void MainWindow::on_bt_login_clicked()
{
    if(ui->user->text()=="wael" && ui->pass->text()=="ksila"){
        QMediaPlayer* player;
        player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/Users/waelk/OneDrive/Bureau/C++/PROJET/ProjetFinal/bienvenue.mp3"));
                     player->play();
                     qDebug()<<player->errorString();

                     QPropertyAnimation *animationajouterp;
                     animationajouterp = new QPropertyAnimation(ui->bt_login,"geometry");
                     animationajouterp->setDuration(1000);
                     animationajouterp->setStartValue(QRect(660,450,141,51));
                     animationajouterp->setEndValue(QRect(650,450,200,51));
                     animationajouterp->setEasingCurve(QEasingCurve::InOutQuint);
                     animationajouterp->start(QPropertyAnimation::DeleteWhenStopped);



    ui->stackedWidget->setCurrentIndex(1);

    }else{
    QMessageBox::information(nullptr, QObject::tr("FAILED CONNECTION"),
                    QObject::tr("connection failed !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
}
void MainWindow::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Enter && ui->stackedWidget->currentIndex()==0 ){
            ui->bt_login->clicked();
        }else if(event->key() == Qt::Key_F && ui->stackedWidget->currentIndex()!=0 ){
        ui->stackedWidget->setCurrentIndex(2);
        ui->tab_fact->setModel(Ftemp.afficher());
    }else if(event->key() == Qt::Key_E && ui->stackedWidget->currentIndex()!=0 ){
        ui->stackedWidget->setCurrentIndex(3);
        ui->tab_ev->setModel(Etemp.afficher_ev());
        ui->supr_ev->clear();
        ui->supr_ev->addItems(Etemp.recherche_id_ev());


    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->setFixedSize(1050,600);


    ui->progressBar->setValue(0);



    ui->tab_ev->setModel(Etemp.afficher_ev());
    ui->tab_produit_4->setModel(P.afficher());  // afficher produit
    ui->tab_fact->setModel(Ftemp.afficher());
    ui->produit_inclus->clear();
    ui->produit_inclus->addItems(Etemp.recherche_produit());
    ui->modif_produit_inclus->clear();
    ui->modif_produit_inclus->addItems(Etemp.recherche_produit());


    /*/////////////////////////////AJOUTTER IMAGE/////////////////////////////////////*/
    QPixmap pix("C:/Users/waelk/OneDrive/Bureau/C++/PROJET/MyProj/img/ajout.png");
    ui->label_4->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));
    QPixmap pix_aff("C:/Users/waelk/OneDrive/Bureau/C++/PROJET/MyProj/img/affiche.png");
    ui->label_10->setPixmap(pix_aff.scaled(100,100,Qt::KeepAspectRatio));
    QPixmap pix_m("C:/Users/waelk/OneDrive/Bureau/C++/PROJET/MyProj/img/modifie.png");
    ui->label_9->setPixmap(pix_m.scaled(100,100,Qt::KeepAspectRatio));
    QPixmap pix_sup("C:/Users/waelk/OneDrive/Bureau/C++/PROJET/MyProj/img/supprime.png");
    ui->label_5->setPixmap(pix_sup.scaled(100,100,Qt::KeepAspectRatio));
    /*/////////////////////////////////////////////////////////////////////////////*/


    /*////////////////////////CONTROLE DE SAISIE///////////////////////////////////*/
    ui->le_ttc_f->setValidator( new QIntValidator(0, 999999999, this));
    ui->modif_ttc_f->setValidator( new QIntValidator(0, 999999999, this));
    /*/////////////////////////////////////////////////////////////////////////////*/


    ui->tab_fact->setModel(Ftemp.afficher());
    ui->tab_ev->setModel(Etemp.afficher_ev());

    ui->date_box->setDateTime(QDateTime::currentDateTime());
    ui->modif_date_f_box->setDateTime(QDateTime::currentDateTime());
    ui->le_id_f->setText(Ftemp.remplir());
    ui->id_ev->setText(Etemp.remplir_ev());

    int ret=Atemp.connect_arduino(); // lancer la connexion ?? arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< Atemp.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<Atemp.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(Atemp.getserial(),SIGNAL(readyRead()),this,SLOT(arduino())); // permet de lancer
     //le slot update_label suite ?? la reception du signal readyRead (reception des donn??es).

     //Timer
      QTimer *timer_p=new QTimer(this);
      connect(timer_p,SIGNAL(timeout()),this,SLOT(showTime()));
      timer_p->start();
      //DAate systeme
      QDateTime Date_p=QDateTime::currentDateTime();
      QString Date_txt=Date_p.toString("dddd dd MMMM yyyy");
      ui->Date_7->setText(Date_txt);

      ui->le_id_5->setValidator(new QIntValidator(100,9999999,this));

      ui->tableView->setModel(tabs.afficherstock());
      this->setWindowTitle("Gestion Stock et depot");
      ui->comboBox_2->setModel(STOCK::afficher1());
      ui->comboBox_3->setModel(STOCK::afficher1());
      this->setWindowTitle("Gestion Stock et Depot");
      ui->comboBox_4->setModel(depot::afficher1());
      ui->tableView_2->setModel(tabd.afficherdepot());
      ui->comboBox->setModel(depot::afficher1());

      QTimer *timer=new QTimer(this);
          connect(timer,SIGNAL(timeout()),this,SLOT(showTime2()));
          timer->start();

          refresh();
          ui->tabemployer->setModel(tmpemployer.afficher_employer());



}
void MainWindow::refresh()
{
  ui->tabemployer->setModel(tmpemployer.afficher_employer());
  ui->comboBox_8->setModel(tmpemployer.afficher_list());
  ui->comboBox_9->setModel(tmpemployer.afficher_list());
}
void MainWindow::refresh2()
{
  ui->tabtache->setModel(tmptache.afficher_tache());
  ui->comboBox_7->setModel(tmptache.afficher_liste());
  ui->comboBox_6->setModel(tmptache.afficher_liste());
}


void MainWindow::showTime()
{
    QTime time=QTime::currentTime();
    QString time_txt=time.toString("hh:mm:ss");
    ui->Timer_2->setText(time_txt);

}


void MainWindow::arduino(){
    /* ################################## Arduino ##################################*/
    if(Etemp.recher_arduino(Atemp.read_from_arduino())==1){
        Atemp.write_to_arduino("1");
    }else{
        Atemp.write_to_arduino("0");
    }
    /* #############################################################################*/
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{

    /**************************************************************************************/
    QSqlQuery query;
    QString result;
    query.prepare("SELECT ID_CLIENT FROM CLIENTS WHERE NOM_C=:a ");
    query.bindValue(":a",ui->le_client->currentText());
    query.exec();
    while(query.next()){
   result=query.value(0).toString();
    }
    /**************************************************************************************/

    QString id_f=ui->le_id_f->text();
    QDateTime date_f=ui->date_box->dateTime();
    QString ttc_f=ui->le_ttc_f->text();
    QString mode_f=ui->le_mode_f->currentText();
    QString nom_c=ui->le_client->currentText();


    Facture F(id_f,date_f,ttc_f,mode_f,result);

    bool test=F.ajouter();
    if(test){
        ui->tab_fact->setModel(Ftemp.afficher());
        notif m("Facture","Facture Ajout??");
        m.afficher();


    }else{
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                              QObject::tr("Ajout non effectu??\n"
                                 "Click Cancel to exit."),QMessageBox::Cancel);

    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->tab_fact->setModel(Ftemp.tri());
    ui->tab_fact->resizeRowsToContents();
    ui->le_client->clear();
    ui->le_client->addItems(Ftemp.recherche_client());
    notif m("Facture","Facture Tri??");
    m.afficher();

}

void MainWindow::on_supp_clicked()
{
    QString id_f= ui->supr_box->currentText();
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "Supprimer", "Etes vous sur de supprimer cette facture?",
                                    QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes) {
          bool test=Ftemp.supprimer(id_f);
          if(test)
          {
              ui->supr_box->clear();
              ui->supr_box->addItems(Ftemp.recherche_id());
              ui->tab_fact->setModel(Ftemp.afficher());
              ui->le_client->clear();
              ui->le_client->addItems(Ftemp.recherche_client());


              notif m("Facture","Facture Supprim??");
              m.afficher();
          }
      }

}

void MainWindow::on_pb_modifier_clicked()
{
    QString id_f = ui->modif_box->currentText();
    QDateTime date_f = ui->modif_date_f_box->dateTime();
    QString ttc_f = ui->modif_ttc_f->text();
    QString mode_f = ui->modif_le_mode_f->currentText();
    QString nom_c = ui->modif_le_client->currentText();

    Facture ff;
    bool test=ff.modifier(id_f,date_f,ttc_f,mode_f,nom_c);

    if(test)
    {
        ui->modif_box->clear();
        ui->modif_box->addItems(Ftemp.recherche_id());
        ui->le_client->clear();
        ui->le_client->addItems(Ftemp.recherche_client());
        ui->tab_fact->setModel(Ftemp.afficher());
        notif m("Facture","Facture Modifi??");
        m.afficher();
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modification echou??"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
    Facture a;
    ui->tab_fact->setModel(Ftemp.rechercher(arg1));

}

void MainWindow::on_pdf_clicked()
{
    QString strStream;
            QTextStream out(&strStream);


    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);
    const int rowCount = ui->tab_fact->model()->rowCount();
    const int columnCount = ui->tab_fact->model()->columnCount();
    QString TT = QDate::currentDate().toString("yyyy/MM/dd");
    out <<"<html>\n"
          "<head>\n"
           "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        << "<title>ERP - FACTURES LIST<title>\n "
        << "</head>\n"
        "<body bgcolor=#ffffff link=#5000A0>\n"
        "<h1 style=\"text-align: center;\"><strong> LISTE DES Factures </strong></h1>"
        "<h5 style=\"text-align: center;\">Le : "+TT+"</h5>"
        "<br>\n"
        "<table style=\"text-align: center; font-size: 12;\" border=1>\n "
          "</br> </br>";
    // headers
    out << "<thead><tr bgcolor=#d6e5ff>";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tab_fact->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tab_fact->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tab_fact->isColumnHidden(column)) {
                QString data =ui->tab_fact->model()->data(ui->tab_fact->model()->index(row, column)).toString().simplified();
                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }
    out <<  "</table>\n"
        "</body>\n"
        "</html>\n";

    QTextDocument doc;
    doc.setHtml(strStream);
    doc.print(&printer);
}

void MainWindow::on_impr_clicked()
{
    QPrinter printer;
            QPrintDialog *printDialog = new QPrintDialog(&printer, this);
            printDialog->setWindowTitle("Imprimer Document");
            printDialog->exec();

            QPropertyAnimation *animationimprimerp;
            animationimprimerp = new QPropertyAnimation(ui->impr,"geometry");
            animationimprimerp->setDuration(1000);
            animationimprimerp->setStartValue(QRect(690,20,141,51));
            animationimprimerp->setEndValue(QRect(680,20,200,51));
            animationimprimerp->setEasingCurve(QEasingCurve::InOutQuint);
            animationimprimerp->start(QPropertyAnimation::DeleteWhenStopped);

}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    ui->tab_fact->setModel(Ftemp.afficher());
    ui->modif_box->clear();
    ui->modif_box->addItems(Ftemp.recherche_id());
    ui->supr_box->clear();
    ui->supr_box->addItems(Ftemp.recherche_id());
    ui->le_client->clear();
    ui->le_client->addItems(Ftemp.recherche_client());
    ui->modif_le_client->clear();
    ui->modif_le_client->addItems(Ftemp.recherche_idclient());
    ui->produit_inclus->clear();
    ui->produit_inclus->addItems(Etemp.recherche_produit());
    ui->modif_produit_inclus->clear();
    ui->modif_produit_inclus->addItems(Etemp.recherche_produit());

    /**************************************************************************************/
    QSqlQuery qry;
    QString resultt;
    qry.prepare("SELECT NOM_C FROM CLIENTS WHERE ID_CLIENT=:a ");
    qry.bindValue(":a",ui->modif_le_client->currentText());
    qry.exec();
    while(qry.next()){
   resultt=qry.value(0).toString();
    }
    /**************************************************************************************/
    ui->Lb_client->clear();
    ui->Lb_client->setText(resultt);

    /**************************************************************************************/
    ui->le_id_f->setText(Ftemp.remplir());
    /**************************************************************************************/
    /**************************************************************************************/
    QSqlQuery y;
    QString rr;
    y.prepare("SELECT MODE_P_F FROM FACTURES WHERE ID_F=:waaa ");
    y.bindValue(":waaa",ui->modif_box->currentText());
    y.exec();
    while(y.next()){
   rr=y.value(0).toString();
    }
    ui->modif_le_mode_f->setCurrentText(rr);
    /**************************************************************************************/
    /**************************************************************************************/
    QDateTime dat;
    QSqlQuery yy;
    yy.prepare("SELECT DATE_F FROM FACTURES WHERE ID_F=:waaa ");
    yy.bindValue(":waaa",ui->modif_box->currentText());
    yy.exec();
    while(yy.next()){
   dat=yy.value(0).toDateTime();
    }
   ui->modif_date_f_box->setDateTime(dat);
   /**************************************************************************************/
   /**************************************************************************************/
   QString ttc_ff;
   QSqlQuery qqr;
   qqr.prepare("SELECT TTC_F FROM FACTURES WHERE ID_F=:waaa ");
   qqr.bindValue(":waaa",ui->modif_box->currentText());
   qqr.exec();
   while(qqr.next()){
  ttc_ff=qqr.value(0).toString();
   }
  ui->modif_ttc_f->setText(ttc_ff);
  /**************************************************************************************/
QString infos;
infos = "Client : "+Ftemp.search_nom_c(ui->supr_box->currentText())+" | Mode de paiement : "+Ftemp.mode_pp(ui->supr_box->currentText())+" | Date : "+Ftemp.date_ff(ui->supr_box->currentText())+" | Total TTC : "+Ftemp.total_ttc(ui->supr_box->currentText())+" DT";
ui->infos->setText(infos);


/*************************************************************************************/
Facture F;
F.stat(ui->widget);




}

void MainWindow::on_modif_box_currentTextChanged(const QString &arg1)
{
ui->modif_box->currentText();
    ui->tab_fact->setModel(Ftemp.afficher());
    /**************************************************************************************/
    QSqlQuery qr;
    QString resu;
    qr.prepare("SELECT ID_C FROM factures WHERE id_f=:waa");
    qr.bindValue(":waa",ui->modif_box->currentText());
    qr.exec();
    while(qr.next()){
   resu=qr.value(0).toString();
    }

    ui->modif_le_client->setCurrentText(resu);

    /**************************************************************************************/
    /**************************************************************************************/
    QSqlQuery qry;
    QString resultt;
    qry.prepare("SELECT NOM_C FROM CLIENTS WHERE ID_CLIENT=:a ");
    qry.bindValue(":a",ui->modif_le_client->currentText());
    qry.exec();
    while(qry.next()){
   resultt=qry.value(0).toString();
    }
    /**************************************************************************************/
    ui->Lb_client->clear();
 ui->Lb_client->setText(resultt);
 /**************************************************************************************/
 QSqlQuery y;
 QString rr;
 y.prepare("SELECT MODE_P_F FROM FACTURES WHERE ID_F=:waaa ");
 y.bindValue(":waaa",ui->modif_box->currentText());
 y.exec();
 while(y.next()){
rr=y.value(0).toString();
 }
 ui->modif_le_mode_f->setCurrentText(rr);
 /**************************************************************************************/
 /**************************************************************************************/
 QDateTime dat;
 QSqlQuery yy;
 yy.prepare("SELECT DATE_F FROM FACTURES WHERE ID_F=:waaa ");
 yy.bindValue(":waaa",ui->modif_box->currentText());
 yy.exec();
 while(yy.next()){
dat=yy.value(0).toDateTime();
 }
ui->modif_date_f_box->setDateTime(dat);
/**************************************************************************************/
/**************************************************************************************/
QString ttc_ff;
QSqlQuery qqr;
qqr.prepare("SELECT TTC_F FROM FACTURES WHERE ID_F=:waaa ");
qqr.bindValue(":waaa",ui->modif_box->currentText());
qqr.exec();
while(qqr.next()){
ttc_ff=qqr.value(0).toString();
}
ui->modif_ttc_f->setText(ttc_ff);
/**************************************************************************************/

}

void MainWindow::on_supr_box_currentIndexChanged(int index)
{
    ui->tab_fact->setModel(Ftemp.afficher());

}

void MainWindow::on_pushButton_2_clicked()
{
    QVariant id_ff = ui->tab_fact->model()->data(ui->tab_fact->selectionModel()->currentIndex(),Qt::DisplayRole);
    QString idd = id_ff.toString();
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "Supprimer", "Etes vous sur de supprimer cette facture?",
                                    QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes) {
          bool test=Ftemp.supprimer(idd);
          if(test)
          {
              ui->supr_box->clear();
              ui->supr_box->addItems(Ftemp.recherche_id());
              ui->le_client->clear();
              ui->le_client->addItems(Ftemp.recherche_client());
              ui->tab_fact->setModel(Ftemp.afficher());
              notif m("Facture","Facture Supprim??");
              m.afficher();

          }
      }

    ui->tab_fact->setModel(Ftemp.afficher());
    ui->modif_box->clear();
    ui->modif_box->addItems(Ftemp.recherche_id());
    ui->supr_box->clear();
    ui->supr_box->addItems(Ftemp.recherche_id());
    ui->le_client->clear();
    ui->le_client->addItems(Ftemp.recherche_client());


}

void MainWindow::on_pushButton_3_clicked()
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
                          QObject::tr("vehicule ajout??.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
      //  ui->stackedWidget->setCurrentIndex(0);

        QString objet="AJOUT VEHICULE";
        QString message=" Votre vehicule a ??t?? ajout?? avec succ??s" ;


        /************************************SMTP******************************************************/
                        Smtp* smtp = new Smtp("smarttt.shop@gmail.com","", "smtp.gmail.com",465);
                        connect (smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
                        smtp->sendMail("smarttt.shop@gmail.com", "ibrahim.benrayana@esprit.tn" , objet,message);
        /***********************************************************************************************/

    }
     //ui->stackedWidget->setCurrentIndex(1);
    ui->tableView_vehicule->setModel(tmpveh.afficher_veh());


}

void MainWindow::on_modif_le_client_activated(const QString &arg1)
{
    /**************************************************************************************/
    QSqlQuery qry;
    QString resultt;
    qry.prepare("SELECT NOM_C FROM CLIENTS WHERE ID_CLIENT=:a ");
    qry.bindValue(":a",ui->modif_le_client->currentText());
    qry.exec();
    while(qry.next()){
   resultt=qry.value(0).toString();
    }
    /**************************************************************************************/
    ui->Lb_client->clear();
 ui->Lb_client->setText(resultt);
}

void MainWindow::on_modif_box_currentIndexChanged(const QString &arg1)
{
    QSqlQuery query;
    query.prepare("select NOM_C from CLIENTS");
    query.exec();
    QString list;
    while(query.next()){
        list=query.value(0).toString();
    }


}

void MainWindow::on_supr_box_currentTextChanged(const QString &arg1)
{
    QString infos;
    infos = "Client : "+Ftemp.search_nom_c(ui->supr_box->currentText())+" | Mode de paiement : "+Ftemp.mode_pp(ui->supr_box->currentText())+" | Date : "+Ftemp.date_ff(ui->supr_box->currentText())+" | Total TTC : "+Ftemp.total_ttc(ui->supr_box->currentText())+" DT";
    ui->infos->setText(infos);

}

/*********************************************************************************************************************************/

void MainWindow::on_commandLinkButton_clicked()
{
    ui->supr_box->clear();
    ui->supr_box->addItems(Ftemp.recherche_id());
    ui->stackedWidget->setCurrentIndex(2);
    ui->tab_fact->setModel(Ftemp.afficher());

}

void MainWindow::on_commandLinkButton_2_clicked()
{
    ui->tab_ev->setModel(Etemp.afficher_ev());
    ui->stackedWidget->setCurrentIndex(3);

}

void MainWindow::on_ajout_ev_clicked()
{

    /**************************************************************************************/
    QSqlQuery query;
    QString result;
    query.prepare("SELECT ID_P FROM PRODUITS WHERE NOM_P=:a ");
    query.bindValue(":a",ui->produit_inclus->currentText());
    query.exec();
    while(query.next()){
   result=query.value(0).toString();
    }
    /**************************************************************************************/

    QString id_ev=ui->id_ev->text();
    QString nom_ev=ui->nom_ev->text();
    QDateTime dat_deb=ui->dat_deb->dateTime();
    QDateTime dat_fin=ui->dat_fin->dateTime();

    Evenement E(id_ev,nom_ev,dat_deb,dat_fin,result);

    bool test=E.ajouter_ev();
    ui->tab_ev->setModel(Etemp.afficher_ev());

    if(test){
        int i=0 ;
        for(i=0;i<100;i=i+0.1){
            i++;
            ui->progressBar->setValue(i);
        }
        notif m("Evenement","Evenement Ajout??");
        m.afficher();
        foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
                     le->clear();}
                QFile file("C:/Users/waelk/OneDrive/Bureau/C++/PROJET/ProjetFinal/Histo/historique.txt");
                if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                    return;
                QTextStream cout(&file);
                QString d_info = QDateTime::currentDateTime().toString();
                QString message2=d_info+" - Un ??v??nement a ??t?? ajout?? avec la r??f??rence "+id_ev+"\n";
                cout << message2;


        if(ui->checkBox->isChecked()){
                /************************************SMTP******************************************************/
                        QString objet="NOUVELLE EVENEMENT AJOUTE !";
                                QString message="IDEvenement:"+ui->id_ev->text()+"Nomd'evenement:"+ui->nom_ev->text() ;
                                Smtp* smtp = new Smtp("wael.ksila@esprit.tn","", "smtp.gmail.com",465);
                                connect (smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

                                QString pro=ui->produit_inclus->currentText();
                                QString okk=pro+" En Solde";
                                QString o=okk+".";
                                smtp->sendMail("wael.ksila@esprit.tn", "waelksila97@gmail.com" , objet,o);

                                /********/
                               /* QSqlQuery query;
                                query.prepare("SELECT EMAIL_C FROM CLIENTS");
                                query.exec();
                                QStringList list;
                                QString e;
                                while(query.next()){
                                    int i=0;
                                       list.append(query.value(0).toString());
                                       e=list.value(i);
                                       QMessageBox::information(nullptr,e,e);

                                       smtp->sendMail("wael.ksila@esprit.tn", e , objet,o);
                                     QTime dieTime= QTime::currentTime().addSecs(7);
                                       while (QTime::currentTime() < dieTime)
                                           QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

                                    i++;
                                }*/
                /**********************************************************************************************/

                 QMessageBox::information(nullptr,"Client inform??\n","Mail envoy?? a vos clients\n");


            }




    }else{
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                              QObject::tr("Ajout non effectu??\n"
                                 "Click Cancel to exit."),QMessageBox::Cancel);

    }
    ui->produit_inclus->clear();
    ui->produit_inclus->addItems(Etemp.recherche_produit());
    ui->supr_ev->clear();
    ui->supr_ev->addItems(Etemp.recherche_id_ev());
    ui->modif_id_ev->clear();
    ui->modif_id_ev->addItems(Etemp.recherche_id_ev());
    ui->modif_produit_inclus->clear();
    ui->modif_produit_inclus->addItems(Etemp.recherche_produit());


}
void MainWindow::readfile(){
    QString filename="C:/Users/waelk/OneDrive/Bureau/C++/PROJET/ProjetFinal/Histo/historique.txt";
    QFile file(filename);
    if(!file.exists()){
        qDebug() << "NO existe el archivo "<<filename;
    }else{
        qDebug() << filename<<" encontrado...";
    }
    QString line;
    ui->textHisto->clear();
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);
        while (!stream.atEnd()){
            line = stream.readLine();
            ui->textHisto->setText(ui->textHisto->toPlainText()+line+"\n");
            qDebug() << "linea: "<<line;
        }
    }
    file.close();
}


void MainWindow::on_tabWidget_2_currentChanged(int index)
{
    ui->progressBar->setValue(0);
    ui->produit_inclus->clear();
    ui->produit_inclus->addItems(Etemp.recherche_produit());
    ui->tab_ev->setModel(Etemp.afficher_ev());
    ui->supr_ev->clear();
    ui->supr_ev->addItems(Etemp.recherche_id_ev());
    ui->modif_id_ev->clear();
    ui->modif_id_ev->addItems(Etemp.recherche_id_ev());
    ui->modif_produit_inclus->clear();
    ui->modif_produit_inclus->addItems(Etemp.recherche_produit());
    ui->id_ev->setText(Etemp.remplir_ev());
    readfile();


}

void MainWindow::on_supp_ev_clicked()
{
    QString id_ev= ui->supr_ev->currentText();
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "Supprimer", "Etes vous sur de supprimer cette evenement ?",
                                    QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes) {
          bool test=Etemp.supprimer_ev(id_ev);
          if(test)
          {
              int i=0 ;
              for(i=0;i<100;i=i+0.1){
                  i++;
                  ui->progressBar->setValue(i);
              }

              ui->supr_ev->clear();
              ui->supr_ev->addItems(Etemp.recherche_id_ev());
              ui->tab_ev->setModel(Etemp.afficher_ev());
              notif m("Evenement","Evenement Supprim??");
              m.afficher();
              foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
                           le->clear();}
                      QFile file("C:/Users/waelk/OneDrive/Bureau/C++/PROJET/ProjetFinal/Histo/historique.txt");
                      if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                          return;
                      QTextStream cout(&file);
                      QString d_info = QDateTime::currentDateTime().toString();
                      QString message2=d_info+" - Un ??v??nement a ??t?? supprim?? avec la r??f??rence "+id_ev+"\n";
                      cout << message2;


          }
      }else{
          QMessageBox::information(nullptr,"Suppression","Evenement non supprim?? !");

      }

}

void MainWindow::on_supp_ev_2_clicked()
{
    QVariant id_ff = ui->tab_ev->model()->data(ui->tab_ev->selectionModel()->currentIndex(),Qt::DisplayRole);
    QString id_ev = id_ff.toString();
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Supprimer", "Etes vous sur de supprimer cette evenement ?",
                                    QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes) {
          bool test=Etemp.supprimer_ev(id_ev);
          if(test)
          {
              int i=0 ;
              for(i=0;i<100;i=i+0.1){
                  i++;
                  ui->progressBar->setValue(i);
              }
              ui->supr_ev->clear();
              ui->supr_ev->addItems(Etemp.recherche_id_ev());
              ui->tab_ev->setModel(Etemp.afficher_ev());
              notif m("Evenement","Evenement Supprim??");
              m.afficher();
              foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
                           le->clear();}
                      QFile file("C:/Users/waelk/OneDrive/Bureau/C++/PROJET/ProjetFinal/Histo/historique.txt");
                      if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                          return;
                      QTextStream cout(&file);
                      QString d_info = QDateTime::currentDateTime().toString();
                      QString message2=d_info+" - Un ??v??nement a ??t?? supprim?? avec la r??f??rence "+id_ev+"\n";
                      cout << message2;
          }
      }else{
          QMessageBox::information(nullptr,"Suppression","Evenement non supprim?? !");

      }
}

void MainWindow::on_pdf_ev_clicked()
{
    QString strStream;
            QTextStream out(&strStream);


    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }
    int i=0 ;
    for(i=0;i<100;i=i+0.1){
        i++;
        ui->progressBar->setValue(i);
    }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);
    const int rowCount = ui->tab_ev->model()->rowCount();
    const int columnCount = ui->tab_ev->model()->columnCount();
    QString TT = QDate::currentDate().toString("yyyy/MM/dd");
    out <<"<html>\n"
          "<head>\n"
           "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        << "<title>ERP - EVENEMENTS LIST<title>\n "
        << "</head>\n"
        "<body bgcolor=#ffffff link=#5000A0>\n"
        "<h1 style=\"text-align: center;\"><strong> LISTE DES EVENEMENTS </strong></h1>"
        "<h5 style=\"text-align: center;\">Le : "+TT+"</h5>"
        "<br>\n"
        "<table style=\"text-align: center; font-size: 12;\" border=1>\n "
          "</br> </br>";
    // headers
    out << "<thead><tr bgcolor=#d6e5ff>";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tab_ev->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tab_ev->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tab_ev->isColumnHidden(column)) {
                QString data =ui->tab_ev->model()->data(ui->tab_ev->model()->index(row, column)).toString().simplified();
                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }
    out <<  "</table>\n"
        "</body>\n"
        "</html>\n";

    QTextDocument doc;
    doc.setHtml(strStream);
    doc.print(&printer);

}

void MainWindow::on_impr_ev_clicked()
{
    QPrinter printer;
            QPrintDialog *printDialog = new QPrintDialog(&printer, this);
            printDialog->setWindowTitle("Imprimer Document");
            printDialog->exec();

            QPropertyAnimation *animationimprimerp;
            animationimprimerp = new QPropertyAnimation(ui->impr,"geometry");
            animationimprimerp->setDuration(1000);
            animationimprimerp->setStartValue(QRect(690,20,141,51));
            animationimprimerp->setEndValue(QRect(680,20,200,51));
            animationimprimerp->setEasingCurve(QEasingCurve::InOutQuint);
            animationimprimerp->start(QPropertyAnimation::DeleteWhenStopped);

}

void MainWindow::on_tri_ev_clicked()
{
    int i=0 ;
    for(i=0;i<100;i=i+0.1){
        i++;
        ui->progressBar->setValue(i);
    }
    ui->tab_ev->setModel(Etemp.tri_ev());
    ui->tab_ev->resizeRowsToContents();
    notif m("Evenement","Evenement Tri??");
    m.afficher();

}

void MainWindow::on_recherche_ev_textEdited(const QString &arg1)
{
    ui->tab_ev->setModel(Etemp.rechercher_ev(arg1));

}

void MainWindow::on_modif_ev_clicked()
{
    /**************************************************************************************/
    QSqlQuery query;
    QString result;
    query.prepare("SELECT ID_P FROM PRODUITS WHERE NOM_P=:a ");
    query.bindValue(":a",ui->modif_produit_inclus->currentText());
    query.exec();
    while(query.next()){
   result=query.value(0).toString();
    }
    /**************************************************************************************/

    QString id_ev = ui->modif_id_ev->currentText();
    QString nom_ev = ui->modif_titre_ev->text();
    QDateTime dat_deb = ui->modif_dat_deb->dateTime();
    QDateTime dat_fin = ui->modif_dat_fin->dateTime();

    Evenement ff;
    bool test=ff.modifier_ev(id_ev,nom_ev,dat_deb,dat_fin,result);

    if(test)
    {
        int i=0 ;
        for(i=0;i<100;i=i+0.1){
            i++;
            ui->progressBar->setValue(i);
        }

        ui->modif_produit_inclus->clear();
        ui->modif_produit_inclus->addItems(Etemp.recherche_id_ev());
        ui->produit_inclus->clear();
        ui->produit_inclus->addItems(Etemp.recherche_id_ev());
        ui->tab_ev->setModel(Etemp.afficher_ev());
        notif m("Evenement","Evenement Modifi??");
        m.afficher();
        foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
                     le->clear();}
                QFile file("C:/Users/waelk/OneDrive/Bureau/C++/PROJET/ProjetFinal/Histo/historique.txt");
                if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                    return;
                QTextStream cout(&file);
                QString d_info = QDateTime::currentDateTime().toString();
                QString message2=d_info+" - Un ??v??nement a ??t?? modifi?? avec la r??f??rence "+id_ev+"\n";
                cout << message2;


    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modification echou??"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_pushButton_5_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Exportation en fichier Excel"), qApp->applicationDirPath (),
                                                                tr("Fichiers d'extension Excel (*.xls)"));
                if (fileName.isEmpty())
                    return;

                ExportExcelObject obj(fileName, "mydata", ui->tab_fact);

                // you can change the column order and
                // choose which colum to export
                obj.addField(0, "ID", "char(20)");
                obj.addField(1, "CLIENT", "char(20)");
                obj.addField(2, "TTC_F", "char(20)");
                obj.addField(3, "MODE_P_F", "char(20)");
                obj.addField(4, "ID_C", "char(20)");
                //obj.addField(5, "servespeed3", "char(20)");


                int retVal = obj.export2Excel();

                if( retVal > 0)
                {
                    QMessageBox::information(this, tr("FAIS!"),
                                             QString(tr("%1 enregistrements export??s!")).arg(retVal)
                                             );
                }
}

void MainWindow::on_pushButton_6_clicked()
{
    QString cin = ui->le_cin->text();
    QString nom = ui->lineEdit_nom_2->text();
    QString prenom = ui->lineEdit_pr->text();
    QString statue = ui->comboBox_10->currentText();


    livreur l(cin,nom,prenom,statue);
    bool test=l.ajouter_liv();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Ajouter un livreur"),
                          QObject::tr("livreur ajout??.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
      //  ui->stackedWidget->setCurrentIndex(0);

        QString objet="AJOUT LIVREUR";
        QString message=" livreur a ??t?? ajout?? avec succ??s" ;



    }

    ui->tableView_livreur->setModel(tmpliv.afficher_liv());


}

void MainWindow::on_toolButton_2_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Log out"),
                      QObject::tr("Etes-vous sure de vous deconnect???.\n"
                                  "Cliquez oui pour confirmer."), QMessageBox::Yes);

    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_toolButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_ajout_ev_2_clicked()
{
    QString objet="AJOUT DU COURRIER";
            QString message=" Votre courrier a ??t?? ajout?? avec succ??s" ;
            Smtp* smtp = new Smtp("wael.ksila@esprit.tn","", "smtp.gmail.com",465);
            connect (smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
            smtp->sendMail("wael.ksila@esprit.tn", "waelksila97@gmail.com" , objet, message);
}

void MainWindow::on_qrcode_clicked()
{

    int tabev=ui->tab_ev->currentIndex().row();
    QVariant idd=ui->tab_ev->model()->data(ui->tab_ev->model()->index(tabev,0));
    QString id= idd.toString();
    QSqlQuery qry;
    qry.prepare("select * from evenements where id_ev=:id");
    qry.bindValue(":id",id);
    qry.exec();
    QString nom,debut,fin,idp,ids;
    while(qry.next()){
        nom=qry.value(1).toString();
        debut=qry.value(2).toString();
        fin=qry.value(3).toString();
        idp=qry.value(4).toString();
    }
    ids=QString(id);
    ids="ID: "+ids+" Nom: "+nom+" Date de debut: "+debut+" Date de fin: "+fin+"ID produit : "+idp;
    QrCode qr = QrCode::encodeText(ids.toUtf8().constData(), QrCode::Ecc::HIGH);

    // Read the black & white pixels
    QImage im(qr.getSize(),qr.getSize(), QImage::Format_RGB888);
    for (int y = 0; y < qr.getSize(); y++) {
        for (int x = 0; x < qr.getSize(); x++) {
            int color = qr.getModule(x, y);  // 0 for white, 1 for black

            // You need to modify this part
            if(color==0)
                im.setPixel(x, y,qRgb(254, 254, 254));
            else
                im.setPixel(x, y,qRgb(0, 0, 0));
        }
    }
    im=im.scaled(200,200);
    ui->qrlabel->setPixmap(QPixmap::fromImage(im));
    int i=0 ;
    for(i=0;i<100;i=i+0.1){
        i++;
        ui->progressBar->setValue(i);
    }
}

void MainWindow::on_toolButton_5_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Log out"),
                      QObject::tr("Etes-vous sure de vous deconnect???.\n"
                                  "Cliquez oui pour confirmer."), QMessageBox::Yes);

    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_toolButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_actionAbout_us_triggered()
{
    QString about;
    about = "Auther :   Wael Ksila\n";
    about +="Date    :   26/04/2021\n";
    about +="(C) Gestion D'entreprise (R)\n\n";
    about +="For more information : fb.me/waellksila\n";
    QMessageBox::about(this,"About",about);
}


void MainWindow::on_lineEdit_5_textEdited(const QString &arg1)
{
    ui->tab_produit_4->setModel(P.recherche(arg1));

}

void MainWindow::on_pdff_5_clicked()
{
    QString strStream;
            QTextStream out(&strStream);


    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);
    const int rowCount = ui->tab_produit_4->model()->rowCount();
    const int columnCount = ui->tab_produit_4->model()->columnCount();
    QString TT = QDate::currentDate().toString("yyyy/MM/dd");
    out <<"<html>\n"
          "<head>\n"
           "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        << "<title>ERP - Liste des Produits<title>\n "
        << "</head>\n"
        "<body bgcolor=#ffffff link=#5000A0>\n"
        "<h1 style=\"text-align: center;\"><strong> Liste des Produits </strong></h1>"
        "<h5 style=\"text-align: center;\">Le : "+TT+"</h5>"
        "<br>\n"
        "<table style=\"text-align: center; font-size: 12;\" border=1>\n "
          "</br> </br>";
    // headers
    out << "<thead><tr bgcolor=#d6e5ff>";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tab_produit_4->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tab_produit_4->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tab_produit_4->isColumnHidden(column)) {
                QString data =ui->tab_produit_4->model()->data(ui->tab_produit_4->model()->index(row, column)).toString().simplified();
                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }
    out <<  "</table>\n"
        "</body>\n"
        "</html>\n";

    QTextDocument doc;
    doc.setHtml(strStream);
    doc.print(&printer);
}

void MainWindow::on_pushButton_18_clicked()
{
    ui->tab_produit_4->setModel(P.tri());

}

void MainWindow::on_commandLinkButton_3_clicked()
{


}

void MainWindow::on_pushButton_19_clicked()
{
    int id_P=ui->le_id_5->text().toInt();
    QString nom_P=ui->le_nom_5->text();
    QString type=ui->le_type_4->text();
    int prix=ui->le_prix_4->text().toInt();

    Produit P(id_P,nom_P,type,prix);
    bool test=P.ajouter();
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Ajout avec succes.");
        ui->tab_produit_4->setModel(P.afficher());

       }
    else
        msgBox.setText("Echec d'ajout");
    msgBox.exec();
}

void MainWindow::on_pb_modifier_5_clicked()
{
    int id_P=ui->id_mod_5->text().toInt();
       QString nom_P=ui->nom_mod_5->text();
       QString type=ui->type_mod_4->text();
       int prix=ui->prix_mod_4->text().toInt();

          Produit P2;
          bool test=P2.modifier(id_P,nom_P,type,prix);

          if(test)
          {
             ui->id_mod_5->clear();
            ui->nom_mod_5->clear();
            ui->type_mod_4->clear();
            ui->prix_mod_4->clear();
              QMessageBox::information(nullptr, QObject::tr("Modification effectue"),
                                QObject::tr("Produit modifie.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
          }
          else
              QMessageBox::critical(nullptr, QObject::tr("Modification echoue"),
                          QObject::tr("Erreur !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_produit_4->setModel(P2.afficher());
}

void MainWindow::on_tab_20_currentChanged(int index)
{
    ui->tab_produit_4->setModel(P.afficher());
    ui->supr_prod_4->clear();
    ui->supr_prod_4->addItems(P.recherche_id_produit());
    Produit P;
    P.statistic(ui->widget_5);
}

void MainWindow::on_pb_supprimer_4_clicked()
{
    Produit P1; P1.setid_P(ui->supr_prod_4->currentText().toInt());
        bool test=P1.supprimer(P1.getid_P());
        QMessageBox msgBox;

        if(test)
           { msgBox.setText("Suppression avec succes.");
            ui->tab_produit_4->setModel(P.afficher());

           }
        else if(test==false)
            msgBox.setText("Echec de suppression");
        msgBox.exec();
        ui->supr_prod_4->clear();
        ui->supr_prod_4->addItems(P.recherche_id_produit());
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_pushButton_17_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_toolButton_19_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_toolButton_17_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Log out"),
                      QObject::tr("Etes-vous sure de vous deconnect???.\n"
                                  "Cliquez oui pour confirmer."), QMessageBox::Yes);

    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_toolButton_20_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Log out"),
                      QObject::tr("Etes-vous sure de vous deconnect???.\n"
                                  "Cliquez oui pour confirmer."), QMessageBox::Yes);

    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_toolButton_16_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_pushButton_9_clicked()
{
    ui->tableView_vehicule_EN->setModel(tmpveh.ent_veh());
    this->hide();
    qApp->processEvents();
#ifdef _WIN32
    //Sleep(3000);
#else
    Kek::wait(200);
#endif

    QPixmap okno = QPixmap::grabWindow(QApplication::desktop()->winId());
    QDateTime t = QDateTime::currentDateTime();
    QString saveWhere = qApp->applicationDirPath() + QString("/Scr_%1-%2-%3-%4-%5-%6.png")
            .arg(t.date().year()).arg(t.date().month()).arg(t.date().day())
            .arg(t.time().hour()).arg(t.time().minute()).arg(t.time().second());
    QString saveAs = QFileDialog::getSaveFileName(NULL, "Save screenshot as...",
                                                  saveWhere,
                                                  "PNG Picture (*.png)",
                                                  nullptr,
                                                  QFileDialog::DontUseNativeDialog);
    if(!saveAs.isEmpty())
        okno.save(saveAs, "PNG");

    this->show();

}

void MainWindow::on_pushButton_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_toolButton_25_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_toolButton_26_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Log out"),
                      QObject::tr("Etes-vous sure de vous deconnect???.\n"
                                  "Cliquez oui pour confirmer."), QMessageBox::Yes);

    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pdff_clicked()
{
    QString strStream;
            QTextStream out(&strStream);


    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);
    const int rowCount = ui->tab_catgorie->model()->rowCount();
    const int columnCount = ui->tab_catgorie->model()->columnCount();
    QString TT = QDate::currentDate().toString("yyyy/MM/dd");
    out <<"<html>\n"
          "<head>\n"
           "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        << "<title>ERP - Liste des Categories<title>\n "
        << "</head>\n"
        "<body bgcolor=#ffffff link=#5000A0>\n"
        "<h1 style=\"text-align: center;\"><strong> Liste des Categories </strong></h1>"
        "<h5 style=\"text-align: center;\">Le : "+TT+"</h5>"
        "<br>\n"
        "<table style=\"text-align: center; font-size: 12;\" border=1>\n "
          "</br> </br>";
    // headers
    out << "<thead><tr bgcolor=#d6e5ff>";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tab_catgorie->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tab_catgorie->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tab_catgorie->isColumnHidden(column)) {
                QString data =ui->tab_catgorie->model()->data(ui->tab_catgorie->model()->index(row, column)).toString().simplified();
                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }
    out <<  "</table>\n"
        "</body>\n"
        "</html>\n";

    QTextDocument doc;
    doc.setHtml(strStream);
    doc.print(&printer);
}

void MainWindow::on_tabWidget_3_currentChanged(int index)
{
    ui->tab_catgorie->setModel(C.afficher_cat());
    ui->supr_cat->clear();
    ui->supr_cat->addItems(C.recherche_id_categorie());

}

void MainWindow::on_categorie_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    ui->tab_catgorie->setModel(C.afficher_cat());
    ui->supr_cat->clear();
    ui->supr_cat->addItems(C.recherche_id_categorie());


}

void MainWindow::on_pushButton_5_cat_clicked()
{
    ui->tab_catgorie->setModel(C.tri_cat());

}

void MainWindow::on_lineEdit_2_cat_textEdited(const QString &arg1)
{
    ui->tab_catgorie->setModel(C.recherche_cat(arg1));

}

void MainWindow::on_pb_ajouter_cat_clicked()
{
    int ID_cat=ui->le_id_2->text().toInt();
    QString Nom_cat=ui->le_nom_2->text();

    Categorie C(ID_cat,Nom_cat);
    bool test=C.ajouter_cat();
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Ajout avec succes.");
        ui->tab_catgorie->setModel(C.afficher_cat());
       }
    else
        msgBox.setText("Echec d'ajout");
    msgBox.exec();
}

void MainWindow::on_pb_modifier_2_cat_clicked()
{
    int ID_cat=ui->id_mod_2->text().toInt();
    QString Nom_cat=ui->nom_mod_2->text();

       Categorie C2;
       bool test=C2.modifier_cat(ID_cat,Nom_cat);

       if(test)
       {
           QMessageBox::information(nullptr, QObject::tr("Modification effectue"),
                             QObject::tr("Categorie modifie.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
       }
       else
           QMessageBox::critical(nullptr, QObject::tr("Modification echoue"),
                       QObject::tr("Erreur !.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
     ui->tab_catgorie->setModel(C2.afficher_cat());

}

void MainWindow::on_pb_supprimer_2_cat_clicked()
{
    Categorie C1; C1.setID_cat(ui->supr_cat->currentText().toInt());
    bool test=C1.supprimer_cat(C1.getID_cat());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Suppression avec succes.");
        ui->tab_catgorie->setModel(C.afficher_cat());

       }
    else if(test==false)
        msgBox.setText("Echec de suppression");
    msgBox.exec();
    ui->supr_cat->clear();
    ui->supr_cat->addItems(C.recherche_id_categorie());
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_produit_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    Produit P;
    P.statistic(ui->widget_5);
    ui->tab_produit_4->setModel(P.afficher());  // afficher produit

}

void MainWindow::on_facture_clicked()
{
    ui->supr_box->clear();
    ui->supr_box->addItems(Ftemp.recherche_id());
    ui->stackedWidget->setCurrentIndex(2);
    ui->tab_fact->setModel(Ftemp.afficher());

}

void MainWindow::on_categorie_2_clicked()
{
    ui->tab_ev->setModel(Etemp.afficher_ev());
    ui->stackedWidget->setCurrentIndex(3);

}

void MainWindow::on_categorie_6_clicked()
{

}

void MainWindow::on_stock_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);

}

void MainWindow::on_pushButton_22_clicked()
{
    tabs.pdf();

}

void MainWindow::on_pushButton_ajouter_clicked()
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
                                                      QObject::tr("produit ajout?? .\n"
                                                                  "Click Cancel to exit ."),QMessageBox::Cancel);
                      }
                 else
                 {
                 QMessageBox::critical(nullptr,QObject::tr("Ajouter produit"),
                                                  QObject::tr("ERooR .\n"
                                                              "Click Cancel to exit ."),QMessageBox::Cancel);
                 }
}

void MainWindow::on_pushButton_modifier_clicked()
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
                                                        QObject::tr("stock Modifi?? .\n"
                                                                    "Click Cancel to exit ."),QMessageBox::Cancel);

                            }
                       else
                       {
                       QMessageBox::critical(nullptr,QObject::tr("Modifier stock"),
                                                        QObject::tr("stock Modifi?? .\n"
                                                                    "Click Cancel to exit ."),QMessageBox::Cancel);
                          }
}

void MainWindow::on_pushButton_16_clicked()
{
    bool test =tabs.supprimerstock(ui->comboBox_2->currentText());
    if(test)
       {
        QMessageBox::information(nullptr,QObject::tr("Supprimer stock"),
                                         QObject::tr("stock supprim?? .\n"
                                                     "Click Cancel to exit ."),QMessageBox::Cancel);

       }
    else
    {
        QMessageBox::information(nullptr,QObject::tr("Supprimer stock"),
                                         QObject::tr("Erreur .\n"
                                                     "Click Cancel to exit ."),QMessageBox::Cancel);
       }
}

void MainWindow::on_pushButton_17z_clicked()
{
    ui->tableView->setModel(tabs.afficherstock());
    ui->comboBox_2->setModel(STOCK::afficher1());

}

void MainWindow::on_comboBox_2_currentTextChanged(const QString &arg1)
{
    ui->comboBox_2->currentText();

}

void MainWindow::on_pushButton_23_clicked()
{
    STOCK * v = new STOCK(ui->lineEdit_nomp->text(),ui->lineEdit_quantite->text(),ui->lineEdit_referencep->text(),ui->lineEdit_noms->text(),ui->lineEdit_references->text());
    if(ui->radioButton->isChecked()){
       ui->tableView->setModel(v->sort1());
    }
    if(ui->radioButton_2->isChecked()){
        ui->tableView->setModel(v->sort2());
    }
    delete v;
}

void MainWindow::on_comboBox_3_currentIndexChanged(const QString &arg1)
{
    ui->comboBox_3->currentText();

}

void MainWindow::on_pushButton_25_clicked()
{
    ui->comboBox_3->setModel(STOCK::afficher1());

}

void MainWindow::on_pushButton_recherche_clicked()
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

void MainWindow::on_qrcode_3_clicked()
{
    int tabev=ui->tableView->currentIndex().row();
    QVariant idd=ui->tableView->model()->data(ui->tableView->model()->index(tabev,0));
    QString nomp= idd.toString();
    QSqlQuery qry;
    qry.prepare("select * from STOCK where nomp=:nomp");
    qry.bindValue(":nomp",nomp);
    qry.exec();
    QString quantite,referencep,noms,references,nomps;
    while(qry.next()){
        quantite=qry.value(1).toString();
        referencep=qry.value(2).toString();
        noms=qry.value(3).toString();
        references=qry.value(4).toString();
    }
    nomps=QString(nomp);
    nomps="Nomps: "+nomps+" Quantite: "+quantite+" Referencep: "+referencep+" Noms: "+noms+" References : "+references;
    QrCode qr = QrCode::encodeText(nomps.toUtf8().constData(), QrCode::Ecc::HIGH);

    // Read the black & white pixels
    QImage im(qr.getSize(),qr.getSize(), QImage::Format_RGB888);
    for (int y = 0; y < qr.getSize(); y++) {
        for (int x = 0; x < qr.getSize(); x++) {
            int color = qr.getModule(x, y);  // 0 for white, 1 for black

            // You need to modify this part
            if(color==0)
                im.setPixel(x, y,qRgb(254, 254, 254));
            else
                im.setPixel(x, y,qRgb(0, 0, 0));
        }
    }
    im=im.scaled(200,200);
    ui->qrlabel_3->setPixmap(QPixmap::fromImage(im));
    int i=0 ;
    for(i=0;i<100;i=i+0.1){
        i++;
      //  ui->progressBar->setValue(i);
    }
}

void MainWindow::on_pushButton_24_clicked()
{
    QTableView *table;
               table = ui->tableView;

               QString filters("CSV files (.csv);;All files (.*)");
              // QString defaultFilter("CSV files (*.csv)");
               QString defaultFilter("Classeur Excel (*.xlsx)");
               QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                  filters, &defaultFilter);
               QFile file(fileName);

               QAbstractItemModel *model =  table->model();
               if (file.open(QFile::WriteOnly | QFile::Truncate)) {
                   QTextStream data(&file);
                   QStringList strList;
                   for (int i = 0; i < model->columnCount(); i++) {
                       if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                           strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                       else
                           strList.append("");
                   }
                   data << strList.join(";") << "\n";
                   for (int i = 0; i < model->rowCount(); i++) {
                       strList.clear();
                       for (int j = 0; j < model->columnCount(); j++) {

                           if (model->data(model->index(i, j)).toString().length() > 0)
                               strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                           else
                               strList.append("");
                       }
                       data << strList.join(";") + "\n";
                   }
                   file.close();
                   QMessageBox::information(this,"Exporter To Excel","Exporte En Excel Avec Succ??es ");
               }
}

void MainWindow::on_pushButton_15_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_toolButton_34_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_toolButton_35_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Log out"),
                      QObject::tr("Etes-vous sure de vous deconnect???.\n"
                                  "Cliquez oui pour confirmer."), QMessageBox::Yes);

    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_categorie_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);

}

void MainWindow::on_toolButton_38_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Log out"),
                      QObject::tr("Etes-vous sure de vous deconnect???.\n"
                                  "Cliquez oui pour confirmer."), QMessageBox::Yes);

    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_toolButton_37_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_pushButton_ajouterd_clicked()
{
    depot d(ui->lineEdit_nomd->text(),ui->lineEdit_adresse->text(),ui->lineEdit_adresse_3->text());
    bool test=d.ajouterdepot();
    if(test)
    {      ui->tableView_2->setModel(tabd.afficherdepot());//actualisation

        QMessageBox::information(nullptr,QObject::tr("Ajouter produit"),
                                             QObject::tr("produit ajout?? .\n"
                                                         "Click Cancel to exit ."),QMessageBox::Cancel);
             }
        else
        {
        QMessageBox::critical(nullptr,QObject::tr("Ajouter produit"),
                                         QObject::tr("ERooR .\n"
                                                     "Click Cancel to exit ."),QMessageBox::Cancel);
        }
}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    ui->comboBox->currentText();

}

void MainWindow::on_pushButton_act_clicked()
{
    ui->tableView_2->setModel(tabd.afficherdepot());
    ui->comboBox->setModel(depot::afficher1());

}

void MainWindow::on_pushButton_supprimerd_clicked()
{
    bool test =tabd.supprimerdepot(ui->comboBox->currentText());
    if(test)
       {  ui->tableView_2->setModel(tabd.afficherdepot());
        QMessageBox::information(nullptr,QObject::tr("Supprimer depot"),
                                         QObject::tr("depot supprim?? .\n"
                                                     "Click Cancel to exit ."),QMessageBox::Cancel);

       }
    else
    {
        QMessageBox::information(nullptr,QObject::tr("Supprimer depot"),
                                         QObject::tr("Erreur .\n"
                                                     "Click Cancel to exit ."),QMessageBox::Cancel);
       }
}

void MainWindow::on_pushButton_recherche_4_clicked()
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

void MainWindow::on_pushButton_30_clicked()
{
    ui->comboBox_4->setModel(depot::afficher1());

}

void MainWindow::on_pushButton_29_clicked()
{
    bool test=tabd.modifierdepot(ui->comboBox_4->currentText(),ui->lineEdit_adresse_2->text(),ui->lineEdit_adresse_4->text());
                 if (test)
                         {
                          ui->tableView_2->setModel(tabd.afficherdepot());//actualisation

                     QMessageBox::information(nullptr,QObject::tr("Modifier depot"),
                                                      QObject::tr("depot Modifi?? .\n"
                                                                  "Click Cancel to exit ."),QMessageBox::Cancel);

                          }
                     else
                     {
                     QMessageBox::critical(nullptr,QObject::tr("Modifier depot"),
                                                      QObject::tr("depot Modifi?? .\n"
                                                                  "Click Cancel to exit ."),QMessageBox::Cancel);
                        }
}

void MainWindow::on_pushButton_26_clicked()
{
    depot* d= new depot(ui->lineEdit_nomd->text(),ui->lineEdit_adresse->text(),ui->lineEdit_adresse_3->text());
    ui->tableView_2->setModel(d->sort1());

}

void MainWindow::on_pushButton_27_clicked()
{
    tabd.pdf();

}

void MainWindow::on_pushButton_28_clicked()
{
    QPrinter  printer;
            printer.setPrinterName("test");
            QPrintDialog dialog(&printer,this);
            if (dialog.exec()==QDialog::Rejected) return;
}


void MainWindow::on_client_clicked()
{
    CLIENT r;
    r.afficherclient(ui);
    ui->stackedWidget->setCurrentIndex(8);

}

void MainWindow::on_pushButton_31_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_toolButton_40_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_toolButton_41_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Log out"),
                      QObject::tr("Etes-vous sure de vous deconnect???.\n"
                                  "Cliquez oui pour confirmer."), QMessageBox::Yes);

    ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::showTime2()
{
    QTime time=QTime::currentTime();
    QString time_text=time.toString("hh : mm : ss");
    ui->DigitalClock->setText(time_text);
}

void MainWindow::on_pushButton_ajouter_2_clicked()
{
    QSqlQuery qry ;
      QString   cin,nom,prenom,adresse,numero ;

         cin=ui->lineEdit_cin->text();
             nom=ui->lineEdit_nom->text();
             prenom=ui->lineEdit_prenom->text();
          adresse=ui->lineEdit_adresse_5->text();
          numero=ui->lineEdit_num->text();

          CLIENT C( cin , nom, prenom, adresse, numero);
          bool test=C.ajouterclient();
          if(test)
          {
              QMessageBox::information(nullptr,QObject::tr("Ajouter client"),
                                                   QObject::tr("client ajout?? .\n"
                                                               "Click Cancel to exit ."),QMessageBox::Cancel);
                   }
              else
              {
              QMessageBox::critical(nullptr,QObject::tr("Ajouter client"),
                                               QObject::tr("ERooR .\n"
                                                           "Click Cancel to exit ."),QMessageBox::Cancel);
              }

}

void MainWindow::on_pushButton_modifier_2_clicked()
{
    QSqlQuery qry ;
      QString   cin,nom,prenom,adresse,numero ;

         cin=ui->lineEdit_cin->text();
             nom=ui->lineEdit_nom->text();
             prenom=ui->lineEdit_prenom->text();
          adresse=ui->lineEdit_adresse_5->text();
          numero=ui->lineEdit_num->text();

          CLIENT r( cin , nom, prenom, adresse, numero);
          bool test=r.modifierclient();
               if (test)
                       {
                   QMessageBox::information(nullptr,QObject::tr("Modifier client"),
                                                    QObject::tr("client Modifi?? .\n"
                                                                "Click Cancel to exit ."),QMessageBox::Cancel);

                        }
                   else
                   {
                   QMessageBox::critical(nullptr,QObject::tr("Modifier client"),
                                                    QObject::tr("client Modifi?? .\n"
                                                                "Click Cancel to exit ."),QMessageBox::Cancel);
                      }
}

void MainWindow::on_tabWidget_9_currentChanged(int index)
{
    CLIENT r;
    r.afficherclient(ui);

}


void MainWindow::on_tableView_3_activated(const QModelIndex &index)
{
    CLIENT r ;
       r.selectionnerclient(ui,index);
}

void MainWindow::on_pushButton_32_clicked()
{
    QSqlQuery qry;
        CLIENT r;


         bool test =r.supprimerclient(ui);
         if(test)
            {
             QMessageBox::information(nullptr,QObject::tr("Supprimer client"),
                                              QObject::tr("client supprim?? .\n"
                                                          "Click Cancel to exit ."),QMessageBox::Cancel);

            }
         else
         {
             QMessageBox::information(nullptr,QObject::tr("Supprimer client"),
                                              QObject::tr("Erreur .\n"
                                                          "Click Cancel to exit ."),QMessageBox::Cancel);
            }
}

void MainWindow::on_pushButton_33_clicked()
{
    CLIENT r;
    r.afficherclient(ui);
}

void MainWindow::on_radioButton_3_clicked()
{
    CLIENT c ;
       c.TRI1(ui);
}

void MainWindow::on_radioButton_4_clicked()
{
    CLIENT c ;
       c.TRI2(ui);
}

void MainWindow::on_pushButton_recherche_2_clicked()
{
    CLIENT c;
        c.recherche(ui);
}

void MainWindow::on_pushButton_34_clicked()
{
    CLIENT c;
  c.pdf();
}
void   MainWindow::sendMail()
{
    Smtp* smtp = new Smtp("yasmine.gharbi@esprit.tn","", "smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


        smtp->sendMail("yasmine.gharbi@esprit.tn", "yasmine.gharbi@esprit.tn" ,"inscription","cher client on vous informe que vous ??tes bien inscrit dans notre boutique et votre abonnement aura un an de validit?? d??s le jour de l'inscription.");
}
void   MainWindow::mailSent(QString status)
{

    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );

}

void MainWindow::on_sendBtn_clicked()
{
    sendMail();

}

void MainWindow::on_pushButton_36_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_toolButton_43_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_toolButton_44_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Log out"),
                      QObject::tr("Etes-vous sure de vous deconnect???.\n"
                                  "Cliquez oui pour confirmer."), QMessageBox::Yes);

    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_ajouterabo_clicked()
{
    QSqlQuery qry ;
        QString  id,cinabo,type;

           id=ui->lineEdit_idabo->text();
               cinabo=ui->lineEdit_cinabo->text();
               type=ui->comboBox_5->currentText();


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
                type=ui->comboBox_5->currentText();



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

void MainWindow::on_pushButton_supprimerabo_clicked()
{
    QSqlQuery qry;
        abonnement r;


         bool test =r.supprimerabonnement(ui);
         if(test)
            {
             QMessageBox::information(nullptr,QObject::tr("Supprimer abonnement"),
                                              QObject::tr("abonnement supprim?? .\n"
                                                          "Click Cancel to exit ."),QMessageBox::Cancel);

            }
         else
         {
             QMessageBox::information(nullptr,QObject::tr("Supprimer abonnement"),
                                              QObject::tr("Erreur .\n"
                                                          "Click Cancel to exit ."),QMessageBox::Cancel);
            }
}

void MainWindow::on_pushButton_37_clicked()
{
    statistique s ;
    s.exec();

}

void MainWindow::on_pushButton_act_2_clicked()
{
    abonnement r;
    r.afficherabonnement(ui);

}

void MainWindow::on_tabWidget_typeabo_currentChanged(int index)
{
    abonnement r;
    r.afficherabonnement(ui);


}

void MainWindow::on_client_2_clicked()
{
    abonnement r;
    r.afficherabonnement(ui);
    ui->stackedWidget->setCurrentIndex(9);


}

void MainWindow::on_abonnement_clicked()
{
    abonnement r;
    r.afficherabonnement(ui);
    ui->stackedWidget->setCurrentIndex(9);

}

void MainWindow::on_tache_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
    ui->tabtache->setModel(tmptache.afficher_tache());

}

void MainWindow::on_Personnel_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
    ui->tabemployer->setModel(tmpemployer.afficher_employer());


}

void MainWindow::on_Livraison_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
    ui->tableView_livraisons->setModel(tmplivraison.afficher_livraison());


}

void MainWindow::on_livreur_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);

}

void MainWindow::on_vehicule_clicked()
{
    ui->stackedWidget->setCurrentIndex(14);
    ui->tableView_vehicule->setModel(tmpveh.afficher_veh());


}

void MainWindow::on_pushButton_42_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_toolButton_58_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_pushButton_41_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_toolButton_55_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_pushButton_40_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_toolButton_52_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_pushButton_39_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_toolButton_49_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_pushButton_38_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_toolButton_46_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_toolButton_47_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Log out"),
                      QObject::tr("Etes-vous sure de vous deconnect???.\n"
                                  "Cliquez oui pour confirmer."), QMessageBox::Yes);

    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_toolButton_50_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Log out"),
                      QObject::tr("Etes-vous sure de vous deconnect???.\n"
                                  "Cliquez oui pour confirmer."), QMessageBox::Yes);

    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_toolButton_53_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Log out"),
                      QObject::tr("Etes-vous sure de vous deconnect???.\n"
                                  "Cliquez oui pour confirmer."), QMessageBox::Yes);

    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_toolButton_56_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Log out"),
                      QObject::tr("Etes-vous sure de vous deconnect???.\n"
                                  "Cliquez oui pour confirmer."), QMessageBox::Yes);

    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_toolButton_59_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Log out"),
                      QObject::tr("Etes-vous sure de vous deconnect???.\n"
                                  "Cliquez oui pour confirmer."), QMessageBox::Yes);

    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pb_ajouter_3_clicked()
{
    QString cin=ui->cin->text();
      QString nom=ui->nom->text();
      QString prenom=ui->prenom->text();
      QString adresse=ui->adresse->text();
      QString email=ui->email->text();
      employer e(cin,nom,prenom,adresse,email);
      bool test=e.ajouter_employer();
      if(test){
          QMessageBox::information(nullptr, QObject::tr("Personnel ajout??"),
                      QObject::tr("Personnel ajout??.\n"
                                  "OK"), QMessageBox::Cancel);
  }else
          QMessageBox::information(nullptr, QObject::tr("Personnel non ajout??"),
                      QObject::tr("Personnel non ajout??.\n"
                                  "OK"), QMessageBox::Cancel);
      ui->tabemployer->setModel(tmpemployer.afficher_employer());
      refresh();
}

void MainWindow::on_pb_modifier_3_clicked()
{
    tmpemployer.setcin(ui->comboBox_9->currentText());
    tmpemployer.setnom(ui->nom_2->text());
        tmpemployer.setprenom(ui->prenom_2->text());
        tmpemployer.setadresse(ui->adresse_2->text());
        tmpemployer.setemail(ui->email_2->text());

        bool test=tmpemployer.modifier_employer();
        if(test){
            QMessageBox::information(nullptr, QObject::tr("Personnel Modifi??"),
                        QObject::tr("Personnel Modifi??.\n"
                                    "OK"), QMessageBox::Cancel);
    }else
            QMessageBox::information(nullptr, QObject::tr("Personnel non Modifi??"),
                        QObject::tr("Personnel non Modifi??.\n"
                                    "OK"), QMessageBox::Cancel);
        refresh();
}

void MainWindow::on_comboBox_9_activated(const QString &arg1)
{
    tmpemployer.setcin(arg1);
    tmpemployer.chercher();
    ui->nom_2->setText(tmpemployer.getnom());
    ui->prenom_2->setText(tmpemployer.getprenom());
    ui->adresse_2->setText(tmpemployer.getadresse());
    ui->email_2->setText(tmpemployer.getemail());
    refresh();
}

void MainWindow::on_comboBox_8_activated(const QString &arg1)
{
    ui->sup->setText(arg1);

}

void MainWindow::on_pb_supprimer_clicked()
{
    QString cin = ui->comboBox_8->currentText();
        employer e;
        e.setcin(cin);
        bool test=e.supprimer_employer();
        if(test){
            QMessageBox::information(nullptr, QObject::tr("Personnel Supprim??"),
                        QObject::tr("Personnel Supprim??.\n"
                                    "OK"), QMessageBox::Cancel);
    }else
            QMessageBox::information(nullptr, QObject::tr("Personnel non Supprim??"),
                        QObject::tr("Personnel non Supprim??.\n"
                                    "OK"), QMessageBox::Cancel);
       ui->tabemployer->setModel(tmpemployer.afficher_employer());
       refresh();
}

void MainWindow::on_cin_3_textEdited(const QString &arg1)
{
    employer a ;
    ui->tabemployer->setModel(tmpemployer.recherche(arg1));

}

void MainWindow::on_trie_2_clicked()
{
    ui->tabemployer->setModel(tmpemployer.tri_employer()) ;

}

void MainWindow::on_imprimer_clicked()
{
    QPrinter printer;
            QPrintDialog *printDialog = new QPrintDialog(&printer, this);
            printDialog->setWindowTitle("Imprimer Document");
            printDialog->exec();

            QPropertyAnimation *animationimprimerp;
            animationimprimerp = new QPropertyAnimation(ui->imprimer,"geometry");
            animationimprimerp->setDuration(1000);
            animationimprimerp->setStartValue(QRect(690,20,141,51));
            animationimprimerp->setEndValue(QRect(680,20,200,51));
            animationimprimerp->setEasingCurve(QEasingCurve::InOutQuint);
            animationimprimerp->start(QPropertyAnimation::DeleteWhenStopped);
}

void MainWindow::on_pdf_2_clicked()
{
    QString strStream;
            QTextStream out(&strStream);


    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);
    const int rowCount = ui->tabemployer->model()->rowCount();
    const int columnCount = ui->tabemployer->model()->columnCount();
    QString TT = QDate::currentDate().toString("yyyy/MM/dd");
    out <<"<html>\n"
          "<head>\n"
           "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        << "<title>ERP - PERSONNELS LIST<title>\n "
        << "</head>\n"
        "<body bgcolor=#ffffff link=#5000A0>\n"
        "<h1 style=\"text-align: center;\"><strong> LISTE DES PERSONNELS </strong></h1>"
        "<h5 style=\"text-align: center;\">Le : "+TT+"</h5>"
        "<br>\n"
        "<table style=\"text-align: center; font-size: 12;\" border=1>\n "
          "</br> </br>";
    // headers
    out << "<thead><tr bgcolor=#d6e5ff>";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tabemployer->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tabemployer->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tabemployer->isColumnHidden(column)) {
                QString data =ui->tabemployer->model()->data(ui->tabemployer->model()->index(row, column)).toString().simplified();
                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }
    out <<  "</table>\n"
        "</body>\n"
        "</html>\n";

    QTextDocument doc;
    doc.setHtml(strStream);
    doc.print(&printer);
}

void MainWindow::on_pb_tache_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);

}

void MainWindow::on_makeShot_clicked()
{
    this->hide();
    qApp->processEvents();
#ifdef _WIN32
    //Sleep(3000);
#else
    Kek::wait(200);
#endif

    QPixmap okno = QPixmap::grabWindow(QApplication::desktop()->winId());
    QDateTime t = QDateTime::currentDateTime();
    QString saveWhere = qApp->applicationDirPath() + QString("/Scr_%1-%2-%3-%4-%5-%6.png")
            .arg(t.date().year()).arg(t.date().month()).arg(t.date().day())
            .arg(t.time().hour()).arg(t.time().minute()).arg(t.time().second());
    QString saveAs = QFileDialog::getSaveFileName(NULL, "Save screenshot as...",
                                                  saveWhere,
                                                  "PNG Picture (*.png)",
                                                  nullptr,
                                                  QFileDialog::DontUseNativeDialog);
    if(!saveAs.isEmpty())
        okno.save(saveAs, "PNG");

    this->show();
}

void MainWindow::on_modifier_currentChanged(int index)
{
    ui->tabemployer->setModel(tmpemployer.afficher_employer());
    refresh();
}

void MainWindow::on_pb_ajouter_2_clicked()
{
    QString id=ui->id->text();
    QString descri=ui->descri->text();
    QDateTime duree=ui->duree->dateTime();
    tache t (id,descri,duree);
    bool test=t.ajouter_tache();
    if(test){
        notif m("Tache","Tache ajout?? avec succ??s");
        m.afficher();
    }else{
        QMessageBox::information(nullptr, QObject::tr("Tache non ajout??"),
                    QObject::tr("Tache non ajout??.\n"
                                "OK"), QMessageBox::Cancel);
}
    ui->tabtache->setModel(tmptache.afficher_tache());
    refresh2();

}

void MainWindow::on_modifier_2_currentChanged(int index)
{
    ui->tabtache->setModel(tmptache.afficher_tache());
    ui->comboBox_7->setModel(tmptache.afficher_liste());
    ui->comboBox_6->setModel(tmptache.afficher_liste());


}

void MainWindow::on_cin_4_textEdited(const QString &arg1)
{
    tache t;
     ui->tabtache->setModel(tmptache.recherche(arg1));

}

void MainWindow::on_trie_clicked()
{
    ui->tabtache->setModel(tmptache.tri_tache()) ;
    notif m("Tache","Tache Tri??");
    m.afficher();


}

void MainWindow::on_comboBox_6_activated(const QString &arg1)
{
    ui->sup_2->setText(arg1);

}

void MainWindow::on_comboBox_7_activated(const QString &arg1)
{
    tmptache.setid(arg1);
    tmptache.chercher();
    ui->descri_2->setText(tmptache.getdescri());
    ui->duree_2->setDateTime(tmptache.getduree());

}

void MainWindow::on_pb_modifier_2_clicked()
{
    tmptache.setid(ui->comboBox_7->currentText());
    tmptache.setdescri(ui->descri_2->text());
    tmptache.setduree(ui->duree_2->dateTime());

    bool test=tmptache.modifier_tache();
    if(test){/*
        QMessageBox::information(nullptr, QObject::tr("tache Modifi??"),
                    QObject::tr("tache Modifi??.\n"
                                "OK"), QMessageBox::Cancel);*/
        notif m("Tache","Tache Modifi??");
        m.afficher();


}else
        QMessageBox::information(nullptr, QObject::tr("tache non Modifi??"),
                    QObject::tr("tache non Modifi??.\n"
                                "OK"), QMessageBox::Cancel);
}

void MainWindow::on_checkBox_pressed()
{

}

void MainWindow::on_email_6_clicked()
{
    /************************************SMTP******************************************************/
                    Smtp* smtp = new Smtp("donia.sarsar@esprit.tn","", "smtp.gmail.com",465);
                    connect (smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

                    QString objet=ui->objet->text();
                    QString o=ui->description->text();
                    QString email=ui->email_3->text();
                    smtp->sendMail("donia.sarsar@esprit.tn", email , objet,o);
    /***********************************************************************************************/

}

void MainWindow::on_qrcode_5_clicked()
{
    int tabev=ui->tabemployer->currentIndex().row();
    QVariant idd=ui->tabemployer->model()->data(ui->tabemployer->model()->index(tabev,0));
    QString id= idd.toString();
    QSqlQuery qry;
    qry.prepare("select * from PERSONNEL where CIN=:id");
    qry.bindValue(":id",id);
    qry.exec();
    QString nom,debut,fin,idp,ids;
    while(qry.next()){
        nom=qry.value(1).toString();
        debut=qry.value(2).toString();
        fin=qry.value(3).toString();
        idp=qry.value(4).toString();
    }
    ids=QString(id);
    ids="CIN: "+ids+" Nom: "+nom+" Prenom: "+debut+" Adresse: "+fin+"Email : "+idp;
    QrCode qr = QrCode::encodeText(ids.toUtf8().constData(), QrCode::Ecc::HIGH);

    // Read the black & white pixels
    QImage im(qr.getSize(),qr.getSize(), QImage::Format_RGB888);
    for (int y = 0; y < qr.getSize(); y++) {
        for (int x = 0; x < qr.getSize(); x++) {
            int color = qr.getModule(x, y);  // 0 for white, 1 for black

            // You need to modify this part
            if(color==0)
                im.setPixel(x, y,qRgb(254, 254, 254));
            else
                im.setPixel(x, y,qRgb(0, 0, 0));
        }
    }
    im=im.scaled(200,200);
    ui->qrlabel_4->setPixmap(QPixmap::fromImage(im));

}

void MainWindow::on_pb_supprimer_2_clicked()
{
    QString id = ui->sup_2->text();
     tache t;
     t.setid(id);
     bool test=t.supprimer_tache();
     if(test){
         /*QMessageBox::information(nullptr, QObject::tr("Tache Supprim??"),
                     QObject::tr("Tache Supprim??.\n"
                                 "OK"), QMessageBox::Cancel);*/
         notif m("Tache","Tache Supprim??");
         m.afficher();

 }else
         QMessageBox::information(nullptr, QObject::tr("Tache non Supprim??"),
                     QObject::tr("Tache non Supprim??.\n"
                                 "OK"), QMessageBox::Cancel);
    ui->tabtache->setModel(tmptache.afficher_tache());
    refresh2();
}

void MainWindow::on_lineEdit_R_3_textEdited(const QString &arg1)
{
    livraison a;
    ui->tableView_livraisons->setModel(tmplivraison.rechercher_liv_dynamique(arg1));

}

void MainWindow::on_SL_clicked()
{
    QString id =ui->tableView_livraisons->model()->index(ui->tableView_livraisons->currentIndex().row(),0).data().toString();
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "Supprimer", "Etes vous sur de supprimer cette Livraison?",
                                    QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes) {
         // int idi = id.toInt() ;
          bool test=tmplivraison.supprimer_livraison(id);
          if(test)
          {
              ui->tableView_livraisons->setModel(tmplivraison.afficher_livraison());
              QMessageBox::information(nullptr,"Suppression","Livraison supprim??");

          }
      }
}

void MainWindow::on_pdf_3_clicked()
{
    QString strStream;
            QTextStream out(&strStream);


    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);
    const int rowCount = ui->tableView_livraisons->model()->rowCount();
    const int columnCount = ui->tableView_livraisons->model()->columnCount();
    QString TT = QDate::currentDate().toString("yyyy/MM/dd");
    out <<"<html>\n"
          "<head>\n"
           "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        << "<title>ERP - FACTURES LIST<title>\n "
        << "</head>\n"
        "<body bgcolor=#ffffff link=#5000A0>\n"
        "<h1 style=\"text-align: center;\"><strong> Liste Des Vehicules </strong></h1>"
        "<h5 style=\"text-align: center;\">Le : "+TT+"</h5>"
        "<br>\n"
        "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
          "</br> </br>";
    // headers
    out << "<thead><tr bgcolor=#d6e5ff>";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tableView_livraisons->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tableView_livraisons->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tableView_livraisons->isColumnHidden(column)) {
                QString data =ui->tableView_livraisons->model()->data(ui->tableView_livraisons->model()->index(row, column)).toString().simplified();
                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }
    out <<  "</table>\n"
        "</body>\n"
        "</html>\n";

    QTextDocument doc;
    doc.setHtml(strStream);
    doc.print(&printer);
}

void MainWindow::on_reload_clicked()
{
    tmplivraison.ajouter_livraison() ;
    ui->tableView_livraisons->setModel(tmplivraison.afficher_livraison());

}

void MainWindow::on_Marquer_livre_clicked()
{
    QString id =ui->tableView_livraisons->model()->index(ui->tableView_livraisons->currentIndex().row(),0).data().toString();
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "UPDATE", "Etes vous sur de marquer cette livraison comme livree ?",
                                    QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes) {
         // int idi = id.toInt() ;
          bool test=tmplivraison.livre(id);
          if(test)
          {
              ui->tableView_livraisons->setModel(tmplivraison.afficher_livraison());
              QMessageBox::information(nullptr,"UPDATE","Livraison Updated");

          }
      }
}

void MainWindow::on_tabWidget_4_currentChanged(int index)
{
    livraison L ;
    L.stat(ui->widget_4);

}

void MainWindow::on_lineEdit_R_2_textEdited(const QString &arg1)
{
    livreur a;
    ui->tableView_livreur->setModel(tmpliv.rechercher_liv_dynamique(arg1));

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
              QMessageBox::information(nullptr,"Suppression","Livreur supprim??");

          }
      }

}

void MainWindow::on_pushButton_tri_2_clicked()
{
    ui->tableView_livreur->setModel(tmpliv.tri_liv());

}

void MainWindow::on_pdfl_clicked()
{
    QString strStream;
            QTextStream out(&strStream);


    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);
    const int rowCount = ui->tableView_livreur->model()->rowCount();
    const int columnCount = ui->tableView_livreur->model()->columnCount();
    QString TT = QDate::currentDate().toString("yyyy/MM/dd");
    out <<"<html>\n"
          "<head>\n"
           "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        << "<title>ERP - FACTURES LIST<title>\n "
        << "</head>\n"
        "<body bgcolor=#ffffff link=#5000A0>\n"
        "<h1 style=\"text-align: center;\"><strong> Liste Des Vehicules </strong></h1>"
        "<h5 style=\"text-align: center;\">Le : "+TT+"</h5>"
        "<br>\n"
        "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
          "</br> </br>";
    // headers
    out << "<thead><tr bgcolor=#d6e5ff>";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tableView_livreur->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tableView_livreur->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tableView_livreur->isColumnHidden(column)) {
                QString data =ui->tableView_livreur->model()->data(ui->tableView_livreur->model()->index(row, column)).toString().simplified();
                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }
    out <<  "</table>\n"
        "</body>\n"
        "</html>\n";

    QTextDocument doc;
    doc.setHtml(strStream);
    doc.print(&printer);
}

void MainWindow::on_qrcode_2_clicked()
{
    int tabev=ui->tableView_livreur->currentIndex().row();
    QVariant idd=ui->tableView_livreur->model()->data(ui->tableView_livreur ->model()->index(tabev,0));
    QString id= idd.toString();
    QSqlQuery qry;
    qry.prepare("select * from livreur where cin=:id");
    qry.bindValue(":id",id);
    qry.exec();
    QString cin,nom,prenom,statue;
    while(qry.next()){
        cin=qry.value(1).toString();
        nom=qry.value(2).toString();
        prenom=qry.value(3).toString();
        statue=qry.value(4).toString();
    }
    cin=QString(id);
    cin="CIN: "+cin+" Nom: "+nom+" Prenom: "+prenom+" Statue: "+statue;
    QrCode qr = QrCode::encodeText(cin.toUtf8().constData(), QrCode::Ecc::HIGH);

    // Read the black & white pixels
    QImage im(qr.getSize(),qr.getSize(), QImage::Format_RGB888);
    for (int y = 0; y < qr.getSize(); y++) {
        for (int x = 0; x < qr.getSize(); x++) {
            int color = qr.getModule(x, y);  // 0 for white, 1 for black

            // You need to modify this part
            if(color==0)
                im.setPixel(x, y,qRgb(254, 254, 254));
            else
                im.setPixel(x, y,qRgb(0, 0, 0));
        }
    }
    im=im.scaled(200,200);
    ui->qrlabell->setPixmap(QPixmap::fromImage(im));
    int i=0 ;
    for(i=0;i<100;i=i+0.1){
        i++;
        ui->progressBar_1->setValue(i);
    }
}

void MainWindow::on_pushButton_43_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);

}

void MainWindow::on_toolButton_61_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_toolButton_62_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Log out"),
                      QObject::tr("Etes-vous sure de vous deconnect???.\n"
                                  "Cliquez oui pour confirmer."), QMessageBox::Yes);

    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pbre_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);

}

void MainWindow::on_pushButton_12_clicked()
{
    QString cin = ui->lec->text();
    QString nom = ui->len->text();
    QString prenom = ui->lep->text();
    livreur l;
    bool test=l.resaisie_liv(cin,nom,prenom);

    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("modifie un livreur"),
                          QObject::tr("vehicule modifie.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("non modifie"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    ui->stackedWidget->setCurrentIndex(13);
    ui->tableView_livreur->setModel(tmpliv.afficher_liv());
}

void MainWindow::on_pushmod_2_clicked()
{
    QString cin = ui->comboBox_12->currentText();

    QString statue = ui->comboBox_11->currentText();

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

void MainWindow::on_tabWidget_5_currentChanged(int index)
{
    ui->comboBox_12->clear();
    ui->comboBox_12->addItems(tmpliv.recherche_liv());
    ui->tableView_livreur->setModel(tmpliv.afficher_liv());


}

void MainWindow::on_tabWidget_6_currentChanged(int index)
{
    ui->tableView_vehicule->setModel(tmpveh.afficher_veh());
    ui->comboBox_13->clear();
    ui->comboBox_13->addItems(tmpveh.recherche_veh());


}

void MainWindow::on_lineEdit_R_textEdited(const QString &arg1)
{
    vehicule a;
    ui->tableView_vehicule->setModel(tmpveh.rechercher_veh_dynamique(arg1));

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
              QMessageBox::information(nullptr,"Suppression","Vehicule supprim??");

          }
      }
}

void MainWindow::on_pushButton_tri_clicked()
{
    ui->tableView_vehicule->setModel(tmpveh.tri_veh());

}

void MainWindow::on_pdf_4_clicked()
{
    QString strStream;
            QTextStream out(&strStream);


    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);
    const int rowCount = ui->tableView_vehicule->model()->rowCount();
    const int columnCount = ui->tableView_vehicule->model()->columnCount();
    QString TT = QDate::currentDate().toString("yyyy/MM/dd");
    out <<"<html>\n"
          "<head>\n"
           "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        << "<title>ERP - FACTURES LIST<title>\n "
        << "</head>\n"
        "<body bgcolor=#ffffff link=#5000A0>\n"
        "<h1 style=\"text-align: center;\"><strong> Liste Des Vehicules </strong></h1>"
        "<h5 style=\"text-align: center;\">Le : "+TT+"</h5>"
        "<br>\n"
        "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
          "</br> </br>";
    // headers
    out << "<thead><tr bgcolor=#d6e5ff>";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tableView_vehicule->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tableView_vehicule->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tableView_vehicule->isColumnHidden(column)) {
                QString data =ui->tableView_vehicule->model()->data(ui->tableView_vehicule->model()->index(row, column)).toString().simplified();
                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }
    out <<  "</table>\n"
        "</body>\n"
        "</html>\n";

    QTextDocument doc;
    doc.setHtml(strStream);
    doc.print(&printer);
}

void MainWindow::on_res_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);

}

void MainWindow::on_pushButton_11_clicked()
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

void MainWindow::on_pushButton_44_clicked()
{
    ui->stackedWidget->setCurrentIndex(14);
    ui->tableView_vehicule->setModel(tmpveh.afficher_veh());

}

void MainWindow::on_toolButton_64_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_toolButton_65_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Log out"),
                      QObject::tr("Etes-vous sure de vous deconnect???.\n"
                                  "Cliquez oui pour confirmer."), QMessageBox::Yes);

    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_45_clicked()
{
    ui->stackedWidget->setCurrentIndex(14);
    ui->tableView_vehicule->setModel(tmpveh.afficher_veh());

}

void MainWindow::on_toolButton_67_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_toolButton_68_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Log out"),
                      QObject::tr("Etes-vous sure de vous deconnect???.\n"
                                  "Cliquez oui pour confirmer."), QMessageBox::Yes);

    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_VE_clicked()
{
    ui->tableView_vehicule_EN->setModel(tmpveh.ent_veh());

    ui->stackedWidget->setCurrentIndex(17);


}

void MainWindow::on_qrcode_4_clicked()
{
    int tabev=ui->tableView_vehicule->currentIndex().row();
    QVariant idd=ui->tableView_vehicule->model()->data(ui->tableView_vehicule ->model()->index(tabev,0));
    QString id= idd.toString();
    QSqlQuery qry;
    qry.prepare("select * from vehicule where matricule=:id");
    qry.bindValue(":id",id);
    qry.exec();
    QString matricule,marque,couleur,date_ent;
    while(qry.next()){
        matricule=qry.value(1).toString();
        marque=qry.value(2).toString();
        couleur=qry.value(3).toString();
        date_ent=qry.value(4).toString();
    }
    matricule=QString(id);
    matricule="Matricule: "+matricule+" Marque: "+marque+" Couleur: "+couleur+" Date_ent: "+date_ent;
    QrCode qr = QrCode::encodeText(matricule.toUtf8().constData(), QrCode::Ecc::HIGH);

    // Read the black & white pixels
    QImage im(qr.getSize(),qr.getSize(), QImage::Format_RGB888);
    for (int y = 0; y < qr.getSize(); y++) {
        for (int x = 0; x < qr.getSize(); x++) {
            int color = qr.getModule(x, y);  // 0 for white, 1 for black

            // You need to modify this part
            if(color==0)
                im.setPixel(x, y,qRgb(254, 254, 254));
            else
                im.setPixel(x, y,qRgb(0, 0, 0));
        }
    }
    im=im.scaled(200,200);
    ui->qrlabel_2->setPixmap(QPixmap::fromImage(im));
    int i=0 ;
    ui->progressBar_2->setValue(i);
    for(i=0;i<100;i=i+0.1){
        i++;
        ui->progressBar_2->setValue(i);
    }
}

void MainWindow::on_pushmod_clicked()
{
    QString matricule = ui->comboBox_13->currentText();
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

void MainWindow::on_pushButton_13_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Exportation en fichier Excel"), qApp->applicationDirPath (),
                                                                tr("Fichiers d'extension Excel (*.xls)"));
                if (fileName.isEmpty())
                    return;

                ExportExcelObject obj(fileName, "mydata", ui->tab_produit_4);

                // you can change the column order and
                // choose which colum to export
                obj.addField(0, "ID_P", "char(20)");
                obj.addField(1, "NOM_P", "char(20)");
                obj.addField(2, "TYPE", "char(20)");
                obj.addField(3, "PRIX", "char(20)");
                //obj.addField(5, "servespeed3", "char(20)");


                int retVal = obj.export2Excel();

                if( retVal > 0)
                {
                    QMessageBox::information(this, tr("FAIS!"),
                                             QString(tr("%1 enregistrements export??s!")).arg(retVal)
                                             );
                }
}

void MainWindow::on_email_7_clicked()
{
    /************************************SMTP******************************************************/
                    Smtp* smtp = new Smtp("nour.friha@esprit.tn","", "smtp.gmail.com",465);
                    connect (smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

                    QString objet=ui->objet_2->text();
                    QString o=ui->description_2->text();
                    QString email=ui->email_4->text();
                    smtp->sendMail("nour.friha@esprit.tn", email , objet,o);
    /***********************************************************************************************/

}
