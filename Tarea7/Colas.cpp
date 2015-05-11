#include "Tarea7/Colas.h"
#include "ui_Colas.h"

Colas::Colas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Colas)
{
    ui->setupUi(this);
}

Colas::~Colas()
{
    delete ui;
}

void Colas::fillList(){
    NodoC* frente = cola.getFrente();
    if (frente){
        ui->txtTope->setText(frente->valor);
        ui->list->clear();
        while(frente){
            ui->list->addItem(frente->valor);
            frente = frente->sig;
        }
    }else{
        ui->txtTope->setText("");
        ui->list->clear();
    }
}

void Colas::on_pushButton_clicked()//agregar
{
    QString valor = ui->txtValor->text();
    if (valor != ""){
        NodoC* temp = new NodoC();
        temp->valor = valor;
        cola.agregar(temp);
    }
    fillList();
}

void Colas::on_pushButton_2_clicked()//sacar
{
    cola.liberarFrente();
    fillList();
}

void Colas::on_pushButton_4_clicked()//vacia
{
    QMessageBox msg;
    msg.setWindowTitle("Cola Vacia?");
    msg.setText("NO Esta Vacia");
    if (cola.vacia())
        msg.setText("Esta Vacia");
    msg.exec();
}

void Colas::on_pushButton_5_clicked()//anular
{
    cola.limpiar();
    fillList();
}
