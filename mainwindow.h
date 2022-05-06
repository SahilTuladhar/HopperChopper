#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QtDebug>
#include <QFileInfo>
#include <QMediaPlayer>



#include <QGraphicsView>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT




public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
QMediaPlayer *helisong = new QMediaPlayer();

QSqlDatabase mydb;

    bool connectionStart(){
        mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("C:/Users/Nitro 5/Desktop/abce/highscores/hs.db");

        if (!mydb.open()){
            qDebug() << ("Database Fail");
            return false;
        }
        else{
            qDebug() << ("Database Connected");
            return true;
        }
    }

   /* QString logintype;
    void logintype_admin(){
        logintype="admin";
    };
    void logintype_employee(){
        logintype="employee";
    };*/


    void connectionClose(){
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();


private:
    Ui::MainWindow *ui;



};
#endif // MAINWINDOW_H
