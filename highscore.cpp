#include "highscore.h"
#include "mainwindow.h"
#include "ui_highscore.h"
#include <QtSql>
#include "stdio.h"
#include <QFileInfo>
highscore::highscore(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::highscore)
{
   ui->setupUi(this);

   QSqlDatabase high=QSqlDatabase::addDatabase("QSQLITE");
   high.setDatabaseName("C:/Users/Nitro 5/Desktop/abce/highscores/hs.db");

}

highscore::~highscore()
{
    delete ui;
}



