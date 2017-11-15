#include <QGraphicsSceneMouseEvent>
#include "graphScene.h"
#include "cnodegraphic.h"
#include "cfatnodes.h"
#include<iostream>
#include <QVector>
#include <QDebug>

GraphScene::GraphScene(QObject* parent) : QGraphicsScene(parent) {
    mainVector = new cfatNode;
}

void GraphScene::showTree() {
    QGraphicsTextItem *text = this->addText("Arbol en el tiempo :");
    text->setPos(50,30);
    QGraphicsTextItem *textX = this->addText("X :");
    textX->setPos(10,390);
    QString s = QString::number(mainVector->versionActual->tiempoActual);
    QGraphicsTextItem *text1 = this->addText(s);
    text1->setPos(50,50);
    QVector <cNode*> c;
    c.push_back(mainVector->versionActual->root);
    int len;
    while(c.size()!=0){
        len=c.size();
        int radius = 25;
        for(int i=0;i<len;i++){
            if(c[i]){
                cnodeGraphic * nodo = new cnodeGraphic(c[i],radius);
                if (c[i]==mainVector->versionActual->root) nodo->setColor(QColor(255, 0, 0, 127));
                c[i]->graphics = nodo;
                int levelActual = nodo->getData()->level;
                nodo->setPos((levelActual)+ (100*i),levelActual);
                this->addItem(nodo);
                QString s = QString::number(c[i]->info);
                QGraphicsTextItem *text = this->addText(s);
                text->setPos((levelActual)+ (100*i)+(550-(levelActual*100))+(radius/2),levelActual*100+(radius/2));

                c.push_back(c[i]->childs[0]);
                c.push_back(c[i]->childs[1]);
            }
            else
            {
                /*QString s = "null";
                QGraphicsTextItem *text = this->addText(s);
                text->setPos((60*i)+300,300);*/
                //todo:visualizar null nodes
            }
        }
        c.erase(c.begin(),c.begin()+len);
    }
}

void GraphScene:: createTree(){
    mainVector->test();
    this->showTree();
}

void GraphScene ::undoTree(){
    mainVector->undo();
    this->showTree();
}
void GraphScene ::redoTree(){
    mainVector->redo();
    this->showTree();
}

void GraphScene:: insertElement(int x){
    mainVector->insertValue(x);
    this->showTree();
}

void GraphScene::deleteElement(int x, bool side){
    mainVector->deleteValue(x,side);
    this->showTree();
}

void GraphScene::changeElement(int x, int newX){
    mainVector->changeValue(x,newX);
    this->showTree();
}
