#include "Tarea8/Hashtable.h"
#include "ui_Hashtable.h"

HashTable::HashTable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HashTable)
{
    ui->setupUi(this);
}

HashTable::~HashTable()
{
    delete ui;
}

void HashTable::fillList(){
    ui->list->clear();
    for(int x = 0; x < 26; x++){
        Conjunto* temp = &words[x];
        Word* actual = temp->inicio;
        while(actual){
            ui->list->addItem(QString::fromStdString(actual->valor));
            actual = actual->sig;
        }
    }
}

int HashTable::hash(string val){
    return (toupper(val[0])-'A')%26;
}

void HashTable::on_pushButton_clicked()//insertar
{
    string valor = ui->txtpalabra->text().toStdString();
    if (valor == "")
        return;
    int pos = hash(valor);
    words[pos].agregar(valor);
    fillList();
}
