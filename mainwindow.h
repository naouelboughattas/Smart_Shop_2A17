#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

private slots:
    void on_pushButton_ajouter_clicked();

    void on_pushButton_modifier_clicked();

    void on_tabWidget_2_currentChanged(int index);

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_pushButton_recherche_clicked();

    void on_pushButton_ajouterabo_clicked();

    void on_pushButton_modifierabo_clicked();

    void on_tabWidget_typeabo_currentChanged(int index);

    void on_pushButton_supprimerabo_clicked();

    void on_pushButton_act_clicked();

    void on_tableView_2_activated(const QModelIndex &index);

    void on_pushButton_statistiqueabo_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
