#ifndef ARRAYS_H
#define ARRAYS_H

#include <QWidget>
#include <QStandardItem>
#include <QStandardItemModel>
#include <iostream>
using namespace std;

namespace Ui {
class Arrays;
}

class Arrays : public QWidget
{
    Q_OBJECT

public:
    explicit Arrays(QWidget *parent = 0);
    int tam = 15, actual = 0;
    ~Arrays();
    int search(QString valor);
    void clear();
    bool append(QString valor);
    bool insert(int pos, QString valor);
    bool suprim(int pos);
    void fillColumns();


private slots:

    void on_append_clicked();

    void on_append_2_clicked();

    void on_append_3_clicked();

    void on_append_4_clicked();

private:
    Ui::Arrays *ui;
    QString arreglo[15];
};

#endif // ARRAYS_H
