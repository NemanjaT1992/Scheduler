#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    qDebug() << "asd";
    return a.exec();
}
