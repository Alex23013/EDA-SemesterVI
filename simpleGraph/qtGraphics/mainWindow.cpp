#include <QHBoxLayout>
#include <QGraphicsView>
#include "mainWindow.h"
#include "graphScene.h"

MainWindow::MainWindow() {
    scene = new GraphScene(this);
    scene->setSceneRect(QRectF(0, 0, 1000, 1000));
    scene->randomizeGraph(200, 3, 50, 1, 500);
    scene ->createTree(5, 15, 10); //crear el arbol

    QHBoxLayout *layout = new QHBoxLayout;
    view = new QGraphicsView(scene);
    view->setRenderHint(QPainter::Antialiasing);
    layout->addWidget(view);
    QWidget* widget = new QWidget;
    widget->setLayout(layout);
    this->setCentralWidget(widget);
    this->setWindowTitle("Persistant Binary tree");
}
