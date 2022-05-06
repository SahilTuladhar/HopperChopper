#include "gameover.h"
#include "ui_gameover.h"
#include <QPixmap>
#include "scene.h"
#include <QMessageBox>

gameover::gameover(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameover)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Nitro 5/Desktop/Hopper_Chopper_front_end/images/GameOver.png");
    int w = ui->label_pic->width();
    int h = ui->label_pic->height();
        ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


}

gameover::~gameover()
{
    delete ui;
}

void gameover::on_pushButton_clicked()
{
    QMessageBox:: StandardButton reply = QMessageBox :: question(this,"Exit Game","Do you want to Exit the game?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
       QApplication:: quit();
    }
}


void gameover::on_pushButton_2_clicked()
{

     this->hide();
}

