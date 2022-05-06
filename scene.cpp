#include "scene.h"
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QtDebug>
#include "newwindow.h"
#include "fuelitem.h"
#include "mainwindow.h"
#include <QFont>

Scene::Scene(QObject *parent):QGraphicsScene(parent),
    gameOn(false),score(0),
    highScore(0)
{
 setUpPillarTimer();
    setUpFuelTimer();
 helisound = new QMediaPlayer();
 helisound-> setMedia(QUrl("qrc:/sound/sounds/Helisound.mp3"));

}

void Scene::addHeli()
{
    heli = new HeliItem(QPixmap(":/images/np1.png"));
    addItem(heli);
}


void Scene::setUpPillarTimer()
{
    pillarTimer = new QTimer(this);
    connect(pillarTimer,&QTimer::timeout,[=](){

        PillarItem * pillarItem = new PillarItem();
        connect(pillarItem,&PillarItem::collideFail,[=](){
            pillarTimer->stop();
            helisound->stop();
            freezeItems();
            freezeFuel();
            fuelTimer->stop();
            setGameOn(false);
          gameover *over = new gameover();

            over->show();

        });

addItem(pillarItem);
    });
    }

void Scene::setUpFuelTimer()
{

    fuelTimer = new QTimer(this);
    connect(fuelTimer,&QTimer::timeout,[=](){
    FuelItem * fItem = new FuelItem();
    connect (fItem,&FuelItem::collideFuel,[=](){
            emit Collid();
        delete fItem;

        qDebug()<<"collided with fuel item";
    });
    addItem(fItem);

});


}

void Scene::startGame()
{
    //heli
    heli->startFlying();
    //Pillars
    if(!pillarTimer->isActive()){
        cleanPillars();
       cleanFuel();
        setGameOn(true);
        setScore(0);
        pillarTimer->start(1000);
        fuelTimer->start(5000);

    }

}


void Scene::freezeItems()
{
    //freeze heli
    heli->freezeInPlace();

    //freeze pillar
    QList<QGraphicsItem *> sceneItems = items();
    foreach (QGraphicsItem * item, sceneItems){
        PillarItem * pillar = dynamic_cast<PillarItem *>(item);
        if (pillar){
            pillar->freezeInPlace();
        }

    }

}

void Scene::freezeFuel(){
    QList<QGraphicsItem *> list = items();
    foreach(QGraphicsItem *i , list)
    {
        FuelItem * fuelItem = dynamic_cast<FuelItem *>(i);
        if (fuelItem)
             fuelItem->freezeInPlace();
    }


}

void Scene::setScore(int newScore)
{
    score = newScore;
}

bool Scene::getGameOn() const
{
    return gameOn;
}

void Scene::setGameOn(bool newGameOn)
{
    gameOn = newGameOn;
}

void Scene::increamentScore()
{
    score++;
    MainWindow conn;
           QString highscore, scor, hscore;
           int hiscore;


            conn.connectionStart();
            QSqlQuery *qry=new QSqlQuery(conn.mydb);

            qry->prepare("select HIGHSCORE from highscore");
            qry->exec();
            scor=QString::number(score);

            while(qry->next()){
                highscore = qry->value(0).toString();
                hiscore=highscore.toInt();
                if (score>hiscore){
                    hscore=scor;
                    qry->prepare("UPDATE highscore SET HIGHSCORE='"+hscore+"'");
                    qry->exec();
                }
                else{
                    hscore=highscore;
                }
            }


            qry->clear();

            conn.connectionClose();


    /*if (score > highScore)
            highScore = score;*/
    qDebug() << "Score: " << score <<"High Score: " <<hscore ;

}

void Scene::keyPressEvent(QKeyEvent *event)
{
    if(event->key()== Qt::Key_Space){
        if(gameOn){
             heli->shootUP();
             if(helisound->state() == QMediaPlayer::PlayingState){
             helisound->setPosition(0);





        }
             else if(helisound->state() == QMediaPlayer::StoppedState){

                 helisound->play();
             }

    }

    QGraphicsScene::keyPressEvent(event);
}
}


void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        if(gameOn){
            heli->shootUP();
        if(helisound->state() == QMediaPlayer::PlayingState){
        helisound->setPosition(0);
         }
        else if(helisound->state() == QMediaPlayer::StoppedState){

            helisound->play();
        }
        }

}
QGraphicsScene::mousePressEvent(event);
    }



void Scene::cleanPillars()
{
QList<QGraphicsItem *> sceneItems = items();
foreach (QGraphicsItem * item, sceneItems){
    PillarItem * pillar = dynamic_cast<PillarItem *>(item);
    if (pillar){
        removeItem(pillar);
        delete pillar;
    }
}

}

void Scene::cleanFuel(){

    QList<QGraphicsItem *> list = items();
    foreach(QGraphicsItem *i , list)
    {
        FuelItem * fuelItem = dynamic_cast<FuelItem *>(i);
        if (fuelItem)
            removeItem(fuelItem);
        delete fuelItem;
    }

}


