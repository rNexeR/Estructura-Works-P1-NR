#include "Tarea3/Arrays.h"
#include "ui_Arrays.h"

Arrays::Arrays(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Arrays)
{
    ui->setupUi(this);
}

Arrays::~Arrays()
{
    delete ui;
}

int Arrays::search(QString valor){
    for(int i = 0; i<actual; i++){
        if(arreglo[i] == valor)
            return i;
    }
    return -1;
}

void Arrays::clear(){
    for(int i = 0; i<actual; i++){
        arreglo[i] = "";
        actual = 0;
    }
    ui->arreglo->setText("[arreglo]");
}

bool Arrays::append(QString valor){
    if(actual < tam)
        arreglo[actual++] = valor;
    fillColumns();
}

bool Arrays::insert(int pos, QString valor){
    if (pos<actual && actual<tam){
        for(int i = actual-1; i >= pos; i--){
            arreglo[i+1] = arreglo[i];
        }
        arreglo[pos] = valor;
        actual++;
        fillColumns();
        return true;
    }
    return false;
}

bool Arrays::suprim(int pos){
    if (pos<actual){
        for(int x = pos; x<actual; x++){
            arreglo[x] = arreglo[x+1];
        }
        arreglo[--actual] = "";
        fillColumns();
        return true;
    }
    return false;
}

void Arrays::fillColumns(){
    QString ar;
    for (int i =0; i<tam; i++){
        if (arreglo[i] != "")
            ar += arreglo[i] + " | ";
    }
    ui->txtPos->setText("");
    ui->txtValor->setText("");
    ui->arreglo->setText(ar);
}

void Arrays::on_append_clicked()
{
    if(ui->txtValor->text() != ""){
        append(ui->txtValor->text());
    }
}

void Arrays::on_append_2_clicked()
{
    int num = (ui->txtPos->text()).toInt();
    QString valor = ui->txtValor->text();
    //if (num>=0 && num<actual && valor != "")
    insert(num, valor);
}

void Arrays::on_append_3_clicked()
{
    int num = (ui->txtPos->text()).toInt();
    suprim(num);
}

void Arrays::on_append_4_clicked()
{
    clear();
}
