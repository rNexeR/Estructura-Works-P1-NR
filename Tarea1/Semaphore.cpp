#include "Semaphore.h"
#include "ui_Semaphore.h"

Semaphore::Semaphore(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Semaphore)
{
    ui->setupUi(this);
    color_actal = BLANCO;
    qcolor = "QLabel {color : black; }";
    fillGrafo();
    getLabelsInArray();
    msg.setWindowTitle("Este es el titulo");
}

Semaphore::~Semaphore()
{
    delete ui;
}

void Semaphore::fillGrafo(){
    grafo.push_back(new Calle("AB"));
    grafo.push_back(new Calle("AC"));
    grafo.push_back(new Calle("AD"));
    grafo.push_back(new Calle("BA"));
    grafo.push_back(new Calle("BC"));
    grafo.push_back(new Calle("BD"));
    grafo.push_back(new Calle("DA"));
    grafo.push_back(new Calle("DB"));
    grafo.push_back(new Calle("DC"));
    grafo.push_back(new Calle("EA"));
    grafo.push_back(new Calle("EB"));
    grafo.push_back(new Calle("EC"));
    grafo.push_back(new Calle("ED"));

    grafo[0]->addAdyecente(grafo[9]);
    grafo[0]->addAdyecente(grafo[6]);
    grafo[0]->addAdyecente(grafo[4]);
    grafo[0]->addAdyecente(grafo[5]);

    grafo[1]->addAdyecente(grafo[9]);
    grafo[1]->addAdyecente(grafo[6]);
    grafo[1]->addAdyecente(grafo[7]);
    grafo[1]->addAdyecente(grafo[10]);
    grafo[1]->addAdyecente(grafo[5]);

    grafo[2]->addAdyecente(grafo[9]);
    grafo[2]->addAdyecente(grafo[10]);
    grafo[2]->addAdyecente(grafo[11]);

    //grafo[3] no tiene adyecentes

    grafo[4]->addAdyecente(grafo[0]);
    grafo[4]->addAdyecente(grafo[8]);
    grafo[4]->addAdyecente(grafo[10]);

    grafo[5]->addAdyecente(grafo[1]);
    grafo[5]->addAdyecente(grafo[0]);
    grafo[5]->addAdyecente(grafo[6]);
    grafo[5]->addAdyecente(grafo[10]);
    grafo[5]->addAdyecente(grafo[11]);

    grafo[6]->addAdyecente(grafo[1]);
    grafo[6]->addAdyecente(grafo[0]);
    grafo[6]->addAdyecente(grafo[5]);
    grafo[6]->addAdyecente(grafo[10]);
    grafo[6]->addAdyecente(grafo[11]);

    grafo[7]->addAdyecente(grafo[1]);
    grafo[7]->addAdyecente(grafo[4]);
    grafo[7]->addAdyecente(grafo[11]);

    //grafo[8] no tiene adyecentes

    grafo[9]->addAdyecente(grafo[0]);
    grafo[9]->addAdyecente(grafo[1]);
    grafo[9]->addAdyecente(grafo[2]);

    grafo[10]->addAdyecente(grafo[6]);
    grafo[10]->addAdyecente(grafo[4]);
    grafo[10]->addAdyecente(grafo[1]);
    grafo[10]->addAdyecente(grafo[2]);
    grafo[10]->addAdyecente(grafo[5]);

    grafo[11]->addAdyecente(grafo[6]);
    grafo[11]->addAdyecente(grafo[7]);
    grafo[11]->addAdyecente(grafo[5]);
    grafo[11]->addAdyecente(grafo[2]);

    //grafo[12] no tiene adyecentes
}

void Semaphore::getLabelsInArray(){
    label.push_back(ui->AB);
    label.push_back(ui->AC);
    label.push_back(ui->AD);
    label.push_back(ui->BA);
    label.push_back(ui->BC);
    label.push_back(ui->BD);
    label.push_back(ui->DA);
    label.push_back(ui->DB);
    label.push_back(ui->DC);
    label.push_back(ui->EA);
    label.push_back(ui->EB);
    label.push_back(ui->EC);
    label.push_back(ui->ED);
}

bool Semaphore::uncolored(){
    for(int i = 0; i < grafo.size(); i++){
        if(grafo[i]->getColor() == BLANCO)
            return true;
    }
    return false;
}

bool Semaphore::recorrer(Calle* c){
    vector<Calle*> vt = c->getAdyecentes();
    for (int x=0; x < vt.size(); x++){
        if (vt[x]->getColor() == color_actal){
            return true;
        }
    }
    return false;
}

void Semaphore::moveColor(){
    if (color_actal == AZUL){
        color_actal = VERDE;
        qcolor = "QLabel {color : green; }";
    }else if(color_actal == VERDE){
        color_actal = ROJO;
        qcolor = "QLabel {color : red; }";
    }else if(color_actal == ROJO){
        color_actal = AMARILLO;
        qcolor = "QLabel {color : yellow; }";
    }else if (color_actal == AMARILLO || color_actal == BLANCO){
        color_actal = AZUL;
        qcolor = "QLabel {color : blue; }";
    }
}

string Semaphore::colorToString(Color cl){
    if (cl == AZUL)
        return "AZUL";
    else if(cl == VERDE)
        return "VERDE";
    else if(cl == ROJO)
        return "ROJO";
    else if (cl == AMARILLO)
        return "AMARILLO";
    else
        return "BLANCO";
}

void Semaphore::start(){    
    char x = '1';
    while(uncolored()){
        for(int i = 0; i < grafo.size(); i++){
            if (grafo[i]->getColor() == BLANCO){
                if (!recorrer(grafo[i])){
                    grafo[i]->setColor(color_actal);
                    label[i]->setStyleSheet(qcolor.c_str());
                }
            }
        }
        moveColor();
        msg.setText(&x);
        msg.exec();
        x++;
    }
}

void Semaphore::on_pushButton_clicked()
{
    moveColor();
    cout<<"\n"<<endl;
    for(int i = 0; i < grafo.size(); i++){
        Calle* c = grafo[i];
        cout<<c->getNombre()<<endl;
        vector<Calle*> vt = c->getAdyecentes();
        for (int i = 0; i < vt.size(); i++){
            Calle* temp = vt[i];
            cout<<"\t"<<temp->getNombre()<<endl;
        }
    }
    start();
}
