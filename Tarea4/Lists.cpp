#include "Lists.h"
#include "ui_Lists.h"

Lists::Lists(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Lists)
{
    ui->setupUi(this);
}

Lists::~Lists()
{
    delete ui;
}

void Lists::fillList(){
    QStandardItemModel* ListModel = new QStandardItemModel();
    for(int i = 0; i < lista.size; i++){
        cout<<i<<endl;
        Carta* t = lista.getPos(i);
        QString num = QString::number(t->num);
        QStandardItem* Items = new QStandardItem(num);
        ListModel->appendRow(Items);
    }
     ui->list1->setModel(ListModel);
}

void Lists::on_append_clicked()
{
    if(ui->txtValor->text() != ""){
        lista.agregar(ui->txtValor->text().toInt());
    }
    fillList();
}

void Lists::on_append_4_clicked()
{
    if(ui->txtPos->text() != ""){
        lista.eliminar(ui->txtPos->text().toInt());
    }
    fillList();
}

void Lists::on_append_2_clicked()
{
    if(ui->txtValor->text() != "" && ui->txtPos->text() != ""){
        lista.insertar(ui->txtPos->text().toInt(),ui->txtValor->text().toInt());
    }
    fillList();
}

void Lists::on_append_3_clicked()
{
    if(ui->txtValor->text() != ""){
        Carta* t = lista.buscar(ui->txtValor->text().toInt());
        QMessageBox msg;
        msg.setWindowTitle("Busqueda");
        msg.setText("Carta no encontrada");
        if (t){
            msg.setText("Carta encontrada");
        }
        msg.exec();

    }
}
