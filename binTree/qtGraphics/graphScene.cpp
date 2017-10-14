#include <QGraphicsSceneMouseEvent>
#include "graphScene.h"
#include "cnodegraphic.h"
#include "cbinarytree.h"
#include<iostream>
#include <QVector>
#include <QDebug>

GraphScene::GraphScene(QObject* parent) : QGraphicsScene(parent) {
    binTree = new cbinarytree();

}

void GraphScene::showTree() {

    /*cnodeGraphic * nodo = new cnodeGraphic(binTree->root,10);
    binTree->root->graphics = nodo;
    this->addItem(nodo);
    */
   QVector <cNode*> c;
    c.push_back(binTree->root);
    int len;
    while(c.size()!=0){
        len=c.size();
        for(int i=0;i<len;i++){
        if(c[i]){
            cnodeGraphic * nodo = new cnodeGraphic(c[i],10);
            c[i]->graphics = nodo;
            this->addItem(nodo);
            c.push_back(c[i]->childs[0]);
            c.push_back(c[i]->childs[1]);
        }
        //else
        //  cout << "- ";
        }
        //cout<<endl;
        c.erase(c.begin(),c.begin()+len);
    }

}

void GraphScene:: createTree(){
    binTree->test();
    this->showTree();
}
