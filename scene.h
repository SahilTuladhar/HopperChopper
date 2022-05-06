#ifndef SCENE_H
#define SCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include "pillaritem.h"
#include "heliitem.h"
#include "fuelitem.h"
#include "gameover.h"
#include <QMediaPlayer>


class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = nullptr);

      void addHeli();
        void startGame();
      bool getGameOn() const;
      void setGameOn(bool newGameOn);

      void increamentScore();

      void setScore(int newScore);
      void cleanPillars();
    void setUpPillarTimer();
    void setUpFuelTimer();
    void freezeItems();
    void cleanFuel();
    void freezeFuel();
    void scoree();
   QTimer * fuelTimer;

   QTimer * pillarTimer;
   HeliItem * heli;
   gameover * over;
   bool gameOn;
   int Fuel=100;
   int score;
   int highScore;


   QMediaPlayer *helisound;


signals:
    void Collid();

public slots:
      // QGraphicsScene interface
  protected:
      void keyPressEvent(QKeyEvent *event);
      void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:

};

#endif // SCENE_H
