#include "Tarea6/Pilas.h"
#include "ui_pilas.h"

Pilas::Pilas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Pilas)
{
    ui->setupUi(this);
}

Pilas::~Pilas()
{
    delete ui;
}

void Pilas::getTope(){
    NodoP* tope = pila.getTope();
    if(tope){
        ui->txtTope->setText(tope->valor);
        ui->list->clear();
        while(tope){
            ui->list->addItem(tope->valor);
            tope = tope->ant;
        }
    }else{
        ui->txtTope->setText("");
        ui->list->clear();
    }
}

void Pilas::on_pushButton_clicked()//agregar
{
    QString valor = ui->txtValor->text();
    if (valor != ""){
        NodoP* nuevo = new NodoP();
        nuevo->valor = valor;
        pila.agregar(nuevo);
    }
    getTope();
}

void Pilas::on_pushButton_2_clicked()//sacar tope
{
    pila.liberarTope();
    getTope();
}

void Pilas::on_pushButton_3_clicked()//sacar
{

}

void Pilas::on_pushButton_4_clicked()//vacia
{
    QMessageBox msg;
    msg.setWindowTitle("Pila Vacia?");
    msg.setText("NO Esta Vacia");
    if (pila.vacia())
        msg.setText("Esta Vacia");
    msg.exec();
}

void Pilas::on_pushButton_5_clicked()//anular
{
    pila.limpiar();
    getTope();
}
