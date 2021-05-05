#include "abonnement.h"

abonnement::abonnement()
{
    id="";
    cinabo="";
    type="";

}

abonnement::abonnement(QString id,QString cinabo,QString type )
{
    this->id=id ;
    this->cinabo=cinabo ;
    this->type=type ;
}

bool abonnement::ajouterabonnement()
{
    QSqlQuery qry ;
    qry.prepare("insert into Abonnement (ID,CINABO,TYPE) values ('"+id+"','"+cinabo+"','"+type+"')") ;
       qry.bindValue(":ID",id);
       qry.bindValue(":CINABO",cinabo);
       qry.bindValue(":type",type);



           return qry.exec();

}

bool abonnement::modifierabonnement()
{
    QSqlQuery qry ;

       qry.prepare("update Abonnement set ID='"+id+"',CINABO='"+cinabo+"',TYPE='"+type+"' where ID='"+id+"' ");
       qry.bindValue(":ID",id);
       qry.bindValue(":CINABO",cinabo);
       qry.bindValue(":type",type);



          return qry.exec();
}

void abonnement::afficherabonnement(Ui::MainWindow *ui)
{

        QSqlQuery q;
        QSqlQueryModel *modal=new QSqlQueryModel();
        q.prepare("select * from Abonnement");
        q.exec();
        modal->setQuery(q);
        ui->tableView_2->setModel(modal);

}
void abonnement::selectionnerabonnement(Ui::MainWindow *ui, const QModelIndex &index)
{ QSqlQuery qry;
    QString val;
   val=ui->tableView_2->model()->data(index).toString();

   qry.prepare("SELECT * FROM Abonnement  where ID='"+val+"' or CINABO='"+val+"' or TYPE='"+val+"'");
       if(qry.exec())
       {
           while (qry.next())

           {

               //ui->lineEdit_idabo->setText(qry.value(0).toString());
                //ui->lineEdit_cinabo->setText(qry.value(1).toString());
               ui->comboBox->setCurrentText(qry.value(2).toString());

           }

       }


}

bool abonnement::supprimerabonnement(Ui::MainWindow *ui)
{
    QString id;
    //id=ui->lineEdit_idabo->text();
  QSqlQuery query ;
  query.prepare("DELETE FROM Abonnement WHERE ID='"+id+"'");
  if(query.exec())
  {
              return query.exec();
  }
  else return false;

}


