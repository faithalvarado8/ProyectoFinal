#include "juego.h"

Juego::Juego(QWidget * parent): QGraphicsView(parent)
{
    //Crear escena
    escena= new QGraphicsScene();
    escena->setSceneRect(0,0,1280,720);
    setScene(escena);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1280,720);
}

Juego::~Juego(){}
