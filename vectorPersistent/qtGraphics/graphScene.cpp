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
                text->setPos((levelActual)+ (100*i)+450+(radius/2),levelActual*100+(radius/2));

                c.push_back(c[i]->childs[0]);
                c.push_back(c[i]->childs[1]);
            }
            else
            {
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
