#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employer.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void refresh();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_modifier_clicked();

    void on_pb_supprimer_clicked();

    //void on_comboBox_3_activated(const QString &arg1);

    void on_comboBox_5_activated(const QString &arg1);

    void on_cin_3_textChanged(const QString &arg1);

    void on_checkBox_2_stateChanged(int arg1);



    void on_comboBox_3_activated(int index);

private:
    Ui::MainWindow *ui;
    employer tmpemployer;
    int etat=0;
    QString valeur;
};
#endif // MAINWINDOW_H
