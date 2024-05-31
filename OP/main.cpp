#include "mainwindow.h"

#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("/home/stepan/Документы/OP/BMSTU.png"));
    MainWindow w;
    w.show();
    return a.exec();
}
