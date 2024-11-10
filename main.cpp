#include "mainwindow.h"
#include <QApplication>
#include "juego.h"

Juego * juego;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    juego= new Juego();
    juego->show();

    return a.exec();
}
