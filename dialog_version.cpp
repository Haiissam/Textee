#include "dialog_version.h"
#include "ui_dialog_version.h"

Dialog_version::Dialog_version(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_version)
{
    ui->setupUi(this);
}

Dialog_version::~Dialog_version()
{
    delete ui;
}
