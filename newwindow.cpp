#include "newwindow.h"
#include "ui_newwindow.h"
#include <QGraphicsPixmapItem>
#include "pillaritem.h"
#include "heliitem.h"
#include "scene.h"
#include <QKeyEvent>
#include "fuelitem.h"
//#include <QMediaPlayer>

int Fuel;

NewWindow::NewWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewWindow)
{
    ui->setupUi(this);

    //For Background
    scene = new Scene(this);
   connect(scene,SIGNAL(Collid()),this,SLOT(Collid1()));

    scene -> setSceneRect(-250,-300,500,600);
    QGraphicsPixmapItem * pixItem = new QGraphicsPixmapItem(QPixmap(":/images/hg.png"));

    scene->addItem(pixItem);
    pixItem->setPos(QPointF(0,0)-QPointF(pixItem->boundingRect().width()/2,
                                         pixItem->boundingRect().height()/2));



    ui->graphicsView->setScene(scene);
    ui -> progressBar -> setValue(100);
    ui-> progressBar -> setRange(-1,Fuel);

    scene->addHeli();
ui->label->setText(QString("<b>Score:</b>")+ QString::number(scene->score));

}

NewWindow::~NewWindow()
{
    delete ui;
}



void NewWindow::on_startGameButton_clicked()
{
    scene->startGame();
//     ui->progressBar->setValue(100);
    Fuel = 100;
    ui-> progressBar -> setRange(-1,Fuel);

}

void NewWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key()== Qt::Key_Space){
        ui->label->setText(QString("<b>Score:</b>")+ QString::number(scene->score));
        Fuel-=3;
        ui->progressBar->setValue(Fuel);
        if (Fuel < 2 ){
           scene->pillarTimer->stop();
            scene->helisound->stop();
            scene->fuelTimer->stop();
            scene->freezeFuel();
            scene->freezeItems();
           scene-> setGameOn(false);
           gameover *over = new gameover();

             over->show();


        }


}

}

void NewWindow::Collid1(){

    Fuel+=30;
    ui->progressBar->setValue(Fuel);
}



