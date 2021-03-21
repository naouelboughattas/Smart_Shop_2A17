#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtWidgets>
#include <QMainWindow>
#include "Vehicule.h"
#include "livreur.h"

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

    void on_pushButton_3_clicked();

    void on_pushmod_clicked();

    void on_pushmod_2_clicked();

    void on_pushButton_S_clicked();

    void on_pushButton_S1_clicked();

     void on_pushButton_tri_clicked();

      void on_pushButton_tri_2_clicked();

     void on_lineEdit_R(const QString &arg1);

private:
    Ui::MainWindow *ui;
    vehicule tmpveh;
    livreur tmpliv;
};

#endif // MAINWINDOW_H
