#include "depot.h"
#include<QPainter>
#include<QPdfWriter>
#include<QSystemTrayIcon>
#include<QMessageBox>
depot::depot()
{
    nom="";
    adresse="";
    capacite="";

}

depot::depot(QString nom,QString adresse,QString capacite )
{
    this->nom=nom ;
    this->adresse=adresse ;
    this->capacite=capacite ;
}

bool depot::ajouterdepot()
{
    QSqlQuery qry ;
    qry.prepare("insert into Depot (NOM,ADRESSE,CAPACITE) values ('"+nom+"','"+adresse+"','"+capacite+"')") ;
       qry.bindValue(":NOM",nom);
       qry.bindValue(":ADRESSE",adresse);
       qry.bindValue(":CAPACITE",capacite);



           return qry.exec();

}

bool depot::modifierdepot(QString nom, QString adresse,QString capacite)
{
    QSqlQuery qry ;

       qry.prepare("update DEPOT set NOM='"+nom+"',ADRESSE='"+adresse+"',CAPACITE='"+capacite+"' where NOM='"+nom+"' ");
       qry.bindValue(":NOM",nom);
       qry.bindValue(":ADRESSE",adresse);
       qry.bindValue(":CAPACITE",capacite);

          return qry.exec();
}

QSqlQueryModel * depot::afficherdepot()
{
          QSqlQuery q;
          QSqlQueryModel *model=new QSqlQueryModel();
          model->setQuery("select * from DEPOT");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("ADRESSE "));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("CAPACITE "));
          return model;
}

bool depot::supprimerdepot(QString NOM)
{

  QSqlQuery query ;
  query.prepare("DELETE FROM DEPOT WHERE NOM= :NOM");
  query.bindValue(":NOM",NOM);
  return    query.exec();

}
QSqlQueryModel * depot ::afficher1()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from DEPOT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM "));
    return model;
}
bool  depot::search(QString nom ){
       QSqlQuery query;
           query.prepare("Select * from DEPOT where nom= :nom");
           query.bindValue(":nom", nom);
           query.exec();
            QSqlQueryModel * model = new QSqlQueryModel();
          model->setQuery(query);
          if(model->rowCount() == 0){ return false;}//thabet e requete ili b3thetha el SQL heki el 7aja mawjouda wala la
       return  true;
}
QSqlQueryModel * depot::sort1(){

    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from DEPOT order by NOM ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ADRESSE "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CAPACITE "));
    return model;
}
void depot :: pdf(){
    //QDateTime datecreation = date.currentDateTime();
                //QString afficheDC = "Date de Creation PDF : " + datecreation.toString() ;
                       QPdfWriter pdf("C:\\Users\\hp\\Desktop\\file3.pdf");
                       QPainter painter(&pdf);
                      int i = 4000;
                           painter.setPen(Qt::blue);
                           painter.setFont(QFont("Arial", 30));
                           painter.drawText(1100,1200,"Liste Des Depots");
                           painter.setPen(Qt::black);
                           painter.setFont(QFont("Arial", 15));
                          // painter.drawText(1100,2000,afficheDC);
                           painter.drawRect(100,100,7300,2600);
                           //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
                           painter.drawRect(0,3000,9600,500);
                           painter.setFont(QFont("Arial", 9));
                           painter.drawText(200,3300,"nom");
                           painter.drawText(1200,3300,"adresse");
                           painter.drawText(2200,3300,"capacite");
                           QSqlQuery query;
                           query.prepare("select * from DEPOT");
                           query.exec();
                           while (query.next())
                           {
                               painter.drawText(200,i,query.value(0).toString());
                               painter.drawText(1300,i,query.value(1).toString());
                               painter.drawText(2200,i,query.value(2).toString());
                              i = i + 500;
                           }


        int reponse = QMessageBox::Yes;
            if (reponse == QMessageBox::Yes)
            {
                QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                notifyIcon->show();
                notifyIcon->setIcon(QIcon("icone.png"));

                notifyIcon->showMessage("GESTION DEPOT","Liste de DEPOT pret dans PDF",QSystemTrayIcon::Information,15000);

                painter.end();
            }
            if (reponse == QMessageBox::No)
            {
                 painter.end();
            }
}

