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

using namespace qrcodegen;

void MainWindow::on_bt_login_clicked()
{
    if(ui->user->text()=="wael" && ui->pass->text()=="ksila"){
        QMediaPlayer* player;
        player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/Users/waelk/OneDrive/Bureau/C++/PROJET/MyProject/bienvenue.mp3"));
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
    ui->progressBar->setValue(0);



    ui->tab_ev->setModel(Etemp.afficher_ev());
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

    int ret=Atemp.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< Atemp.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<Atemp.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(Atemp.getserial(),SIGNAL(readyRead()),this,SLOT(arduino())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).

     //Timer
      QTimer *timer_p=new QTimer(this);
      connect(timer_p,SIGNAL(timeout()),this,SLOT(showTime()));
      timer_p->start();
      //DAate systeme
      QDateTime Date_p=QDateTime::currentDateTime();
      QString Date_txt=Date_p.toString("dddd dd MMMM yyyy");
      ui->Date->setText(Date_txt);
      ui->Date_2->setText(Date_txt);

}
void MainWindow::showTime()
{
    QTime time=QTime::currentTime();
    QString time_txt=time.toString("hh:mm:ss");
    ui->Timer->setText(time_txt);
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
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectué\n"
                                 "Click Cancel to exit."),QMessageBox::Cancel);
        ui->tab_fact->setModel(Ftemp.afficher());


    }else{
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                              QObject::tr("Ajout non effectué\n"
                                 "Click Cancel to exit."),QMessageBox::Cancel);

    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->tab_fact->setModel(Ftemp.tri());
    ui->tab_fact->resizeRowsToContents();
    ui->le_client->clear();
    ui->le_client->addItems(Ftemp.recherche_client());

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


              QMessageBox::information(nullptr,"Suppression","Facture supprimé");

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
        QMessageBox::information(nullptr, QObject::tr("Modification effectué"),
                          QObject::tr("Facture modifie.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modification echoué"),
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

              QMessageBox::information(nullptr,"Suppression","Facture supprimé");

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
    //ui->tab_prod->setModel(Ftemp.afficher());
    ui->stackedWidget->setCurrentIndex(1);


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
            QMessageBox::information(nullptr,"Ajout effectué\n","Ajout effectué\n");
            if(ui->checkBox->isChecked()){
                /************************************SMTP******************************************************/
                        QString objet="NOUVELLE EVENEMENT AJOUTE !";
                                QString message="IDEvenement:"+ui->id_ev->text()+"Nomd'evenement:"+ui->nom_ev->text() ;
                                Smtp* smtp = new Smtp("wael.ksila@esprit.tn","191JMT3269", "smtp.gmail.com",465);
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

                 QMessageBox::information(nullptr,"Client informé\n","Mail envoyé a vos clients\n");


            }




    }else{
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                              QObject::tr("Ajout non effectué\n"
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
              QMessageBox::information(nullptr,"Suppression","Evenement supprimé");

          }
      }else{
          QMessageBox::information(nullptr,"Suppression","Evenement non supprimé !");

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
              QMessageBox::information(nullptr,"Suppression","Evenement supprimé");

          }
      }else{
          QMessageBox::information(nullptr,"Suppression","Evenement non supprimé !");

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
        QMessageBox::information(nullptr, QObject::tr("Modification effectué"),
                          QObject::tr("Facture modifie.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modification echoué"),
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
                                             QString(tr("%1 enregistrements exportés!")).arg(retVal)
                                             );
                }
}

void MainWindow::on_pushButton_6_clicked()
{


}

void MainWindow::on_toolButton_2_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Log out"),
                      QObject::tr("Etes-vous sure de vous deconnecté?.\n"
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
            QString message=" Votre courrier a été ajouté avec succés" ;
            Smtp* smtp = new Smtp("wael.ksila@esprit.tn","191JMT3269", "smtp.gmail.com",465);
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
                      QObject::tr("Etes-vous sure de vous deconnecté?.\n"
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

