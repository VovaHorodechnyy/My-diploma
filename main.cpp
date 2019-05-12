#include "mainwindow.h"
#include <QApplication>
#include "cloadingscreen.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setStyle(QStyleFactory::create("Fusion"));
    MainWindow w;

    w.show();

    //CLoadingScreen c;
   // c.show();


    return a.exec();
}
