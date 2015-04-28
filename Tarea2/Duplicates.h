#ifndef DUPLICATES_H
#define DUPLICATES_H

#include <QWidget>
#include <QStandardItem>
#include <QStandardItemModel>
#include <vector>
#include <iostream>
using namespace std;

namespace Ui {
class Duplicates;
}

class Duplicates : public QWidget
{
    Q_OBJECT

public:
    explicit Duplicates(QWidget *parent = 0);
    ~Duplicates();

private slots:
    void on_btnadd_clicked();

    void on_btnquitar_clicked();

private:
    Ui::Duplicates *ui;
    vector<QString> lista;
    bool search(vector<QString> lista, QString valor);
};

#endif // DUPLICATES_H
