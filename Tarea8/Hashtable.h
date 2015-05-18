#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <QWidget>
#include "Tarea8/Conjunto.h"

namespace Ui {
class HashTable;
}

class HashTable : public QWidget
{
    Q_OBJECT

public:
    explicit HashTable(QWidget *parent = 0);
    ~HashTable();
    int hash(string val);
    void fillList();


private slots:
    void on_pushButton_clicked();

private:
    Ui::HashTable *ui;
    Conjunto words[26];
};

#endif // HASHTABLE_H
