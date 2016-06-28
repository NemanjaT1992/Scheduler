#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <QDebug>
#include <algorithm>

#include "chromosome.h"
#include "constraint.h"
#include "mutator.h"
#include "generator.h"
#include "repository.h"
#include "range.h"
#include "selector.h"
#include "genetic_algorithm.h"

double test_eval(chromosome& c) { return 3.0; }

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    genetic_algorithm alg(6, 400, 2, 5);
    alg.run();

    return a.exec();
}





















