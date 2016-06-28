#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "time_table.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QStandardItemModel(constants::hours, 5, this);
    model->setHorizontalHeaderItem(0, new QStandardItem(QString("Ponedeljak")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("Utorak")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QString("Sreda")));
    model->setHorizontalHeaderItem(3, new QStandardItem(QString("Četvrtak")));
    model->setHorizontalHeaderItem(4, new QStandardItem(QString("Petak")));

    ui->tableView->setModel(model);

    fill_table();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fill_table()
{
    std::vector<course_class> classes = get::courses();

    genetic_algorithm algorithm(30, 600, 2, 5);
    chromosome chrom = algorithm.run();

//    generator m_generator(1);
//    generation gener = m_generator.generate();
//    chrom = gener.at(0);

    for(int i=0; i<chrom.schedule.size(); ++i)
    {
        time_table tt = chrom.schedule.at(i);
//        for(int j=0; j<tt.size(); ++j)
//        {
            for(int k=0; k<tt.size(); ++k)
            {
                int day = k;
                for(int d=0; d<tt[k].size(); ++d)
                {
                    int time = tt[k][d].time;
                    QStandardItem *data = new QStandardItem(classes.at(tt[k][d].course).name);
                    model->setItem(time,k,data);
                }
            }
//        }
    }
}
