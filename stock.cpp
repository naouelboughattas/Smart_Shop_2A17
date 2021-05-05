#include "stock.h"
#include<QPainter>
#include<QPdfWriter>
#include<QMessageBox>
#include<QSystemTrayIcon>
STOCK::STOCK()
{
    nomp="";
    quantite="";
    referencep="";
    noms="";
    references="";
}

STOCK::STOCK(QString nomp, QString quantite,QString referencep,QString noms, QString references)
{
    this->nomp=nomp;
    this->quantite=quantite;
    this->referencep=referencep ;
    this->noms=noms ;
    this->references=references ;
}

bool STOCK::ajouterproduit()
{
    QSqlQuery qry ;
    qry.prepare("insert into STOCK (NOMP,QUANTITE,REFERENCEP,NOMS,REFERENCES) values ('"+nomp+"','"+quantite+"','"+referencep+"','"+noms+"','"+references+"')") ;
       qry.bindValue(":NOMP",nomp);
       qry.bindValue(":QUANTITE",quantite);
       qry.bindValue(":REFERENCEP",referencep);
       qry.bindValue(":NOMS",noms);
       qry.bindValue(":REFERENCES",references);


           return qry.exec();

}

bool STOCK::modifierstock(QString nomp, QString quantite,QString referencep,QString noms,QString references)
{
    QSqlQuery query;

    query.prepare("UPDATE STOCK SET quantite= :quantite, referencep= :referencep , noms= :noms,references= :references where nomp= :nomp ");
    query.bindValue(":nomp", nomp);
    query.bindValue(":quantite",quantite);
    query.bindValue(":referencep",referencep);
    query.bindValue(":noms",noms);
    query.bindValue(":references",references);
       return    query.exec();
}

QSqlQueryModel * STOCK::afficherstock()
{


        QSqlQueryModel * model= new QSqlQueryModel();

          model->setQuery("select * from STOCK");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOMP"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("QUANTITE "));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("REFERENCEP "));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("NOMS "));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("REFERENCES "));



              return model;

}
QSqlQueryModel * STOCK ::afficher1()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from STOCK");
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("REFERENCEP "));

        return model;
}
bool STOCK::supprimerstock(QString NOMP)
{

  QSqlQuery query;
   query.prepare("Delete from STOCK where NOMP = :NOMP ");
   query.bindValue(":NOMP",NOMP);
   return    query.exec();

}
QSqlQueryModel * STOCK::sort1(){

    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from STOCK order by NOMS DESC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOMP"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("QUANTITE "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("REFERENCEP "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NOMS "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("REFERENCES "));


        return model;
}
QSqlQueryModel * STOCK :: sort2(){
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from STOCK order by REFERENCES ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOMP"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("QUANTITE "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("REFERENCEP "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NOMS "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("REFERENCES "));



        return model;
}
bool  STOCK::search(QString nomp ){
       QSqlQuery query;
           query.prepare("Select * from STOCK where nomp= :nomp");
           query.bindValue(":nomp", nomp);
           query.exec();
            QSqlQueryModel * model = new QSqlQueryModel();
          model->setQuery(query);
          if(model->rowCount() == 0){ return false;}//thabet e requete ili b3thetha el SQL heki el 7aja mawjouda wala la
       return  true;
}

void STOCK :: pdf(){
    //QDateTime datecreation = date.currentDateTime();
                //QString afficheDC = "Date de Creation PDF : " + datecreation.toString() ;
                       QPdfWriter pdf("C:\\Users\\waelk\\OneDrive\\Bureau\\C++\\PROJET\\ProjetFinal\\PDF\\pdf_stock.pdf");
                       QPainter painter(&pdf);
                      int i = 4000;
                           painter.setPen(Qt::blue);
                           painter.setFont(QFont("Arial", 30));
                           painter.drawText(1100,1200,"Liste Des Stocks");
                           painter.setPen(Qt::black);
                           painter.setFont(QFont("Arial", 15));
                          // painter.drawText(1100,2000,afficheDC);
                           painter.drawRect(100,100,7300,2600);
                           //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
                           painter.drawRect(0,3000,9600,500);
                           painter.setFont(QFont("Arial", 9));
                           painter.drawText(200,3300,"nomp");
                           painter.drawText(1200,3300,"quantite");
                           painter.drawText(2200,3300,"referencep");
                           painter.drawText(3350,3300,"noms");
                           painter.drawText(3900,3300,"references");

                           QSqlQuery query;
                           query.prepare("select * from Stock");
                           query.exec();
                           while (query.next())
                           {
                               painter.drawText(200,i,query.value(0).toString());
                               painter.drawText(1300,i,query.value(1).toString());
                               painter.drawText(2200,i,query.value(2).toString());
                               painter.drawText(3200,i,query.value(3).toString());
                               painter.drawText(3900,i,query.value(4).toString());


                              i = i + 500;
                           }


        int reponse = QMessageBox::Yes;
            if (reponse == QMessageBox::Yes)
            {
                QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                notifyIcon->show();
                notifyIcon->setIcon(QIcon("icone.png"));

                notifyIcon->showMessage("GESTION Stock ","Liste de stock pret dans PDF",QSystemTrayIcon::Information,15000);

                painter.end();
            }
            if (reponse == QMessageBox::No)
            {
                 painter.end();
            }
}

