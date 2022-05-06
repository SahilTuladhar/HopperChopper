#ifndef NEWWINDOW_H
#define NEWWINDOW_H

#include <QWidget>
#include "scene.h"
#include <QtSql>
//#include <QsqlDatabase>
#include <QtDebug>
#include <QFileInfo>
#include "fuelitem.h"
#include <QTimer>
#include "gameover.h"

extern int Fuel;

namespace Ui {
class NewWindow;
}

class NewWindow : public QWidget
{
    Q_OBJECT

public:
    explicit NewWindow(QWidget *parent = nullptr);
    ~NewWindow();



private slots:
    void on_startGameButton_clicked();
    void Collid1();


signals:
        void collideFail();
        void collideFuel();
protected:

private:
   Ui::NewWindow *ui;
    Scene *scene;

    void keyPressEvent(QKeyEvent *event);
    FuelItem *f;

    QTimer * fuelTimer;

};

#endif // NEWWINDOW_H
