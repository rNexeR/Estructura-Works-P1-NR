#include "Tarea5/Cursores.h"
#include "ui_Cursores.h"

Cursores::Cursores(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Cursores)
{
    arreglo.inicializar();
    ui->setupUi(this);
}

Cursores::~Cursores()
{
    delete ui;
}

void Cursores::on_pushButton_5_clicked()
{
    QString valor = ui->txtValor->text();
    //cout<<valor<<endl;
    //char valor = ((ui->txtValor->text()).toStdString())[0];
    if(valor != "")
        arreglo.crearLista(valor);
    ui->cmbListas->clear();
    for(int i = 0; i <= arreglo.listas; i++)
        ui->cmbListas->addItem(""+i);
}

void Cursores::on_pushButton_clicked()
{

}
