#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "messagebox.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());
    if(!ketholibinstance->checkIfMinecraftProcessIsRunning()){
        ui->btnpatch->setEnabled(false);
        ui->lblminecraftstatus->setText("Not running");
    }else{
        ui->lblminecraftstatus->setText("Minecraft is running");
        ui->btncheckprocess->setEnabled(false);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnpatch_clicked()
{
    this->ketholibinstance->minecraftBypassDo();
    messagebox *msg = new messagebox();
    msg->show();
}

void MainWindow::on_btncheckprocess_clicked()
{
    if(ketholibinstance->checkIfMinecraftProcessIsRunning()){
        ui->lblminecraftstatus->setText("Minecraft is running");
        ui->btncheckprocess->setEnabled(false);
        ui->btnpatch->setEnabled(true);
    }
}
