#include "Tarea2/Duplicates.h"
#include "ui_Duplicates.h"

Duplicates::Duplicates(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Duplicates)
{
    ui->setupUi(this);
}

Duplicates::~Duplicates()
{
    delete ui;
}

void Duplicates::on_btnadd_clicked()
{
    lista.push_back(ui->txt1->text());
    QStandardItemModel* ListModel = new QStandardItemModel();
    for (int i =0; i<lista.size(); i++){
        QStandardItem* Items = new QStandardItem(lista[i]);
        ListModel->appendRow(Items);
    }

    ui->list1->setModel(ListModel);
    ui->txt1->setText("");
}

bool Duplicates::search(vector<QString> lista, QString valor){
    for(int x = 0; x < lista.size(); x++){
           if(lista[x] == valor)
               return true;
    }
    return false;
}

void Duplicates::on_btnquitar_clicked()
{
    cout<<"quitando duplicados"<<endl;
    vector<QString> temp;
    QStandardItemModel* ListModel = new QStandardItemModel();

    for(int i = 0; i < lista.size(); i++){
        if(!search(temp, lista[i])){
            cout<<lista[i].toStdString()<<endl;
            temp.push_back(lista[i]);
            QStandardItem* Items = new QStandardItem(lista[i]);
            ListModel->appendRow(Items);
        }
    }
    ui->list2->setModel(ListModel);
}
