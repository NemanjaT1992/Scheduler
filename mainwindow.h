#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include "chromosome.h"

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
    void draw_chromosome(chromosome& c);
    void draw_chromosome_by_time(chromosome& chrom);
private slots:

private:
    Ui::MainWindow *ui;
    QStandardItemModel* model;
//    genetic_algorithm algorithm;
};

#endif // MAINWINDOW_H
