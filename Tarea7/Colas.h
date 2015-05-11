#ifndef COLAS_H
#define COLAS_H

#include <QWidget>
#include <QMessageBox>
#include "Tarea7/Cola.h"

namespace Ui {
class Colas;
}

class Colas : public QWidget
{
    Q_OBJECT

public:
    explicit Colas(QWidget *parent = 0);
    ~Colas();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void fillList();

private:
    Ui::Colas *ui;
    Cola cola;
};

#endif // COLAS_H
