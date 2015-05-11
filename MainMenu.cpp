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
    Ventana_Nueva->show();
}

void MainMenu::on_pushButton_clicked()
{
   open_Semaphore();
}

void MainMenu::on_pushButton_2_clicked()
{
    Duplicates *Ventana_Nueva = new Duplicates();
    Ventana_Nueva->show();
}

void MainMenu::on_pushButton_3_clicked()
{
    Arrays *Ventana_Nueva = new Arrays();
    Ventana_Nueva->show();
}

void MainMenu::on_pushButton_4_clicked()
{
    Lists *Ventana_Nueva = new Lists();
    Ventana_Nueva->show();
}

void MainMenu::on_pushButton_5_clicked()
{
    Cursores *Ventana_Nueva = new Cursores();
    Ventana_Nueva->show();
}

void MainMenu::on_pushButton_6_clicked()
{
    Pilas *Ventana_Nueva = new Pilas();
    Ventana_Nueva->show();
}

void MainMenu::on_pushButton_7_clicked()
{
    Colas *Ventana_Nueva = new Colas();
    Ventana_Nueva->show();
}
