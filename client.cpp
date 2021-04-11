#include "client.h"
//#include<QPrinter>

CLIENT::CLIENT()
{
    cin="";
    nom="";
    prenom="";
    adresse="";
    numero="";
}

CLIENT::CLIENT(QString cin, QString nom,QString prenom,QString adresse, QString numero)
{
    this->cin=cin;
    this->nom=nom;
    this->prenom=prenom ;
    this->adresse=adresse ;
    this->numero=numero ;
}

bool CLIENT::ajouterclient()
{
    QSqlQuery qry ;
    qry.prepare("insert into CLIENT (CIN,NOM,PRENOM,ADRESSE,NUMERO) values ('"+cin+"','"+nom+"','"+prenom+"','"+adresse+"','"+numero+"')") ;
       qry.bindValue(":CIN",cin);
       qry.bindValue(":NOM",nom);
       qry.bindValue(":PRENOM",prenom);
       qry.bindValue(":ADRESSE",adresse);
       qry.bindValue(":NUMERO",numero);


           return qry.exec();

}

bool CLIENT::modifierclient()
{
    QSqlQuery qry ;

       qry.prepare("update CLIENT set CIN='"+cin+"',NOM='"+nom+"',PRENOM='"+prenom+"',ADRESSE='"+adresse+"',NUMERO='"+numero+"' where CIN='"+cin+"' ");
       qry.bindValue(":CIN",cin);
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
        q.prepare("select * from CLIENT");
        q.exec();
        modal->setQuery(q);
        ui->tableView->setModel(modal);

}

void CLIENT::selectionnerclient(Ui::MainWindow *ui,const QModelIndex &index)
{ QSqlQuery qry;
    QString val;
   val=ui->tableView->model()->data(index).toString();

   qry.prepare("SELECT * FROM CLIENT  where CIN='"+val+"' or NOM='"+val+"' or PRENOM='"+val+"' or ADRESSE='"+val+"' or NUMERO='"+val+"'");
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
    QString cin;
    cin=ui->lineEdit_cin->text();
  QSqlQuery query ;
  query.prepare("DELETE FROM CLIENT WHERE CIN='"+cin+"'");
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
       q.prepare("select * from CLIENT order by NOM");
       q.exec();
       model->setQuery(q);
       ui->tableView->setModel(model);
}

void CLIENT::TRI2(Ui::MainWindow *ui)
{
    QSqlQuery q;
       QSqlQueryModel *model=new QSqlQueryModel();
       q.prepare("select * from CLIENT order by CIN");
       q.exec();
       model->setQuery(q);
       ui->tableView->setModel(model);
}

void CLIENT::recherche(Ui::MainWindow *ui)
{
    QSqlQuery q;
        QSqlQueryModel *modal=new QSqlQueryModel();
        QString mot =ui->lineEdit_recherche->text();
        q.prepare("select * from CLIENT where (CIN LIKE '%"+mot+"%' or NOM LIKE '%"+mot+"%' or PRENOM LIKE '%"+mot+"%' )");

        q.exec() ;
        modal->setQuery(q);
        ui->tableView->setModel(modal);
}
