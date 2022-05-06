#include "pillaritem.h"
#include <QRandomGenerator>
#include <QGraphicsScene>
#include "scene.h"
#include "heliitem.h"

#include <QDebug>

PillarItem::PillarItem():
    topPillar(new QGraphicsPixmapItem(QPixmap(":/images/dh1_inv.png"))),
    bottomPillar(new QGraphicsPixmapItem(QPixmap(":/images/dh1png.png"))),
    pastHeli(false)
{

    topPillar->setPos(QPointF(0,0) - QPointF(topPillar->boundingRect().width()/2,
                                             topPillar->boundingRect().height() + 90));

    bottomPillar->setPos(QPointF(0,0) + QPointF(-bottomPillar->boundingRect().width()/2,
                                               70));

    addToGroup(topPillar);
    addToGroup(bottomPillar);
    //ANIMATION
     yPos = QRandomGenerator::global()->bounded(120);
    int xRandomizer = QRandomGenerator::global()->bounded(20);


    setPos(QPoint(0,0)+ QPoint(210+ xRandomizer,yPos));

    xAnimation = new QPropertyAnimation(this,"x",this);
    xAnimation->setStartValue(650+xRandomizer);
    xAnimation->setEndValue(-500);
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
   delete topPillar;
   delete bottomPillar;
}


qreal PillarItem::x() const
{
    return m_x;
}


void PillarItem::setX(qreal x)
{
    m_x = x;

    if(x < 0  && !pastHeli){
        pastHeli = true;
        QGraphicsScene * mscene = scene();
        Scene * myScene = dynamic_cast<Scene * > (mscene);
        if (myScene){
            myScene->increamentScore();
        }
    }

    if(collidesWithHeli()){

        emit collideFail();
    }

    setPos(QPointF(0,0)+QPointF(x,yPos));
}

void PillarItem::freezeInPlace()
{
    xAnimation->stop();
}

bool PillarItem::collidesWithHeli()
{
    QList<QGraphicsItem*>collidingItems = topPillar->collidingItems();
    collidingItems.append(bottomPillar->collidingItems());
    foreach(QGraphicsItem * item, collidingItems){
        HeliItem * heliItem = dynamic_cast<HeliItem*>(item);
        if (heliItem){
            return true;
        }

    }
    return false;
}
