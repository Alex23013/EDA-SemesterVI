#include <QHBoxLayout>
#include <QGraphicsView>
#include "mainWindow.h"
#include "graphScene.h"

MainWindow::MainWindow() {
    scene = new GraphScene(this);
    scene->setSceneRect(QRectF(0, 0, 1000, 1000));
    scene ->createTree(); //crear el arbol
    QHBoxLayout *layout = new QHBoxLayout;
    view = new QGraphicsView(scene);
    view->setRenderHint(QPainter::Antialiasing);
    layout->addWidget(view);
    QWidget* widget = new QWidget;
    widget->setLayout(layout);
    this->setCentralWidget(widget);
    this->setWindowTitle("Persistant Binary tree");

    undoButton = new QPushButton("UnDo", this);
    undoButton->setGeometry(50,100,100,30);

    redoButton = new QPushButton("ReDo", this);
    redoButton->setGeometry(50,150,100,30);

    insertButton = new QPushButton("INSERT X", this);
    insertButton->setGeometry(50,250,100,30);

    deleteButton = new QPushButton("DELETE X", this);
    deleteButton->setGeometry(50,300,100,30);

    changeButton = new QPushButton("REPLACE X", this);
    changeButton->setGeometry(50,350,100,30);

    //Connect button signal to appropriate slot
    connect(undoButton, SIGNAL (released()),this, SLOT (handleUndoButton()));
    connect(redoButton, SIGNAL (released()),this, SLOT (handleRedoButton()));
    connect(insertButton, SIGNAL (released()),this, SLOT (handleInsertButton()));
    connect(deleteButton, SIGNAL (released()),this, SLOT (handleDeleteButton()));
    connect(changeButton, SIGNAL (released()),this, SLOT (handleChangeButton()));

    newElement = new QLineEdit(this->window());
    newElement->setGeometry(50,400,50,30);
    newElement->show();

    childToRemove = new QLineEdit(this->window());
    childToRemove->setGeometry(110,400,50,30);
    childToRemove->show();

}


void MainWindow:: handleUndoButton(){

    this->scene->clear();
    this->scene->undoTree();
}

void MainWindow:: handleRedoButton(){

    this->scene->clear();
    this->scene->redoTree();
}

void MainWindow:: handleInsertButton(){
    this->scene->clear();
    QString res= newElement->text();
    int as= res.toInt();
    this->scene->insertElement(as);
}


void MainWindow:: handleDeleteButton(){
    this->scene->clear();
    QString res= newElement->text();
    QString side= childToRemove->text();
    int as= res.toInt();
    bool Bside = side.toInt();
    this->scene->deleteElement(as,Bside);
}


void MainWindow:: handleChangeButton(){
    this->scene->clear();
    QString res= newElement->text();
    QString newRes= childToRemove->text();
    int as= res.toInt();
    int newAs = newRes.toInt();
    this->scene->changeElement(as, newAs);
}


