#ifndef PILAS_H
#define PILAS_H

#include <QWidget>
#include <QMessageBox>
#include "Tarea6/Pila.h"

namespace Ui {
class Pilas;
}

class Pilas : public QWidget
{
    Q_OBJECT

public:
    explicit Pilas(QWidget *parent = 0);
    ~Pilas();
    Pila pila;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void getTope();

private:
    Ui::Pilas *ui;
};

#endif // PILAS_H
