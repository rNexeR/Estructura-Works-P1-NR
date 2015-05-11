#ifndef CURSORES_H
#define CURSORES_H

#include <QWidget>
#include "Tarea5/Nodolist.h"

namespace Ui {
class Cursores;
}

class Cursores : public QWidget
{
    Q_OBJECT

public:
    explicit Cursores(QWidget *parent = 0);
    ~Cursores();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

private:
    Ui::Cursores *ui;
    NodoList arreglo;
};

#endif // CURSORES_H
