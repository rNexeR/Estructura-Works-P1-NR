#ifndef CONJUNTOS_H
#define CONJUNTOS_H

#include <QWidget>
#include <vector>
#include "Tarea8/Conjunto.h"

namespace Ui {
class Conjuntos;
}

class Conjuntos : public QWidget
{
    Q_OBJECT

public:
    explicit Conjuntos(QWidget *parent = 0);
    ~Conjuntos();
    void fillLists();
    void fillResultadoList(Conjunto* c);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_conjunto1_currentIndexChanged(const QString &arg1);

    void on_conjunto2_currentIndexChanged(const QString &arg1);

private:
    Ui::Conjuntos *ui;
    vector<Conjunto> lconjuntos;
};

#endif // CONJUNTOS_H
