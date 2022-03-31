#include "pillaritem.h"
#include <QRandomGenerator>
#include <QGraphicsScene>
#include <QDebug>

PillarItem::PillarItem():
    topPillar(new QGraphicsPixmapItem(QPixmap(":/images/d2 (2).png"))),
    bottomPillar(new QGraphicsPixmapItem(QPixmap(":/images/d2 (1).png")))
{

    topPillar->setPos(QPointF(0,0) - QPointF(topPillar->boundingRect().width()/2,
                                             topPillar->boundingRect().height() + 200));

    bottomPillar->setPos(QPointF(0,0) + QPointF(-bottomPillar->boundingRect().width()/2,
                                               60));

    addToGroup(topPillar);
    addToGroup(bottomPillar);
    //ANIMATION
     yPos = QRandomGenerator::global()->bounded(150);
    int xRandomizer = QRandomGenerator::global()->bounded(200);


    setPos(QPoint(0,0)+ QPoint(260+ xRandomizer,yPos));

    xAnimation = new QPropertyAnimation(this,"x",this);
    xAnimation->setStartValue(260+xRandomizer);
    xAnimation->setEndValue(-260);
    xAnimation->setEasingCurve(QEasingCurve::Linear);
    xAnimation->setDuration(1500);

    connect(xAnimation,&QPropertyAnimation::finished,[=](){
        scene()->removeItem(this);
        qDebug()<<"Animation Finished";
        delete this;
    });
    xAnimation->start();


}

PillarItem::~PillarItem()
{
   qDebug()<<"Deleting Pillar";
}


qreal PillarItem::x() const
{
    return m_x;
}

void PillarItem::setX(qreal x)
{
    m_x = x;
    setPos(QPointF(0,0)+QPointF(x,yPos));
}
