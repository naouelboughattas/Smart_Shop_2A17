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
#include <QPrinter>
#include <QFileInfo>
#include <QFileDialog>

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

    Produit P1; P1.setid_P(ui->supr_prod->currentText().toInt());
    bool test=P1.supprimer(P1.getid_P());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Suppression avec succes.");
        ui->tab_produit->setModel(P.afficher());

       }
    else if(test==false)
        msgBox.setText("Echec de suppression");
    msgBox.exec();
    ui->supr_prod->clear();
    ui->supr_prod->addItems(P.recherche_id_produit());

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
void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
        ui->tab_produit->setModel(P.recherche(arg1));
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->tab_produit->setModel(P.tri());
}

void MainWindow::on_tab_12_currentChanged(int index)
{
    ui->tab_produit->setModel(P.afficher());
    ui->supr_prod->clear();
    ui->supr_prod->addItems(P.recherche_id_produit());

}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_pushButton_4_clicked()
{
    ui->supr_cat->clear();
    ui->supr_cat->addItems(C.recherche_id_categorie());

    ui->stackedWidget->setCurrentIndex(2);

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

void MainWindow::on_lineEdit_2_cat_textEdited(const QString &arg1)
{
    ui->tab_catgorie->setModel(C.recherche_cat(arg1));

}

void MainWindow::on_pb_modifier_2_cat_clicked()
{
    int ID_cat=ui->id_mod_2->text().toInt();
    QString Nom_cat=ui->nom_mod_2->text();

       Categorie C2;
       bool test=C2.modifier_cat(ID_cat,Nom_cat);

       if(test)
       {
         ui->id_mod->clear();
         ui->nom_mod->clear();
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
    ui->supr_prod->clear();
    ui->supr_prod->addItems(C.recherche_id_categorie());

}

void MainWindow::on_pushButton_5_cat_clicked()
{
    ui->tab_catgorie->setModel(C.tri_cat());

}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    ui->tab_catgorie->setModel(C.afficher_cat());
    ui->supr_cat->clear();
    ui->supr_cat->addItems(C.recherche_id_categorie());

}

void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_6_clicked()
{
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

void MainWindow::on_pdff_2_clicked()
{
    QString strStream;
            QTextStream out(&strStream);


    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);
    const int rowCount = ui->tab_produit->model()->rowCount();
    const int columnCount = ui->tab_produit->model()->columnCount();
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
        if (!ui->tab_produit->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tab_produit->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tab_produit->isColumnHidden(column)) {
                QString data =ui->tab_produit->model()->data(ui->tab_produit->model()->index(row, column)).toString().simplified();
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
