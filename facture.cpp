#include "facture.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QTableView>
#include <QDateTime>
#include <QDate>
#include <QTime>
#include <QSqlRecord>

Facture::Facture()
{
id_f="";
date_f=QDateTime(QDate(2000,01,01),QTime(00,00,00));
ttc_f="";
mode_f="";
nom_c="";
}
Facture::Facture(QString id_f,QDateTime date_f,QString ttc_f, QString mode_f, QString nom_c){
    this->id_f=id_f;
    this->date_f=date_f;
    this->ttc_f=ttc_f;
    this->mode_f=mode_f;
    this->nom_c=nom_c;

}
QString Facture::getid_f(){
    return id_f;
}
QDateTime Facture::getdate_f(){
    return date_f;
}
QString Facture::getttc_f(){
    return ttc_f;
}
QString Facture::getmode_f(){
    return mode_f;
}
QString Facture::getnom_c(){
    return nom_c;
}
void Facture::setid_f(QString id_f){
    this->id_f=id_f;
}
void Facture::setdate_f(QDateTime date_f){
    this->date_f=date_f;
}
void Facture::setttc_f(QString ttc_f){
    this->ttc_f=ttc_f;
}
void Facture::setmode_f(QString mode_f){
    this->mode_f=mode_f;
}
void Facture::setnom_c(QString nom_c){
    this->nom_c=nom_c;
}
bool Facture::ajouter(){
    bool test=true;
    QSqlQuery query;
    QString id_string= id_f;
          query.prepare("INSERT INTO FACTURES (ID_F, DATE_F, TTC_F, MODE_P_F,ID_C) "
                        "VALUES (:id_f, :forename, :surname, :mode_f, :nom_c)");
          query.bindValue(":id_f", id_string);
          query.bindValue(":forename", date_f);
          query.bindValue(":surname", ttc_f);
          query.bindValue(":mode_f", mode_f);
          query.bindValue(":nom_c", nom_c);
          if(query.exec()){
            return test;
          }else{
            return false;
          }
}
QSqlQueryModel *Facture::afficher(){
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT ID_F, NOM_C, DATE_F, MODE_P_F, TTC_F FROM FACTURES, CLIENTS where FACTURES.ID_C=CLIENTS.ID_CLIENT ORDER BY DATE_F DESC");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("Référence"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Client"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("Paiement"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("Total TTC"));
          return model;
}
bool Facture::supprimer(QString id_f){
    QSqlQuery query;

    query.prepare("DELETE FROM FACTURES WHERE ID_F = :id_f ");
    query.bindValue(":id_f", id_f);
    return    query.exec();
}
bool Facture::modifier(QString id_f,QDateTime date_f,QString ttc_f,QString mode_f,QString nom_c)
{
    QSqlQuery query;
    query.prepare("UPDATE FACTURES SET date_f= :date_f,ttc_f = :ttc_f,MODE_P_F= :mode_f,ID_C = :nom_c WHERE id_f= :id_f ");
    query.bindValue(":id_f",id_f);
    query.bindValue(":date_f",date_f);
    query.bindValue(":ttc_f",ttc_f);
    query.bindValue(":mode_f",mode_f);
    query.bindValue(":nom_c",nom_c);
    return    query.exec();
}
QSqlQueryModel * Facture::rechercher(QString a)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT ID_F, NOM_C, DATE_F, MODE_P_F, TTC_F FROM FACTURES, CLIENTS where FACTURES.ID_C=CLIENTS.ID_CLIENT AND ID_F like '"+a+"' ||'%' OR DATE_F like '"+a+"' ||'%' OR TTC_F like '"+a+"' ||'%' OR MODE_P_F like '"+a+"' OR NOM_C like '"+a+"' ||'%' ORDER BY DATE_F DESC ");
    query.bindValue(":id",a);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Référence"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Client"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Paiement"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Total TTC"));
    return model;
}
QSqlQueryModel * Facture::tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT ID_F, NOM_C, DATE_F, MODE_P_F, TTC_F FROM FACTURES, CLIENTS where FACTURES.ID_C=CLIENTS.ID_CLIENT ORDER BY ID_F DESC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Référence"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Client"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Paiement"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Total TTC"));
    return model;
}
QStringList Facture::recherche_id(){
    QSqlQuery query;
    query.prepare("select * from FACTURES ORDER BY ID_F ASC");
    query.exec();
    QStringList list;
    while(query.next()){
        list.append(query.value(0).toString());
    }

    return list;

}
QStringList Facture::recherche_client(){
    QSqlQuery query;
    query.prepare("select NOM_C from CLIENTS");
    query.exec();
    QStringList list;
    while(query.next()){
        list.append(query.value(0).toString());
    }

    return list;

}
Facture Facture::search_id(QString id_f){
    QSqlQuery query;
    query.prepare("select *from FACTURES where ID_F=:id_f");
    query.bindValue(":ID_F",id_f);
    query.exec();
    Facture p;
    while(query.next()){
        p.setid_f(query.value(0).toString());
        p.setdate_f(query.value(1).toDateTime());
        p.setttc_f(query.value(2).toString());

    }


    return p;
}
QString Facture::COUNT_FACT(){
    QSqlQuery query; int l=0;
    query.prepare("SELECT COUNT(*) FROM FACTURES;");
    query.exec();
    while(query.next()){
        l=query.value(0).toInt();
    }
    l++;
    return QString::number(l);
}
QString Facture::remplir(){
    QSqlQuery qy;
    int res=0;
    QString ref;
    ref="#FC000"+QString::number(res);
    QSqlQuery qyr;
    qyr.prepare("SELECT ID_F FROM FACTURES WHERE ID_F LIKE :id_f");
    qyr.bindValue(":id_f",ref);
    qyr.exec();
    while(qyr.next()){
    if(qyr.value(0).toString()==ref){
        res++;
        ref="#FC000"+QString::number(res);

    }

    qy.prepare("SELECT COUNT(*) FROM FACTURES");
    qy.exec();
    while(qy.next()){
    res=qy.value(0).toInt();
    }
    res++;
    }

  return  ref="#FC000"+QString::number(res);
}
QString Facture::recherche_nom_client(){
    QSqlQuery query;
    query.prepare("select NOM_C from CLIENTS");
    query.exec();
    QString list;
    while(query.next()){
        list=query.value(0).toString();
    }

    return list;

}
QStringList Facture::recherche_idclient(){
    QSqlQuery query;
    query.prepare("select distinct ID_CLIENT from CLIENTS");
    query.exec();
    QStringList list;
    while(query.next()){
        list.append(query.value(0).toString());
    }

    return list;

}

QString Facture::search_nom_c(QString nom_c){
    QSqlQuery qr;
    QString resu;
    qr.prepare("SELECT NOM_C FROM FACTURES, CLIENTS where FACTURES.ID_C=CLIENTS.ID_CLIENT AND ID_F=:waa");
    qr.bindValue(":waa",nom_c);
    qr.exec();
    while(qr.next()){
   resu=qr.value(0).toString();
    }
return resu;
}
QString Facture::mode_pp(QString mode_p){
    QSqlQuery qr;
    QString resu;
    qr.prepare("SELECT MODE_P_F FROM FACTURES, CLIENTS where FACTURES.ID_C=CLIENTS.ID_CLIENT AND ID_F=:waa");
    qr.bindValue(":waa",mode_p);
    qr.exec();
    while(qr.next()){
   resu=qr.value(0).toString();
    }
return resu;
}
QString Facture::date_ff(QString dat_info){
    QSqlQuery qr;
    QString resu;
    qr.prepare("SELECT DATE_F FROM FACTURES, CLIENTS where FACTURES.ID_C=CLIENTS.ID_CLIENT AND ID_F=:waa");
    qr.bindValue(":waa",dat_info);
    qr.exec();
    while(qr.next()){
   resu=qr.value(0).toString();
    }
return resu;
}
QString Facture::total_ttc(QString total_ttc){
    QSqlQuery qr;
    QString resu;
    qr.prepare("SELECT TTC_F FROM FACTURES, CLIENTS where FACTURES.ID_C=CLIENTS.ID_CLIENT AND ID_F=:waa");
    qr.bindValue(":waa",total_ttc);
    qr.exec();
    while(qr.next()){
   resu=qr.value(0).toString();
    }
return resu;
}
QString Facture::stat_count(){
    QSqlQuery qr;
    QString resu;
    qr.prepare("SELECT COUNT(*) From FACTURES");
    qr.exec();
    while(qr.next()){
   resu=qr.value(0).toString();
    }
return resu;
}
QString Facture::max_p(){
    QSqlQuery qr;
    QString resu;
    qr.prepare("SELECT MAX(TTC_F) From FACTURES");
    qr.exec();
    while(qr.next()){
   resu=qr.value(0).toString();
    }
return resu;
}
QString Facture::min_p(){
    QSqlQuery qr;
    QString resu;
    qr.prepare("SELECT MIN(TTC_F) From FACTURES");
    qr.exec();
    while(qr.next()){
   resu=qr.value(0).toString();
    }
return resu;
}
QString Facture::top_cc(){
    QSqlQuery qr;
    QString resu;
    qr.prepare("SELECT MAX(ID_C) From FACTURES;");
    qr.exec();
    while(qr.next()){
   resu=qr.value(0).toString();
    }
return resu;
}
QString Facture::top_c(){
    QSqlQuery qr;
    QString resu;
    qr.prepare("SELECT MAX(NOM_C) FROM FACTURES, CLIENTS where FACTURES.ID_C=CLIENTS.ID_CLIENT");
    qr.exec();
    while(qr.next()){
   resu=qr.value(0).toString();
    }
return resu;
}

void Facture::stat(QCustomPlot *customPlot)
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
    fossil->setName("Factures");
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
    query.prepare("SELECT COUNT(DISTINCT id_f) FROM factures where ttc_f between 0 and 100");
    query.exec();
    int i;
    while(query.next())
    {
        i=query.value(0).toInt();
    }
    query.prepare("SELECT COUNT(DISTINCT id_f) FROM factures where ttc_f between 100 and 1000");
    query.exec();
    int j;
    while(query.next())
    {
        j=query.value(0).toInt();
    }
    query.prepare("SELECT COUNT(DISTINCT id_f) FROM factures where ttc_f > 1000");
    query.exec();
    int k;
    while(query.next())
    {
        k=query.value(0).toInt();
    }





    ticks << 1 << 2 << 3 ;
    labels << "[0,100]" << "[100,1000]"<<"Plus que 1000" ;
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


