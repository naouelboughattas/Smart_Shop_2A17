#ifndef ZEINEBWINDOW_H
#define ZEINEBWINDOW_H

#include <QMainWindow>
#include"stock.h"
#include"depot.h"
QT_BEGIN_NAMESPACE
namespace Ui { class zeinebwindow; }
QT_END_NAMESPACE

class zeinebwindow : public QMainWindow
{
    Q_OBJECT

public:
    zeinebwindow(QWidget *parent = nullptr);
    ~zeinebwindow();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_ajouter_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_tabWidget_2_currentChanged(int index);

    void on_pushButton_2_clicked();

    void on_comboBox_2_currentIndexChanged(int index);

    void on_comboBox_2_currentTextChanged(const QString &arg1);

    void on_pushButton_4_clicked();

    void on_comboBox_3_currentIndexChanged(const QString &arg1);

    void on_pushButton_5_clicked();

    void on_pushButton_recherche_clicked();

    void on_pushButton_ajouterd_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pushButton_act_clicked();

    void on_pushButton_supprimerd_clicked();

    void on_pushButton_recherche_4_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::zeinebwindow *ui;
    STOCK tabs;
    depot tabd;
};
#endif // ZEINEBWINDOW_H
