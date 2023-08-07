#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w; //what we going to make
    w.show();
    return a.exec();
}
