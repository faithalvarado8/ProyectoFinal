#include "nivel.h"

Nivel::Nivel(int nivelSeleccionado, QGraphicsScene * escena): nivelSeleccionado(nivelSeleccionado) {
    if (nivelSeleccionado==3){

        jugador = new Jugador("Bart");
        //Enfocar personaje
        jugador->setFlag(QGraphicsItem::ItemIsFocusable);
        jugador->setFocus();

        escena->addItem(jugador);
    }
}

Nivel::~Nivel() {
    delete jugador;
}
