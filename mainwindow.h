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

    void on_pushButton_2_clicked();

    void on_pdf_clicked();

    void on_impr_clicked();

    void on_modif_box_currentTextChanged(const QString &arg1);

    void on_modif_box_activated(QString index);

    void on_tabWidget_currentChanged(int index);

    void on_modif_box_editTextChanged(const QString &arg1);

    void on_modif_box_currentIndexChanged(QString index);

    void on_supr_box_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    Facture Ftemp;
    QString IDTemp;
    QString Rtemp;
};

#endif // MAINWINDOW_H
