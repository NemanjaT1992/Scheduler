#include "mainwindow.h"
#include "repository.h"
#include <QApplication>
#include <iostream>
#include <QDebug>

#include "chromosome.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    repository::get_instance();

    return a.exec();
}
