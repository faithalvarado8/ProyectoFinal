#ifndef NIVEL_H
#define NIVEL_H

#include "jugador.h"

class Nivel
{
private:
    int nivelSeleccionado;

public:
    Nivel(int nivelSeleccionado);
    Jugador * jugador;
    ~Nivel();
};

#endif // NIVEL_H
