#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog_version.h"
#include "QFileDialog"
#include "QFile"
#include "QTextStream"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionVersion,SIGNAL(triggered()),this,SLOT(open_version()));
    connect(ui->actionOuvrir,SIGNAL(triggered()),this,SLOT(open_file()));
    connect(ui->actionQuitter,SIGNAL(triggered()),this,SLOT(close_app()));
}

void MainWindow::open_version()
{
    Dialog_version *dialog = new Dialog_version(this);
    dialog->exec();
}

void MainWindow::open_file()
{

        QString fileName = QFileDialog::getOpenFileName(this,QString("Selectionner le fichier"), QDir::homePath(),"Fichier (*.txt *.odt)");
        QFile fichier(fileName);
        fichier.open(QIODevice::ReadOnly | QIODevice::Text);

        //lire le fichier avec QTextStream
        QTextStream flux(&fichier);
        QString data;
        data = flux.readAll();
        ui->plainTextEdit->insertPlainText(data);


        //lire le fichier avec QByteArray
        //QByteArray data;
        //data = fichier.readAll();
        //QString ligne(data);
        //ui->plainTextEdit->insertPlainText(ligne);


}

void MainWindow::close_app()
{

    QMessageBox msgBox(this);
    msgBox.setText(QString("On dirait que vous avez terminez de travailler!"));
    msgBox.setInformativeText(QString("Êtes-vous sûr de vouloir quitter?"));
    msgBox.setStandardButtons(QMessageBox::Save|QMessageBox::Discard|QMessageBox::Cancel);
    int ret = msgBox.exec();

    if (ret == QMessageBox::Cancel)
    {msgBox.close();}                            //ferme la messagebox

    else close();                                //ferme la fenêtre

}

MainWindow::~MainWindow()
{
    delete ui;
}
