#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "time_table.h"
#include "genetic_algorithm.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    std::vector<room> rooms = get::rooms();
    model = new QStandardItemModel(rooms.size(), 5, this);
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
void MainWindow::draw_chromosome(chromosome &chrom)
{
    std::vector<course_class> classes = get::courses();
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

void MainWindow::fill_table()
{
    std::vector<course_class> classes = get::courses();

    genetic_algorithm algorithm(30, 20, 2, 5, this, 0.7);
    chromosome chrom = algorithm.run();

//    generator m_generator(1);
//    generation gener = m_generator.generate();
//    chrom = gener.at(0);

    for(int i=0; i<chrom.schedule.size(); ++i)
    {
        time_table tt = chrom.schedule.at(i);
//        for(int j=0; j<tt.size(); ++j)
//        {
            for(int k=0; k < tt.size(); ++k)
            {
                int day = k;
                QString& day_data = QString::number(tt[k].size());
                for(int d=0; d<tt[k].size(); ++d)
                {
                    class_data single = tt[k][d];
                    day_data.append(QString(classes.at(single.course).name) + " " + QString(get::professor_at(single.professor).name)
                                    + " " + QString::number(single.time) + " + " + QString::number(single.count) + "  ||  ");

                }
                QStandardItem *data = new QStandardItem(day_data);
                model->setItem(i,k,data);
            }
//        }
    }
}
