#ifndef FUELITEM_H
#define FUELITEM_H

#include <QObject>
#include <QTimer>

#include <QGraphicsPixmapItem>
#include <QGraphicsItemGroup>

#include <QPropertyAnimation>



class FuelItem :public QObject, public QGraphicsItemGroup
{
    Q_OBJECT
    Q_PROPERTY(qreal x READ x WRITE setX )
public:
    explicit FuelItem();
       ~FuelItem();

    qreal x() const;
    void setX(qreal newX);
     void freezeInPlace();

signals:
    void collideFuel();
        void Collid();

public slots:

private:
    bool collidesWithFuel();
    QGraphicsPixmapItem *fItem;
    QPropertyAnimation *xAnimation;
    qreal m_x;
     int yPos;
     int fl;
};

#endif // FUELITEM_H








