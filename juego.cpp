#include "juego.h"
#include "nivel.h"
#include <QGraphicsProxyWidget>

Juego::Juego(QWidget * parent): QGraphicsView(parent), nivel(nullptr)
{
    //Crear escena
    escena= new QGraphicsScene();
    escena->setSceneRect(0,0,1280,720);
    setScene(escena);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1280,720);

    mostrarMenuInicio();
}

Juego::~Juego() {
    delete nivel;
    delete escena;
}

void Juego::mostrarMenuInicio() {
    // Crear botones para seleccionar el nivel
    botonNivel1 = new QPushButton("Nivel 1");
    botonNivel2 = new QPushButton("Nivel 2");
    botonNivel3 = new QPushButton("Nivel 3");

    // Configurar tamaño de los botones
    botonNivel1->setFixedSize(250, 100);
    botonNivel2->setFixedSize(250, 100);
    botonNivel3->setFixedSize(250, 100);

    // Posicionar botones en la escena
    QGraphicsProxyWidget *botonWidget1 =escena->addWidget(botonNivel1);
    botonWidget1->setPos(540, 150);
    QGraphicsProxyWidget *botonWidget2 =escena->addWidget(botonNivel2);
    botonWidget2->setPos(540, 300);
    QGraphicsProxyWidget *botonWidget3 =escena->addWidget(botonNivel3);
    botonWidget3->setPos(540, 450);

    // Conectar botones a las funciones para seleccionar el nivel
    connect(botonNivel1, &QPushButton::clicked, this, &Juego::seleccionarNivel1);
    connect(botonNivel2, &QPushButton::clicked, this, &Juego::seleccionarNivel2);
    connect(botonNivel3, &QPushButton::clicked, this, &Juego::seleccionarNivel3);
}

void Juego::seleccionarNivel1() { iniciarNivel(1); }
void Juego::seleccionarNivel2() { iniciarNivel(2); }
void Juego::seleccionarNivel3() { iniciarNivel(3); }

void Juego::iniciarNivel(int nivelSeleccionado) {
    // Limpiar la escena de los botones
    escena->clear();

    nivel= new Nivel(nivelSeleccionado);
}
