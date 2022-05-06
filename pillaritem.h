#ifndef PILLARITEM_H
#define PILLARITEM_H

#include <QGraphicsItemGroup>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>
#include <QObject>

class PillarItem :public QObject ,  public QGraphicsItemGroup
{
    Q_OBJECT
    Q_PROPERTY(qreal x READ x WRITE setX)
public:
    explicit PillarItem();
    ~PillarItem();
    qreal x() const;
    void setX(qreal newX);

    void freezeInPlace();

signals:
    void collideFail();

private:
    bool collidesWithHeli();
    QGraphicsPixmapItem *topPillar;
    QGraphicsPixmapItem * bottomPillar;
    QPropertyAnimation *xAnimation;
    int yPos;
    qreal m_x;
    bool pastHeli;
};

#endif // PILLARITEM_H
