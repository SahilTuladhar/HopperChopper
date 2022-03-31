#include "newwindow.h"
#include "ui_newwindow.h"
#include <QGraphicsPixmapItem>
#include "pillaritem.h"
#include "heliitem.h"


NewWindow::NewWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewWindow)
{
    ui->setupUi(this);

    //For Background
    scene = new Scene(this);

    scene -> setSceneRect(-250,-300,500,600);
    QGraphicsPixmapItem * pixItem = new QGraphicsPixmapItem(QPixmap(":/images/hg.png"));

    scene->addItem(pixItem);
    pixItem->setPos(QPointF(0,0)-QPointF(pixItem->boundingRect().width()/2,
                                         pixItem->boundingRect().height()/2));

    //scene->addLine(-400,0,400,0,QPen(Qt::blue));
    //scene->addLine(0,-400,0,400,QPen(Qt::blue));
    HeliItem *heli = new HeliItem(QPixmap(":/images/np1.png"));
    scene->addItem(heli);

    ui->graphicsView->setScene(scene);


//For Pillar
   // PillarItem *pillar = new PillarItem();
    //scene->addItem(pillar);


}

NewWindow::~NewWindow()
{
    delete ui;
}


