#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets/QMainWindow>
#include "smtp.h"
#include <QtWidgets/QGridLayout>
#include <QTableView>
#include <QPdfWriter>
#include"QTextDocumentWriter"
#include"QDesktopServices"
#include <QPixmap>
#include <QtPrintSupport/QPrinter>
//#include <QPrintDialog>
#include <QTextDocument>
//#include <QPrinter>
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
#include <QDebug>
#include <QObject>
#include "QrCode.h"
#include <QTimer>
#include "Livraison.h"

using namespace qrcodegen;


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



    /*////////////////////   Ajout Images    ////////////////////

    QPixmap veh("C:\Users\Ibrahim\Downloads\veh.png");
    ui->label_4->setPixmap(veh.scaled(100,100,Qt::KeepAspectRatio));
    QPixmap livreur("C:/Users/Ibrahim/Downloads/veh.png");
    ui->label_6->setPixmap(livreur.scaled(100,100,Qt::KeepAspectRatio));
    QPixmap livraison("C:/Users/Ibrahim/Downloads/veh.png");
    ui->label_7->setPixmap(livraison.scaled(100,100,Qt::KeepAspectRatio));


    ////////////////////   Ajout Images    ////////////////////*/
    //Timer
     QTimer *timer_p=new QTimer(this);
     connect(timer_p,SIGNAL(timeout()),this,SLOT(showTime()));
     timer_p->start();
     //DAate systeme
     QDateTime Date_p=QDateTime::currentDateTime();
     QString Date_txt=Date_p.toString("dddd dd MMMM yyyy");
    // ui->Date->setText(Date_txt);
     ui->Date_2->setText(Date_txt);

    }
    void MainWindow::showTime()
    {
    QTime time=QTime::currentTime();
    QString time_txt=time.toString("hh:mm:ss");
   // ui->Timer->setText(time_txt);
    ui->Timer_2->setText(time_txt);

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

        Smtp* smtp = new Smtp("smarttt.shop@gmail.com","projet2a", "smtp.gmail.com",465);
        connect (smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
        smtp->sendMail("smarttt.shop@gmail.com", "rayanaibrahim894@gmail.com" , objet, message);


    }
     //ui->stackedWidget->setCurrentIndex(1);
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

    ui->stackedWidget->setCurrentIndex(4);
    ui->tableView_livreur->setModel(tmpliv.afficher_liv());

}



void MainWindow::on_qrcode_clicked()
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
    ui->qrlabel->setPixmap(QPixmap::fromImage(im));
    int i=0 ;
    for(i=0;i<100;i=i+0.1){
        i++;
        ui->progressBar->setValue(i);
    }
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
              QMessageBox::information(nullptr,"Suppression","Livraison supprimé");

          }
      }

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

void MainWindow::on_tabWidget_3_currentChanged(int index)
{
livraison L ;
L.stat(ui->widget);
}
void MainWindow::on_pushButton_VE_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
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

void MainWindow::on_lineEdit_R_3_textEdited(const QString &arg1)
{
    livraison a;
    ui->tableView_livraisons->setModel(tmplivraison.rechercher_liv_dynamique(arg1));
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
    ui->stackedWidget->setCurrentIndex(2);
}
void MainWindow::on_pushButton_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::on_pbret_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}
void MainWindow::on_res_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pbre_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

    ui->tableView_livraisons->setModel(tmplivraison.afficher_livraison());
}

void MainWindow::on_reload_clicked()
{
 tmplivraison.ajouter_livraison() ;
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
