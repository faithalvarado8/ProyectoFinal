#include "nivel.h"

Nivel::Nivel(int nivelSeleccionado): nivelSeleccionado(nivelSeleccionado) {
    jugador = new Jugador();
}

Nivel::~Nivel() {
    delete jugador;
}
