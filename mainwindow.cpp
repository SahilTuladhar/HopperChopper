#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "newwindow.h"
#include "highscore.h"
#include <QDebug>
#include <QPixmap>
#include <QMediaPlayer>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Nitro 5/Desktop/Hopper_Chopper_front_end/images/HopperChopper.png");
    int w = ui->label_pic->width();
    int h = ui->label_pic->height();
        ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

   helisong-> setMedia(QUrl("qrc:/sound/sounds/Helisong.mp3"));

  //  helisong-> play();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    NewWindow *nw = new NewWindow();
  this->hide();
    nw->show();
    helisong->stop();
  /*StartGame stgame;
  stgame.setModal(true);
  stgame.exec();
*/

}


void MainWindow::on_pushButton_clicked()
{
    helisong->stop();
    QMessageBox:: StandardButton reply = QMessageBox :: question(this,"Exit Game","Do you want to Exit the game?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
       QApplication:: quit();
    }

}




void MainWindow::on_pushButton_3_clicked()
{
      helisong->stop();
    MainWindow conn;
        // QString name;

         QSqlQueryModel * modal=new QSqlQueryModel();

         connectionStart();
         QSqlQuery* qry=new QSqlQuery(mydb);

         qry->prepare("select HIGHSCORE from highscore");

             qry -> exec();


              modal->setQuery(*qry);
         ui->thighscore->setModel(modal);
         qry->clear();

         connectionClose();
         qDebug() <<(modal->rowCount());

   //  highscore *hg = new highscore();
     //hg->show();



}

