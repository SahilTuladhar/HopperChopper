#ifndef HELIITEM_H
#define HELIITEM_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include  <QPropertyAnimation>
class HeliItem : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
   Q_PROPERTY(qreal rotation READ rotation WRITE setRotation );
    Q_PROPERTY(qreal y READ y WRITE setY  );
public:
    explicit HeliItem(QPixmap pixmap);

    qreal rotation() const;

    qreal y() const;
    void setY(qreal newY);

signals:

public slots:
    void setRotation(qreal rotation);

    void rotateTo(const qreal &end , const int& duration, const QEasingCurve& curve);

private:
    enum WingPosition {
        Up,
        Middle,
        Down
    };
   void updatePixmap();
   WingPosition wingPosition;
   bool wingDirection; // 0:down , 1:up


   qreal m_rotation;
   qreal m_y;
   QPropertyAnimation * yAnimation;
   QPropertyAnimation * rotationAnimation;
   qreal groundPosition;
};

#endif // HELIITEM_H
