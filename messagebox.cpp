#include "messagebox.h"
#include "ui_messagebox.h"

messagebox::messagebox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::messagebox)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());
}

messagebox::~messagebox()
{
    delete ui;
}

void messagebox::on_btncloseall_clicked()
{
    exit(1);
}
