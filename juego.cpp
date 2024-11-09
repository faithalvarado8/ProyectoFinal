#include "juego.h"
#include "nivel.h"
#include <QGraphicsProxyWidget>
#include <QPixmap>

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

    // Poner fondo
    QPixmap fondo(":/fondos/fondoInicio1.png");
    QGraphicsPixmapItem* fondoItem = escena->addPixmap(fondo.scaled(1280, 720)); // Ajustar al tamaño de la escena
    fondoItem->setZValue(-1); // Ponerlo detras de los botones

    // Crear botones para seleccionar el nivel
    botonNivel1 = new QPushButton();
    botonNivel2 = new QPushButton();
    botonNivel3 = new QPushButton();

    // Configurar imagen en los botones
    QPixmap iconoPixmapNivel1(":/fondos/Krusty.jpg");
    QPixmap iconoPixmapNivel2(":/fondos/King Homer.png");
    QPixmap iconoPixmapNivel3(":/fondos/cementerio.jpg");

    botonNivel1->setIcon(iconoPixmapNivel1);
    botonNivel2->setIcon(iconoPixmapNivel2);
    botonNivel3->setIcon(iconoPixmapNivel3);

    // Configurar tamaño de los botones y el tamaño del icono
    botonNivel1->setIconSize(QSize(250, 100));
    botonNivel2->setIconSize(QSize(250, 100));
    botonNivel3->setIconSize(QSize(250, 100));

    // Estilo de los botones con borde visible y espacio alrededor de la imagen
    QString botonEstilo =
        "QPushButton {"
        "   border: 10px solid black;"        // Color y grosor del borde para pruebas
        "   background-color: transparent;"   // Fondo transparente
        "   border-radius: 20px;"             // Bordes redondeados

        "}"
        "QPushButton:hover {"
        "   background-color: darkgray;"   // Fondo al pasar el mouse
        "}";

    botonNivel1->setStyleSheet(botonEstilo);
    botonNivel2->setStyleSheet(botonEstilo);
    botonNivel3->setStyleSheet(botonEstilo);

    // Posicionar botones en la escena
    QGraphicsProxyWidget *botonWidget1 =escena->addWidget(botonNivel1);
    botonWidget1->setPos(650, 160);
    QGraphicsProxyWidget *botonWidget2 =escena->addWidget(botonNivel2);
    botonWidget2->setPos(650, 310);
    QGraphicsProxyWidget *botonWidget3 =escena->addWidget(botonNivel3);
    botonWidget3->setPos(650, 460);

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

    // Eliminar cualquier nivel previamente creado
    if (nivel) {
        delete nivel;
    }

    nivel= new Nivel(nivelSeleccionado);
}
