#include "Livraison.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDialog>


livraison::livraison()
{
    this->ttc="";
    this->nom_c="";
    this->adresse="";
    this->livreur="";
    this->statue="" ;

}

livraison::livraison(QString ttc,QString nc,QString ad,QString li,QString sta)
{
    this->ttc=ttc;
    this->nom_c=nc;
    this->adresse=ad;
    this->livreur=li;
    this->statue=sta;
}



bool livraison::ajouter_livraison(){

    QSqlQuery qry;
    QSqlQuery q;
    QSqlQuery query;
    QSqlQuery queryy;
    QSqlQuery qryy;
    QSqlQuery qryyy;
    int s,n,o ;
    qryyy.exec("select count(*) from livraison") ;
    qryyy.next() ;
    o = qryyy.value(0).toInt() ;
    qry.exec("SELECT NOM_C,ADRESSE,TTC_F FROM FACTURES,CLIENT where FACTURES.ID_C=CLIENT.ID_C");
    qry.bindValue(":o",o);
    queryy.exec("select nom from livreur where statue = 'Libre'") ;
    QString nomc,add,ttc,liv;
    QString stat = "Non Livree" ;
    qryy.exec("select count(*) from livreur where statue = 'Libre'") ;
    qryy.next() ;
    s = qryy.value(0).toInt();
    n = qryy.value(0).toInt();
    while((qry.next())and(queryy.next()) and(s > 0)){
        nomc=qry.value(0).toString();
        add=qry.value(1).toString();
        ttc=qry.value(2).toString();
        liv=queryy.value(0).toString();

        query.prepare("INSERT INTO livraison (ttc,nom_c,adresse,livreur,statue) VALUES (:ttc,:nomc,:add,:liv,:stat)");
        query.bindValue(":ttc",ttc);
        query.bindValue(":nomc",nomc);
        query.bindValue(":add",add);
        query.bindValue(":liv",liv);
        query.bindValue(":stat",stat);

        s-- ;
        query.exec();
    }

}



QSqlQueryModel * livraison::afficher_livraison()
{


    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from livraison");
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom Client"));
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Total Facture"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Livreur"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Statue"));

    return model;







    /*  QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT NOM_C,ADRESSE,TTC_F FROM FACTURES,CLIENT where FACTURES.ID_C=CLIENT.ID_C");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Non Client"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Total Facture"));

    return model;

*/
}

bool livraison::supprimer_livraison(QString idd)
{
    QSqlQuery query;

    query.prepare("Delete from livraison where ttc = :id ");
    query.bindValue(":id", idd);
    return    query.exec();
}

bool livraison::livre(QString idd)
{
    QSqlQuery query;

    query.prepare("UPDATE livraison SET statue = 'Livree' WHERE ttc = :id ");
    query.bindValue(":id", idd);
    return    query.exec();
}


QSqlQueryModel * livraison::rechercher_liv_dynamique(QString a)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM livraison where nom_c like '"+a+"' ||'%'");
    query.bindValue(":id",a);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom Client"));
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Total Facture"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Livreur"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Statue"));

        return model;
}


void livraison::stat(QCustomPlot *customPlot)
{
    QSqlQuery query,query1;
    // set dark background gradient:
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
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
    fossil->setName("Livraison");
    fossil->setPen(QPen(QColor(111, 9, 176).lighter(170)));
    fossil->setBrush(QColor(111, 9, 176));
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
    query.prepare("SELECT COUNT(DISTINCT id_liv) FROM livraison where adresse='Ben Arous'");
    query.exec();
    int i;
    while(query.next())
    {
        i=query.value(0).toInt();
    }
    query.prepare("SELECT COUNT(DISTINCT id_liv) FROM livraison where adresse='Tunis'");
    query.exec();
    int j;
    while(query.next())
    {
        j=query.value(0).toInt();
    }
    query.prepare("SELECT COUNT(DISTINCT id_liv) FROM livraison where adresse='Ariana'");
    query.exec();
    int k;
    while(query.next())
    {
        k=query.value(0).toInt();
    }





    ticks << 1 << 2 << 3 ;
    labels << "[Ben Arous]" << "[Tunis]"<<"Ariana" ;
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    customPlot->xAxis->setTicker(textTicker);
    customPlot->xAxis->setTickLabelRotation(60);
    customPlot->xAxis->setSubTicks(false);
    customPlot->xAxis->setTickLength(0, 4);
    customPlot->xAxis->setRange(0, 8);
    customPlot->xAxis->setBasePen(QPen(Qt::white));
    customPlot->xAxis->setTickPen(QPen(Qt::white));
    customPlot->xAxis->grid()->setVisible(true);
    customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    customPlot->xAxis->setTickLabelColor(Qt::white);
    customPlot->xAxis->setLabelColor(Qt::white);

    // prepare y axis:
    customPlot->yAxis->setRange(0, 20);
    customPlot->yAxis->setPadding(5); // a bit more space to the left border
    customPlot->yAxis->setLabel("Intervalle de prix des factures");
    customPlot->yAxis->setBasePen(QPen(Qt::white));
    customPlot->yAxis->setTickPen(QPen(Qt::white));
    customPlot->yAxis->setSubTickPen(QPen(Qt::white));
    customPlot->yAxis->grid()->setSubGridVisible(true);
    customPlot->yAxis->setTickLabelColor(Qt::white);
    customPlot->yAxis->setLabelColor(Qt::white);
    customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

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
