#include "MainWidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DSVMainWidget w;
    w.show();

    return a.exec();
}
