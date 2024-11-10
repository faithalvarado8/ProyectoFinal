#include "jugador.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>

Jugador::Jugador(string nombre){
    if (nombre=="Bart"){
        sprites= QPixmap(":/Nivel3/BartLado.png");

        ancho=117;
        alto=187;
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

void Jugador::actualizarAnimacion(){
    bool moving = false;

    if (keys[Qt::Key_Left] && pos().x()>35){
        setPos(x()-10,y());
        fila=1;
        moving = true;
    }
    else if (keys[Qt::Key_Right] && pos().x()<1150){
        setPos(x()+10,y());
        fila=0;
        moving = true;
    }

    if (moving){
        // Avanzar al siguiente cuadro en la hoja de sprites
        columna = (columna + 1) % 4;
    }else {
        columna = 0;
    }
  
    // Calcular la posicion del cuadro en la hoja de sprites
    int x = columna * ancho;
    int y = fila * alto;

    // Actualizar la imagen del personaje
    QPixmap sprite = sprites.copy(x, y, ancho, alto);
    setPixmap(sprite.scaled(80, 80, Qt::KeepAspectRatio, Qt::SmoothTransformation));

}

void Jugador::keyReleaseEvent(QKeyEvent *event) {
    switch(event->key()){
    case Qt::Key_Left:
    case Qt::Key_Right:
        keys[event->key()]=false;
        break;
    default:
        break;
    }
}
void Jugador::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){
    case Qt::Key_Left:
    case Qt::Key_Right:
        keys[event->key()]=true;
        break;
    default:
        break;
    }
}
