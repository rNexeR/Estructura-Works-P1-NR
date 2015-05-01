#ifndef LISTS_H
#define LISTS_H

#include <QWidget>
#include <QMessageBox>
#include "Listcartas.h"
#include <QStandardItem>
#include <QStandardItemModel>

namespace Ui {
class Lists;
}

class Lists : public QWidget
{
    Q_OBJECT

public:
    explicit Lists(QWidget *parent = 0);
    ~Lists();
    void fillList();

private slots:
    void on_append_clicked();

    void on_append_4_clicked();

    void on_append_2_clicked();

    void on_append_3_clicked();

private:
    Ui::Lists *ui;
    ListCartas lista;
};

#endif // LISTS_H
