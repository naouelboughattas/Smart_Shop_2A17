#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connexion.h"
#include "employer.h"
#include "tache.h"
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
#include <src/SmtpMime>

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

void MainWindow::refresh2()
{
  ui->tabtache->setModel(tmptache.afficher_tache());
  ui->comboBox_4->setModel(tmptache.afficher_liste());
  ui->comboBox_6->setModel(tmptache.afficher_liste());
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
    if(test){
        QMessageBox::information(nullptr, QObject::tr("Personnel Modifié"),
                    QObject::tr("Personnel Modifié.\n"
                                "OK"), QMessageBox::Cancel);
}else
        QMessageBox::information(nullptr, QObject::tr("Personnel non Modifié"),
                    QObject::tr("Personnel non Modifié.\n"
                                "OK"), QMessageBox::Cancel);
    refresh();

}

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


void MainWindow::on_comboBox_5_activated(const QString &arg1)
{
    ui->sup->setText(arg1);
    refresh();
}


/*void MainWindow::on_cin_3_textChanged(const QString &arg1)
{
    ui->tabemployer->setModel(tmpemployer.recherche(arg1));
    valeur=arg1;
    refresh();
}
*/
void MainWindow::on_checkBox_2_stateChanged(int arg1)
{

    etat=arg1;
    ui->tabemployer->setModel(tmpemployer.recherche(valeur));
    refresh();
}

void MainWindow::on_pb_supprimer_clicked()
{
    QString cin = ui->cin->text();
     employer e;
     e.setcin(cin);
     bool test=e.supprimer_employer();
     if(test){
         QMessageBox::information(nullptr, QObject::tr("Personnel Supprimé"),
                     QObject::tr("Personnel Supprimé.\n"
                                 "OK"), QMessageBox::Cancel);
 }else
         QMessageBox::information(nullptr, QObject::tr("Personnel non Supprimé"),
                     QObject::tr("Personnel non Supprimé.\n"
                                 "OK"), QMessageBox::Cancel);
    ui->tabemployer->setModel(tmpemployer.afficher_employer());
    refresh();
}

void MainWindow::on_cin_3_textEdited(const QString &arg1)
{
    employer a ;
    ui->tabemployer->setModel(tmpemployer.recherche(arg1));

}



void MainWindow::on_pb_ajouter_2_clicked()
{
    QString id=ui->id->text();
    QString descri=ui->descri->text();
    QDateTime duree=ui->duree->dateTime();
    tache t (id,descri,duree);
    bool test=t.ajouter_tache();
    if(test){
        QMessageBox::information(nullptr, QObject::tr("Tache ajouté"),
                    QObject::tr("Tache ajouté.\n"
                                "OK"), QMessageBox::Cancel);
}else
        QMessageBox::information(nullptr, QObject::tr("Tache non ajouté"),
                    QObject::tr("Tache non ajouté.\n"
                                "OK"), QMessageBox::Cancel);
    ui->tabtache->setModel(tmptache.afficher_tache());
    refresh2();
}

void MainWindow::on_pb_tache_clicked()
{

    ui->stackedWidget->setCurrentIndex(1);


}

void MainWindow::on_pb_modifier_2_clicked()
{
    tmptache.setdescri(ui->descri_2->text());
    tmptache.setduree(ui->duree_2->dateTime());

    bool test=tmptache.modifier_tache();
    if(test){
        QMessageBox::information(nullptr, QObject::tr("tache Modifié"),
                    QObject::tr("tache Modifié.\n"
                                "OK"), QMessageBox::Cancel);
}else
        QMessageBox::information(nullptr, QObject::tr("tache non Modifié"),
                    QObject::tr("tache non Modifié.\n"
                                "OK"), QMessageBox::Cancel);
    refresh2();
}

void MainWindow::on_comboBox_4_activated(const QString &arg1)
{
    tmptache.setid(arg1);
    tmptache.chercher();
    ui->descri_2->setText(tmptache.getdescri());
    ui->duree_2->setDateTime(tmptache.getduree());

    refresh2();

}

void MainWindow::on_comboBox_6_activated(const QString &arg1)
{
    ui->sup_2->setText(arg1);
    refresh2();
}

void MainWindow::on_pb_supprimer_2_clicked()
{
    QString id = ui->id->text();
     tache t;
     t.setid(id);
     bool test=t.supprimer_tache();
     if(test){
         QMessageBox::information(nullptr, QObject::tr("Tache Supprimé"),
                     QObject::tr("Tache Supprimé.\n"
                                 "OK"), QMessageBox::Cancel);
 }else
         QMessageBox::information(nullptr, QObject::tr("Tache non Supprimé"),
                     QObject::tr("Tache non Supprimé.\n"
                                 "OK"), QMessageBox::Cancel);
    ui->tabtache->setModel(tmptache.afficher_tache());
    refresh2();
}

void MainWindow::on_cin_4_textEdited(const QString &arg1)
{
     ui->tabtache->setModel(tmptache.recherche(arg1));
     refresh2();
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

void MainWindow::on_email_6_clicked()
{
    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);
       smtp.setUser("donia.sarsar@esprit.tn");
       smtp.setPassword("Dadou1234");
       MimeMessage message;
       message.setSender(new EmailAddress("donia.sarsar@esprit.tn", "Service client"));
       message.addRecipient(new EmailAddress(ui->email_3->text(), "Recipient's Name"));
       message.setSubject(ui->objet->text());
       MimeText text;
       text.setText(ui->description->text());
       message.addPart(&text);
       smtp.connectToHost();
       smtp.login();
       smtp.sendMail(message);
       smtp.quit();
}

void MainWindow::on_trie_clicked()
{
    ui->tabtache->setModel(tmptache.tri_tache()) ;

}
