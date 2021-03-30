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
#include"QTextDocumentWriter"
#include <QTextStream>
#include"QDesktopServices"
#include <QFileDialog>
#include <QPrinter>
#include"QFont"
#include"QPen"
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


void MainWindow::on_bt_login_clicked()
{
    if(ui->user->text()=="wael" && ui->pass->text()=="ksila"){
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
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);






    ui->tab_fact->setModel(Ftemp.afficher());
    ui->produit_inclus->clear();
    ui->produit_inclus->addItems(Etemp.recherche_produit());

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
    /*/////////////////////////////////////////////////////////////////////////////*/


    ui->tab_fact->setModel(Ftemp.afficher());
    ui->date_box->setDateTime(QDateTime::currentDateTime());
    ui->modif_date_f_box->setDateTime(QDateTime::currentDateTime());
    ui->le_id_f->setText(Ftemp.remplir());

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
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_commandLinkButton_2_clicked()
{
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
    if(test){
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectué\n"
                                 "Click Cancel to exit."),QMessageBox::Cancel);
       // ui->tab_fact->setModel(Ftemp.afficher());


    }else{
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                              QObject::tr("Ajout non effectué\n"
                                 "Click Cancel to exit."),QMessageBox::Cancel);

    }
    ui->produit_inclus->clear();
    ui->produit_inclus->addItems(Etemp.recherche_produit());


}

void MainWindow::on_tabWidget_2_currentChanged(int index)
{
    ui->produit_inclus->clear();
    ui->produit_inclus->addItems(Etemp.recherche_produit());

}
