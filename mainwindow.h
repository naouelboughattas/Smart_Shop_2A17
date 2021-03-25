#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include<QSqlQueryModel>
#include <stdlib.h>
#include <facture.h>
#include <QTableView>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pushButton_clicked();

    void on_supp_clicked();

    void on_pb_modifier_clicked();

    void on_lineEdit_textEdited(const QString &arg1);

    void on_pdf_clicked();

    void on_impr_clicked();

    void on_modif_box_currentTextChanged(const QString &arg1);

    void on_tabWidget_currentChanged(int index);

    void on_supr_box_currentIndexChanged(int index);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();
  //  int * recherche_id_client(QString);

    void on_modif_le_client_activated(const QString &arg1);

    void on_modif_box_currentIndexChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    Facture Ftemp;
    QString IDTemp;
    QString Rtemp;
    QString Ctemp;
};

#endif // MAINWINDOW_H
