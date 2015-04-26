#include "MainMenu.h"
#include "ui_MainMenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::open_Semaphore(){
    Semaphore *Ventana_Nueva = new Semaphore();
    Ventana_Nueva->setWindowModality(Qt::ApplicationModal);
    Ventana_Nueva->show();
}

void MainMenu::on_pushButton_clicked()
{
    open_Semaphore();
}
