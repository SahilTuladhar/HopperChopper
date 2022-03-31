#include "heliitem.h"
#include <QTimer>
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

    groundPosition = scenePos().y() + 290;

    yAnimation = new QPropertyAnimation(this,"y",this);
    yAnimation->setStartValue(scenePos().y());
    yAnimation->setEndValue(groundPosition);
    yAnimation->setEasingCurve(QEasingCurve::InQuad);
    yAnimation->setDuration(1000);
    yAnimation->start();


       rotationAnimation = new QPropertyAnimation(this,"rotation",this);
       rotateTo(90,1200,QEasingCurve::InQuad);





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


void HeliItem::setY(qreal y)
{
    moveBy(0,y-m_y);
    m_y = y;
}
