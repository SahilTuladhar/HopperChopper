#include "fuelitem.h"
#include <QGraphicsScene>
#include <QRandomGenerator>
#include "scene.h"
#include <QPropertyAnimation>
//#include "newwindow.h"
#include "heliitem.h"



FuelItem::FuelItem() :

  fItem(new QGraphicsPixmapItem(QPixmap(":/images/fuelitem.png")))
{
    fItem->setPos(QPointF(1000,0) - QPointF(fItem->boundingRect().width()/2,
                                             fItem->boundingRect().height() + 90));
    yPos = QRandomGenerator::global()->bounded(500);
   int xRandomizer = QRandomGenerator::global()->bounded(1000);

     setPos( QPoint(300+ xRandomizer,yPos));

    xAnimation = new QPropertyAnimation(this,"x",this);
    xAnimation->setStartValue(1000+xRandomizer);
    xAnimation->setEndValue(-1000);
    xAnimation->setEasingCurve(QEasingCurve::Linear);
    xAnimation->setDuration(7000);
    connect(xAnimation,&QPropertyAnimation::finished,[=](){
        scene()->removeItem(this);
       // qDebug()<<"Animation Finished";
        delete this;
    });
    xAnimation->start();
   addToGroup(fItem);


}

FuelItem::~FuelItem()
{
   qDebug()<<"Deleting Fuel";
   delete fItem;
}

qreal FuelItem::x() const
{
    return m_x;

}

void FuelItem::setX(qreal x)
{
    m_x = x;

    setPos(QPointF(x,yPos));
    if(collidesWithFuel()==true){
     // Collid();
        emit collideFuel();
    }

}



bool FuelItem::collidesWithFuel()
{

    QList<QGraphicsItem *> list = collidingItems();
    foreach(QGraphicsItem *i , list)
    {
        HeliItem * heliItem = dynamic_cast<HeliItem *>(i);
        if (heliItem)
            return true;
    }
    return false;
}

void FuelItem::freezeInPlace()
{
    xAnimation->stop();
}
