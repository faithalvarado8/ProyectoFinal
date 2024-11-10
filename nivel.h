#ifndef NIVEL_H
#define NIVEL_H

#include <QGraphicsScene>
#include "jugador.h"

class Nivel
{
private:
    int nivelSeleccionado;

public:
    Nivel(int nivelSeleccionado, QGraphicsScene * escena);
    Jugador * jugador;
    ~Nivel();
};

#endif // NIVEL_H
