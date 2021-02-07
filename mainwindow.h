#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "KethoLib/ketholibminecraftimplementation.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnpatch_clicked();

    void on_btncheckprocess_clicked();

private:
    Ui::MainWindow *ui;
    KethoLibMinecraftImplementation *ketholibinstance = new KethoLibMinecraftImplementation();
};
#endif // MAINWINDOW_H
