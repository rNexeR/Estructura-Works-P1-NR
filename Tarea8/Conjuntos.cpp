#include "Tarea8/Conjuntos.h"
#include "ui_Conjuntos.h"

Conjuntos::Conjuntos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Conjuntos)
{
    ui->setupUi(this);
}

Conjuntos::~Conjuntos()
{
    delete ui;
}

void Conjuntos::fillLists(){
    int pos = ui->conjunto1->currentIndex();
    if(pos<0)
        return;
    Conjunto* c = &lconjuntos[pos];

    Word* actual = c->inicio;
    ui->listc1->clear();
    while(actual){
        ui->listc1->addItem(QString::fromStdString(actual->valor));
        actual = actual->sig;
    }

    pos = ui->conjunto2->currentIndex();
    if(pos<0)
        return;
    c = &lconjuntos[pos];

    actual = c->inicio;
    ui->listc2->clear();
    while(actual){
        ui->listc2->addItem(QString::fromStdString(actual->valor));
        actual = actual->sig;
    }
}

void Conjuntos::fillResultadoList(Conjunto* c){
    Word* actual = c->inicio;
    ui->listcr->clear();
    while(actual){
        ui->listcr->addItem(QString::fromStdString(actual->valor));
        actual = actual->sig;
    }
}

void Conjuntos::on_pushButton_clicked()//agregar
{
    string valor = ui->txtvalor->text().toStdString();
    //cout<<valor.toStdString()<<endl;
    if(valor == "")
        return;
    if(ui->cmbconjunto->currentText() == "Conjunto Nuevo"){
        cout<<"Conjunto Nuevo"<<endl;
        lconjuntos.push_back(Conjunto());
        lconjuntos[lconjuntos.size()-1].agregar(valor);

        ui->cmbconjunto->clear();
        ui->conjunto1->clear();
        ui->conjunto2->clear();
        for(int x = 0; x < lconjuntos.size(); x++){
            QString num = QString::number(x+1);
            ui->cmbconjunto->addItem("Conjunto "+num);
            ui->conjunto1->addItem("Conjunto "+num);
            ui->conjunto2->addItem("Conjunto "+num);
        }
        ui->cmbconjunto->addItem("Conjunto Nuevo");
    }else{
        int pos = ui->cmbconjunto->currentIndex();
        cout<<pos<<endl;
        lconjuntos[pos].agregar(valor);
    }
    fillLists();
}

void Conjuntos::on_pushButton_2_clicked()//union
{
    int pos = ui->conjunto1->currentIndex();
    if(pos<0)
        return;
    Conjunto* c = &lconjuntos[pos];

    pos = ui->conjunto2->currentIndex();
    if(pos<0)
        return;
    Conjunto* c2 = &lconjuntos[pos];

    Conjunto r = c->unionc(c2);
    fillResultadoList(&r);
}

void Conjuntos::on_pushButton_3_clicked()//interseccion
{
    int pos = ui->conjunto1->currentIndex();
    if(pos<0)
        return;
    Conjunto* c = &lconjuntos[pos];

    pos = ui->conjunto2->currentIndex();
    if(pos<0)
        return;
    Conjunto* c2 = &lconjuntos[pos];

    Conjunto r = c->interseccion(c2);
    fillResultadoList(&r);
}

void Conjuntos::on_pushButton_4_clicked()//diferencia
{
    int pos = ui->conjunto1->currentIndex();
    if(pos<0)
        return;
    Conjunto* c = &lconjuntos[pos];

    pos = ui->conjunto2->currentIndex();
    if(pos<0)
        return;
    Conjunto* c2 = &lconjuntos[pos];

    Conjunto r = c->diferencia(c2);
    fillResultadoList(&r);
}

void Conjuntos::on_conjunto1_currentIndexChanged(const QString &arg1)
{
    fillLists();
}

void Conjuntos::on_conjunto2_currentIndexChanged(const QString &arg1)
{
    fillLists();
}
