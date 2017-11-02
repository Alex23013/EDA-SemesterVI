#include "cfatnodes.h"
#include "cnode.h"
cfatNode::cfatNode(cNode* nodo)
{
    versiones.push_back(nodo);
    this->versionActual = versiones[0];
}

int cfatNode::numVersiones(){
    return versiones.size();
}

void cfatNode::addNodeVersion(cNode *nodo){
    versiones.push_back(nodo);
}

void cfatNode::setVersion(int n){
    this->versionActual = versiones[n];
}

int cfatNode::getinfo(){
    return versionActual->info;
}

cNode* cfatNode:: getChilds(bool side){
    return this->versionActual->childs[side];
}

QVector<cNode*> cfatNode:: getVersions(){
    return this->versiones;
}
