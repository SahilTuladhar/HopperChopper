#include "heliitem.h"
#include <QTimer>
#include <QGraphicsScene>
#include "fuelitem.h"
HeliItem::HeliItem(QPixmap pixmap):
    wingPosition(WingPosition::Up),
    wingDirection(0)


{
    setPixmap(pixmap);
    QTimer *heliWingsTimer = new QTimer(this);
    connect(heliWingsTimer,&QTimer::timeout,[=](){
        updatePixmap();
    });

    heliWingsTimer->start(80);

    groundPosition = scenePos().y() + 150 ;

    yAnimation = new QPropertyAnimation(this,"y",this);
    yAnimation->setStartValue(scenePos().y());
    yAnimation->setEndValue(groundPosition);
    yAnimation->setEasingCurve(QEasingCurve::InQuad);
    yAnimation->setDuration(1000);
   // yAnimation->start();


       rotationAnimation = new QPropertyAnimation(this,"rotation",this);
      // rotateTo(90,1200,QEasingCurve::InQuad);





}

void HeliItem::updatePixmap()
{
    if (wingPosition == WingPosition::Middle){
        if(wingDirection){
            //up
            setPixmap(QPixmap(":/images/np1.png"));
            wingPosition = WingPosition::Up;
            wingDirection =0;
        }else{
            //down
            setPixmap(QPixmap(":/images/np1.png"));
            wingPosition = WingPosition::Down;
            wingDirection =1;
        }
    }else{
        setPixmap(QPixmap(":/images/np1.png"));
      wingPosition = WingPosition::Middle;
    }
}

qreal HeliItem::rotation() const
{
    return m_rotation;
}

qreal HeliItem::y() const
{
    return m_y;
}

void HeliItem::setRotation(qreal rotation){
    m_rotation = rotation;
    QPointF c = boundingRect().center();
    QTransform t;
    t.translate(c.x(),c.y());
    t.rotate(rotation);
    t.translate(-c.x(), -c.y());
    setTransform(t);

}

void HeliItem::rotateTo(const qreal &end, const int &duration, const QEasingCurve &curve)
{
    rotationAnimation->setStartValue(rotation());
    rotationAnimation->setEndValue(end);
    rotationAnimation->setEasingCurve(curve);
    rotationAnimation->setDuration(duration);

    rotationAnimation->start();
}

void HeliItem::fallToGroundIfNecessary()
{
    if (y() < groundPosition){

        rotationAnimation->stop();
        yAnimation->stop();

        yAnimation->setStartValue(y());
        yAnimation->setEasingCurve(QEasingCurve::InQuad);
        yAnimation->setEndValue(1200);
        yAnimation->setDuration(1000);
        yAnimation->start();

        rotateTo(60,110,QEasingCurve::InCubic);
    }
}


void HeliItem::setY(qreal y)
{
    moveBy(0,y-m_y);
    m_y = y;
}

void HeliItem::shootUP()
{
    yAnimation->stop();
    rotationAnimation->stop();

    qreal curPosY = y();

    yAnimation->setStartValue(curPosY);
    yAnimation->setEndValue(curPosY - scene()->sceneRect().height()/8);
    yAnimation->setEasingCurve(QEasingCurve::OutQuad);
    yAnimation->setDuration(285);

    connect(yAnimation,&QPropertyAnimation::finished,[=](){

        fallToGroundIfNecessary();

    });

    yAnimation->start();

    rotateTo(-20,200,QEasingCurve::OutCubic);


}

void HeliItem::startFlying()
{
    yAnimation->start();
    rotateTo(90,1200,QEasingCurve::InQuad);
}

void HeliItem::freezeInPlace()
{
    yAnimation->stop();
    rotationAnimation->stop();
}


