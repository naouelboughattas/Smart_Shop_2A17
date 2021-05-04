#include "produit.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QTableView>

Produit::Produit()
{id_P=0; nom_P=""; type=""; prix=0;
}

Produit::Produit(int id_P,QString nom_P,QString type,int prix)
{   this->id_P=id_P;
    this->nom_P=nom_P;
    this->type=type;
    this->prix=prix;
}

int Produit::getid_P(){return id_P;}
QString Produit::getnom_P(){return nom_P;}
QString Produit::gettype(){return type;}
int Produit::getprix(){return prix;}

void Produit::setid_P(int id_P){ this->id_P=id_P;}
void Produit::setnom_P(QString nom_P){ this->nom_P=nom_P;}
void Produit::settype(QString type){ this->type=type;}
void Produit::setprix(int prix){ this->prix=prix;}
bool Produit::ajouter()
{
    QString id_string=QString::number(id_P);
    QSqlQuery query;
        query.prepare("INSERT INTO produits (id_P, nom_P, type,prix) "
                      "VALUES (:id_P, :nom_P, :type, :prix)");
         query.bindValue(":id_P",id_P);
         query.bindValue(":nom_P",nom_P);
         query.bindValue(":type",type);
         query.bindValue(":prix",prix);
         return query.exec();
}
bool Produit::supprimer(int id_P)
{
    QSqlQuery query;
        query.prepare("Delete from produits where id_P=:id_P ");
         query.bindValue(":id_P",id_P);

         return query.exec();

}
QSqlQueryModel* Produit::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();


    model->setQuery("SELECT* FROM produits");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id Produit"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom Produit"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type Produit"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix Produit"));

    return model;
}
bool Produit::modifier(int id_P,QString nom_P,QString type,int prix)
{
    QSqlQuery query;
    query.prepare("UPDATE produits SET nom_P= :nom_P,type= :type,prix= :prix WHERE id_P= :id_P");
    query.bindValue(":id_P",id_P);
    query.bindValue(":nom_P",nom_P);
    query.bindValue(":type",type);
    query.bindValue(":prix",prix);
    return query.exec();

}
QSqlQueryModel* Produit::tri()
{
    QSqlQueryModel* model=new QSqlQueryModel();


    model->setQuery("SELECT* FROM produits ORDER BY prix");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id Produit"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom Produit"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type Produit"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix Produit"));

    return model;
}
QSqlQueryModel* Produit::recherche(QString r)
{
    QSqlQueryModel* model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT* FROM produits WHERE id_P like '"+r+"' ||'%' OR nom_P like '"+r+"' ||'%' OR type like '"+r+"' ||'%' OR prix like '"+r+"' ");
    query.bindValue(":id",r);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id Produit"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom Produit"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type Produit"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix Produit"));

    return model;
}
QStringList Produit::recherche_id_produit(){
    QSqlQuery query;
    query.prepare("select id_P from PRODUITS");
    query.exec();
    QStringList list;
    while(query.next()){
        list.append(query.value(0).toString());
    }

    return list;

}
void Produit::statistic(QCustomPlot *customPlot)
{
    QSqlQuery query,query1;
    // set dark background gradient:
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(255, 255, 255));
    gradient.setColorAt(0.38, QColor(255, 255, 255));
    gradient.setColorAt(1, QColor(255, 255, 255));
    customPlot->clearPlottables();
    customPlot->clearGraphs();
    customPlot->replot();

    customPlot->setBackground(QBrush(gradient));

    // create empty bar chart objects:
   // QCPBars *regen = new QCPBars(customPlot->xAxis, customPlot->yAxis);
   // QCPBars *nuclear = new QCPBars(customPlot->xAxis, customPlot->yAxis);
    QCPBars *fossil = new QCPBars(customPlot->xAxis, customPlot->yAxis);
  //  regen->setAntialiased(false); // gives more crisp, pixel aligned bar borders
  //  nuclear->setAntialiased(false);
    fossil->setAntialiased(false);
  //  regen->setStackingGap(1);
    //nuclear->setStackingGap(1);
    fossil->setStackingGap(1);
    // set names and colors:
    fossil->setName("Produit");
    fossil->setPen(QPen(QColor(0, 128, 255).lighter(170)));
    fossil->setBrush(QColor(0, 128, 255));
  //  nuclear->setName("Nuclear");
  //  nuclear->setPen(QPen(QColor(250, 170, 20).lighter(150)));
  //  nuclear->setBrush(QColor(250, 170, 20));
   // regen->setName("Regenerative");
  //  regen->setPen(QPen(QColor(0, 168, 140).lighter(130)));
  //  regen->setBrush(QColor(0, 168, 140));
    // stack bars on top of each other:
  //  nuclear->moveAbove(fossil);
 //   regen->moveAbove(nuclear);

    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
    query.prepare("SELECT COUNT(DISTINCT id_p) FROM produits where prix between 0 and 50");
    query.exec();
    int i;
    while(query.next())
    {
        i=query.value(0).toInt();
    }
    query.prepare("SELECT COUNT(DISTINCT id_p) FROM produits where prix between 50 and 100");
    query.exec();
    int ii;
    while(query.next())
    {
        ii=query.value(0).toInt();
    }

    query.prepare("SELECT COUNT(DISTINCT id_p) FROM produits where prix between 100 and 1000");
    query.exec();
    int j;
    while(query.next())
    {
        j=query.value(0).toInt();
    }
    query.prepare("SELECT COUNT(DISTINCT id_p) FROM produits where prix > 1000");
    query.exec();
    int k;
    while(query.next())
    {
        k=query.value(0).toInt();
    }





    ticks << 1 << 2 << 3 << 4 ;
    labels << "[ 0 DT,50 DT ]"<< "[ 50 DT,100 DT ]" << "[ 100 DT,1000 DT ]"<<"Plus que 1000 DT" ;
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    customPlot->xAxis->setTicker(textTicker);
    customPlot->xAxis->setTickLabelRotation(60);
    customPlot->xAxis->setSubTicks(false);
    customPlot->xAxis->setTickLength(0, 4);
    customPlot->xAxis->setRange(0, 8);
    customPlot->xAxis->setBasePen(QPen(Qt::black));
    customPlot->xAxis->setTickPen(QPen(Qt::black));
    customPlot->xAxis->grid()->setVisible(true);
    customPlot->xAxis->grid()->setPen(QPen(QColor(0, 0, 0), 0, Qt::DotLine));
    customPlot->xAxis->setTickLabelColor(Qt::black);
    customPlot->xAxis->setLabelColor(Qt::black);

    // prepare y axis:
    customPlot->yAxis->setRange(0, 20);
    customPlot->yAxis->setPadding(5); // a bit more space to the left border
    customPlot->yAxis->setLabel("Intervalle de prix des produits");
    customPlot->yAxis->setBasePen(QPen(Qt::black));
    customPlot->yAxis->setTickPen(QPen(Qt::black));
    customPlot->yAxis->setSubTickPen(QPen(Qt::black));
    customPlot->yAxis->grid()->setSubGridVisible(true);
    customPlot->yAxis->setTickLabelColor(Qt::black);
    customPlot->yAxis->setLabelColor(Qt::black);
    customPlot->yAxis->grid()->setPen(QPen(QColor(0, 0, 0), 0, Qt::SolidLine));
    customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(0, 0, 0), 0, Qt::DotLine));

    // Add data:
    QVector<double> fossilData, nuclearData, regenData;
    fossilData  << i << j << k;
   // nuclearData << 0.08*10.5 << 0.12*5.5 << 0.12*5.5 << 0.40*5.8 << 0.09*5.2 << 0.00*4.2 << 0.07*11.2;
    regenData   << 0.06*10.5 << 0.05*5.5 << 0.04*5.5 << 0.06*5.8 << 0.02*5.2 << 0.07*4.2 << 0.25*11.2;
    fossil->setData(ticks, fossilData);
  //  nuclear->setData(ticks, nuclearData);
 //   regen->setData(ticks, regenData);

    // setup legend:
    customPlot->legend->setVisible(true);
    customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    customPlot->legend->setBrush(QColor(255, 255, 255, 100));
    customPlot->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = QFont();
    legendFont.setPointSize(10);
    customPlot->legend->setFont(legendFont);
    customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

}
