#ifndef JUGADOR_H
#define JUGADOR_H

#include "personajes.h"
#include <string>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QMap>

using namespace std;

class Jugador: public Personajes{
    Q_OBJECT
private:
    string nombre;
    QPixmap sprites;
    int ancho;
    int alto;
    int columna;
    int fila;
    QTimer *timer;

    QMap<int,bool>keys;

public:
    explicit Jugador(string nombre);

    void keyPressEvent(QKeyEvent * event)override;
    void keyReleaseEvent(QKeyEvent *event)override;

private slots:
    void actualizarAnimacion();

};

#endif // JUGADOR_H
