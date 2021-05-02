#include "login.h"
#include "ui_login.h"
#include<QMessageBox>
#include<QDialog>
login::login(QWidget *parent) :
   QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    this->setWindowTitle("LOGIN");
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{

    if((ui->lineEdit->text()=="admin")&&(ui->lineEdit_2->text()=="admin"))
  {

        QMessageBox::information(this,"Sucess","Acces garanti!");
        hide();
        mDialog = new zeinebwindow(this);
        mDialog->show();

  }
      else
      {
          QMessageBox::information(this,"Erreur","Verifiez vos informations");
      }

}

