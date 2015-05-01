#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include "Tarea1/Semaphore.h"
#include "Tarea2/Duplicates.h"
#include "Tarea3/Arrays.h"
#include "Tarea4/Lists.h"

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

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
