#ifndef NEWWINDOW_H
#define NEWWINDOW_H

#include <QWidget>
#include "scene.h"
namespace Ui {
class NewWindow;
}

class NewWindow : public QWidget
{
    Q_OBJECT

public:
    explicit NewWindow(QWidget *parent = nullptr);
    ~NewWindow();

private:
    Ui::NewWindow *ui;
    Scene *scene;

};

#endif // NEWWINDOW_H
