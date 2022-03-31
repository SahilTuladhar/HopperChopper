 #include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "newwindow.h"
#include <QDebug>
#include <QPixmap>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Nitro 5/Downloads/HopperChopper.png");
    int w = ui->label_pic->width();
    int h = ui->label_pic->height();
        ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
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
  /*StartGame stgame;
  stgame.setModal(true);
  stgame.exec();*/

}


void MainWindow::on_pushButton_clicked()
{

    QMessageBox:: StandardButton reply = QMessageBox :: question(this,"Exit Game","Do you want to Exit the game?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
       QApplication:: quit();
    }

}

