#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include "Semaphore.h"

namespace Ui {
class MainMenu;
}

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = 0);
    ~MainMenu();

private slots:
    void on_pushButton_clicked();
    void open_Semaphore();

private:
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
