#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include "chromosome.h"
#include "genetic_algorithm.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void fill_table();

private slots:

private:
    Ui::MainWindow *ui;
    QStandardItemModel* model;
//    genetic_algorithm algorithm;
};

#endif // MAINWINDOW_H
