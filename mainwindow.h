#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "produit.h"
#include <QString>
#include<QSqlQueryModel>
#include <QTableView>
#include "categorie.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_lineEdit_textEdited(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_tab_12_currentChanged(int index);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();
    // categorie
    void on_pb_ajouter_cat_clicked();

    void on_pb_modifier_2_cat_clicked();

    void on_pb_supprimer_2_cat_clicked();

    void on_lineEdit_2_cat_textEdited(const QString &arg1);

    void on_pushButton_5_cat_cat_clicked();

    void on_tab_12_cat_currentChanged(int index);

    void on_pushButton_5_cat_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_supr_prod_2_activated(const QString &arg1);

    void on_supr_prod_activated(const QString &arg1);

    void on_pdff_clicked();

    void on_pdff_2_clicked();

private:
    Ui::MainWindow *ui;
    Produit P;
    Categorie C;

};
#endif // MAINWINDOW_H
