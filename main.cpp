#include "mainwindow.h"
// #include "music.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    // music m; // BASS interface class
    w.show();
    return a.exec();
}
