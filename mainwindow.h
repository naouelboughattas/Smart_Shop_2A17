#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtWidgets>
#include <QMainWindow>
#include "Vehicule.h"
#include "livreur.h"
#include "Livraison.h"


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

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_9_clicked();

     void on_pushButton_8_clicked();

      void on_res_clicked();

     void on_pushButton_11_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_3_clicked();

     void on_pushButton_10_clicked();

     void on_pushButton_VE_clicked();

    void on_pushmod_clicked();

    void on_pushmod_2_clicked();

    void on_pushButton_S_clicked();

    void on_pushButton_S1_clicked();

    void on_pushButton_S2_clicked();

     void on_pushButton_tri_clicked();

      void on_pushButton_tri_2_clicked();

     void on_lineEdit_R_textEdited(const QString &arg1);

     void on_lineEdit_R_2_textEdited(const QString &arg1);

     void on_tabWidget_2_currentChanged(int index);

     void on_tabWidget_currentChanged(int index);

private:
    Ui::MainWindow *ui;
    vehicule tmpveh;
    livreur tmpliv;
    livraison tmplivraison ;
};

#endif // MAINWINDOW_H
