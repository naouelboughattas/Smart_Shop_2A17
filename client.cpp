#include "client.h"
#include<QPainter>
#include<QPdfWriter>
#include<QMessageBox>
#include<QSystemTrayIcon>


void CLIENT :: pdf(){
    //QDateTime datecreation = date.currentDateTime();
                //QString afficheDC = "Date de Creation PDF : " + datecreation.toString() ;
                       QPdfWriter pdf("C:\\pdf\\file1.pdf");
                       QPainter painter(&pdf);
                      int i = 4000;
                           painter.setPen(Qt::blue);
                           painter.setFont(QFont("Arial", 30));
                           painter.drawText(1100,1200,"Liste Des clients");
                           painter.setPen(Qt::black);
                           painter.setFont(QFont("Arial", 15));
                          // painter.drawText(1100,2000,afficheDC);
                           painter.drawRect(100,100,7300,2600);
                           //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
                           painter.drawRect(0,3000,9600,500);
                           painter.setFont(QFont("Arial", 9));
                           painter.drawText(200,3300,"ID_CLIENT");
                           painter.drawText(1200,3300,"nom");
                           painter.drawText(2200,3300,"prenom");
                           painter.drawText(3350,3300,"adresse");
                           painter.drawText(3900,3300,"numero");

                           QSqlQuery query;
                           query.prepare("select * from CLIENTS");
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

                notifyIcon->showMessage("GESTION client ","Liste des clients prete dans PDF",QSystemTrayIcon::Information,15000);

                painter.end();
            }
            if (reponse == QMessageBox::No)
            {
                 painter.end();
            }
}







CLIENT::CLIENT()
{
    ID_CLIENT="";
    nom="";
    prenom="";
    adresse="";
    numero="";
}

CLIENT::CLIENT(QString ID_CLIENT, QString nom,QString prenom,QString adresse, QString numero)
{
    this->ID_CLIENT=ID_CLIENT;
    this->nom=nom;
    this->prenom=prenom ;
    this->adresse=adresse ;
    this->numero=numero ;
}

bool CLIENT::ajouterclient()
{
    QSqlQuery qry ;
    qry.prepare("insert into CLIENTS (ID_CLIENT,NOM_C,PRENOM,ADRESSE,NUMERO) values ('"+ID_CLIENT+"','"+nom+"','"+prenom+"','"+adresse+"','"+numero+"')") ;
       qry.bindValue(":ID_CLIENT",ID_CLIENT);
       qry.bindValue(":NOM",nom);
       qry.bindValue(":PRENOM",prenom);
       qry.bindValue(":ADRESSE",adresse);
       qry.bindValue(":NUMERO",numero);


           return qry.exec();

}

bool CLIENT::modifierclient()
{
    QSqlQuery qry ;

       qry.prepare("update CLIENTS set ID_CLIENT='"+ID_CLIENT+"',NOM_C='"+nom+"',PRENOM='"+prenom+"',ADRESSE='"+adresse+"',NUMERO='"+numero+"' where ID_CLIENT='"+ID_CLIENT+"' ");
       qry.bindValue(":ID_CLIENT",ID_CLIENT);
       qry.bindValue(":NOM",nom);
       qry.bindValue(":PRENOM",prenom);
       qry.bindValue(":ADRESSE",adresse);
       qry.bindValue(":NUMERO",numero);


          return qry.exec();
}

void CLIENT::afficherclient(Ui::MainWindow *ui)
{

        QSqlQuery q;
        QSqlQueryModel *modal=new QSqlQueryModel();
        q.prepare("select * from CLIENTS");
        q.exec();
        modal->setQuery(q);
        ui->tableView_3->setModel(modal);

}

void CLIENT::selectionnerclient(Ui::MainWindow *ui,const QModelIndex &index)
{ QSqlQuery qry;
    QString val;
   val=ui->tableView_3->model()->data(index).toString();

   qry.prepare("SELECT * FROM CLIENTS  where ID_CLIENT='"+val+"' or NOM_C='"+val+"' or PRENOM='"+val+"' or ADRESSE='"+val+"' or NUMERO='"+val+"'");
       if(qry.exec())
       {
           while (qry.next())

           {

               ui->lineEdit_cin->setText(qry.value(0).toString());
                ui->lineEdit_nom->setText(qry.value(1).toString());
                ui->lineEdit_prenom->setText(qry.value(2).toString());
                ui->lineEdit_adresse->setText(qry.value(3).toString());
                ui->lineEdit_num->setText(qry.value(4).toString());
           }

       }


}

bool CLIENT::supprimerclient(Ui::MainWindow *ui)
{
    QString ID_CLIENT;
    ID_CLIENT=ui->lineEdit_cin->text();
  QSqlQuery query ;
  query.prepare("DELETE FROM CLIENTS WHERE ID_CLIENT='"+ID_CLIENT+"'");
  if(query.exec())
  {
              return query.exec();
  }
  else return false;


}

void CLIENT::TRI1(Ui::MainWindow *ui)
{
    QSqlQuery q;
       QSqlQueryModel *model=new QSqlQueryModel();
       q.prepare("select * from CLIENTS order by NOM_C");
       q.exec();
       model->setQuery(q);
       ui->tableView_3->setModel(model);
}

void CLIENT::TRI2(Ui::MainWindow *ui)
{
    QSqlQuery q;
       QSqlQueryModel *model=new QSqlQueryModel();
       q.prepare("select * from CLIENTS order by ID_CLIENT");
       q.exec();
       model->setQuery(q);
       ui->tableView_3->setModel(model);
}

void CLIENT::recherche(Ui::MainWindow *ui)
{
    QSqlQuery q;
        QSqlQueryModel *modal=new QSqlQueryModel();
        QString mot =ui->lineEdit_recherche_2->text();
        q.prepare("select * from CLIENTS where (ID_CLIENT LIKE '%"+mot+"%' or NOM_C LIKE '%"+mot+"%' or PRENOM LIKE '%"+mot+"%' )");

        q.exec() ;
        modal->setQuery(q);
        ui->tableView_3->setModel(modal);
}
