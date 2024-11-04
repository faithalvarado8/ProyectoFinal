#ifndef JUGADOR_H
#define JUGADOR_H

#include "personajes.h"
#include <QString>
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

public:
    explicit Jugador(QGraphicsItem * parent=nullptr, string nombre="0");

    void keyPressEvent(QKeyEvent * event) override;

private slots:
    void actualizarAnimacion();

};

#endif // JUGADOR_H
