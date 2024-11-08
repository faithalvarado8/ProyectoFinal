#ifndef NIVEL_H
#define NIVEL_H

#include "jugador.h"

class Nivel
{
private:
    unsigned int numNivel;

public:
    Nivel(int nivelSeleccionado);
    Jugador * jugador;

};

#endif // NIVEL_H
