#ifndef JUEGO_H
#define JUEGO_H

#include "nivel.h"
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPushButton>

class Juego: public QGraphicsView{
    Q_OBJECT
public:
    Juego(QWidget * parent=nullptr);
    ~Juego();

private:
    QGraphicsScene * escena;
    Nivel * nivel;
    QPushButton *botonNivel1;
    QPushButton *botonNivel2;
    QPushButton *botonNivel3;
    
    void mostrarMenuInicio();
    void iniciarNivel(int nivelSeleccionado);

private slots:
    void seleccionarNivel1();
    void seleccionarNivel2();
    void seleccionarNivel3();
};

#endif // JUEGO_H
