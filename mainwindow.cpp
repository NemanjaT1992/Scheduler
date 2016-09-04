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

void MainWindow::draw_chromosome_by_time(chromosome &chrom)
{
    std::vector<course_class> classes = get::courses();

    for(int i=0; i<chrom.schedule.size(); ++i)
    {
        time_table tt = chrom.schedule.at(i);
        for(int k=0; k < tt.size(); ++k)
        {
//            qDebug() << "time_table size:" << tt[k].size();
            for(int d=0; d<tt[k].size(); ++d)
            {
                QString day_data = "";
                class_data single = tt[k][d];

                day_data.append("(" + QString::number(i) + ") " + QString(get::professor_at(single.professor).name) + " " +
                                QString(classes.at(single.course).name)+ " "
                                + QString::number(single.count));

                QStandardItem *data = new QStandardItem(day_data);
//                qDebug() << single.count;
                model->setItem(single.time, k, data);


                for(int countClass = 1; countClass < single.count; ++countClass)
                {
                    QStandardItem *data1 = new QStandardItem("/");
                    model->setItem(single.time + countClass, k, data1);
                }
            }
        }
    }
}

void MainWindow::fill_table()
{
    std::vector<course_class> classes = get::courses();

    genetic_algorithm algorithm(50, 30, 2, 5, this, 0.8);

    chromosome chrom = algorithm.run();

//    generator m_generator(30);
//    generation gener = m_generator.generate();
//    auto& chrom = gener.at(0);

//    for(int i=0; i<chrom.schedule.size(); ++i)
//    {
//        time_table tt = chrom.schedule.at(i);
////        for(int j=0; j<tt.size(); ++j)
////        {
//            for(int k=0; k < tt.size(); ++k)
//            {
//                int day = k;
//                QString& day_data = QString::number(tt[k].size());
//                for(int d=0; d<tt[k].size(); ++d)
//                {
//                    class_data single = tt[k][d];
//                    day_data.append(QString(classes.at(single.course).name) + " " + QString(get::professor_at(single.professor).name)
//                                    + " " + QString::number(single.time) + " + " + QString::number(single.count) + "  ||  ");

//                }
//                QStandardItem *data = new QStandardItem(day_data);
//                model->setItem(i,k,data);
//            }
////        }
//    }
    draw_chromosome_by_time(chrom);
}
