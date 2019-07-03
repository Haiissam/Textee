#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void open_version();  //fonction pour appeler la dialogue version
    void open_file();     //fonction pour ouvrir un fichier
    void close_app();
};

#endif // MAINWINDOW_H
