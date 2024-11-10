#include "jugador.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>

Jugador::Jugador(string nombre){
    if (nombre=="Bart"){
        spritesLado= QPixmap(":/Nivel3/BartLado.png");
        spritesArribaAbajo = QPixmap(":/Nivel3/BartFrente.png");

        ancho=117;
        alto=187;

        // Dimensiones de cada hoja de sprites
        anchoLado = 117;
        altoLado = 187;
        anchoArribaAbajo = 45;
        altoArribaAbajo = 88;


        sprites = spritesLado; // Iniciar con la hoja de movimientos laterales
        ancho = anchoLado;
        alto = altoLado;
        columna = 0;
        fila = 0;

        QPixmap sprite = sprites.copy(0, 0, ancho, alto);

        setPixmap(sprite.scaled(80, 80, Qt::KeepAspectRatio, Qt::SmoothTransformation));

        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, & Jugador::actualizarAnimacion);
        timer->start(75);

        setPos(35,65);
        setZValue(1);
    }
}
