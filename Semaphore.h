#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include <QWidget>
#include <QMessageBox>
#include <vector>
#include "Calle.h"
//#include "Semaphore.ui"

namespace Ui {
class Semaphore;
}

class Semaphore : public QWidget
{
    Q_OBJECT

public:
    explicit Semaphore(QWidget *parent = 0);
    ~Semaphore();
    void start();

private slots:
    void on_pushButton_clicked();

private:
    void fillGrafo();
    void getLabelsInArray();
    void moveColor();
    bool uncolored();
    bool recorrer(Calle* c);
    string colorToString(Color cl);
    Ui::Semaphore *ui;
    vector<Calle*> grafo;
    vector<QLabel*> label;
    Color color_actal;
    QMessageBox msg;
    string qcolor;

};

#endif // SEMAPHORE_H
