#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window|Qt::MSWindowsFixedSizeDialogHint|Qt::WindowMinimizeButtonHint);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_Comenzar_clicked()
{
    SecondWindow *sw = new SecondWindow(this);
    sw->show();
}



