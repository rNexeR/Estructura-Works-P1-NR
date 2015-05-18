#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include "Tarea1/Semaphore.h"
#include "Tarea2/Duplicates.h"
#include "Tarea3/Arrays.h"
#include "Tarea4/Lists.h"
#include "Tarea5/Cursores.h"
#include "Tarea6/Pilas.h"
#include "Tarea7/Colas.h"
#include "Tarea8/Conjuntos.h"
#include "Tarea8/Hashtable.h"

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

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
