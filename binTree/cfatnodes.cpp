#include "cfatnodes.h"
#include "cnode.h"
#include <iostream>///debugging
using namespace std;///debugging
cfatNode::cfatNode(cNode* nodo)
{
    versiones.push_back(nodo);
    this->versionActual = versiones[0];
}

int cfatNode::numVersiones(){
    return versiones.size();
}

void cfatNode::addNodeVersion(cNode *nodo, cNode* n1, bool side){
    nodo->inject(n1,side);
    versiones.push_back(nodo);
    //cout<<"version a definir como actual "<<nodo->version;
    this->setVersion(nodo->version);
}

void cfatNode::setVersion(int n){
    this->versionActual = versiones[n];
}

int cfatNode::getinfo(){
    return versionActual->info;
}

cfatNode* cfatNode:: getChilds(bool side){
    return this->versionActual->childs[side];
}

QVector<cNode*> cfatNode:: getVersions(){
    return this->versiones;
}
