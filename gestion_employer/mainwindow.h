#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employer.h"
#include "tache.h"
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
    void refresh2();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_modifier_clicked();

    void on_trie_clicked();

    void on_trie_2_clicked();

    void on_pb_supprimer_clicked();

    void on_comboBox_3_activated(const QString &arg1);

    void on_comboBox_5_activated(const QString &arg1);

    void on_cin_3_textEdited(const QString &arg1);

    void on_checkBox_2_stateChanged(int arg1);



   // void on_comboBox_3_activated(int index);

    //void on_pb_rechercher_clicked();

    void on_pb_ajouter_2_clicked();

    void on_pb_tache_clicked();

    void on_pb_modifier_2_clicked();

    void on_comboBox_4_activated(const QString &arg1);

    void on_comboBox_6_activated(const QString &arg1);

    void on_pb_supprimer_2_clicked();

    void on_cin_4_textEdited(const QString &arg1);

    void on_pdf_clicked();

    void on_imprimer_clicked();

    void on_email_6_clicked();

private:
    Ui::MainWindow *ui;
    employer tmpemployer;
    tache tmptache;
    int etat=0;
    QString valeur;
};
#endif // MAINWINDOW_H
