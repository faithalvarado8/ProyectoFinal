#ifndef JUEGO_H
#define JUEGO_H

#include "nivel.h"
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>

class Juego: public QGraphicsView{

public:
    QGraphicsScene * escena;
    Nivel * nivel;
    Juego(QWidget * parent=nullptr);
    ~Juego();
};

#endif // JUEGO_H
