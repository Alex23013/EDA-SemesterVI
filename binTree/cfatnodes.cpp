#include "cfatnodes.h"
#include "cnode.h"
cfatNodes::cfatNodes(cNode* nodo)
{
    versiones.push_back(nodo);
    this->versionActual = versiones[0];
}

int cfatNodes::numVersiones(){
    return versiones.size();
}

void cfatNodes::addNode(cNode *nodo){
    versiones.push_back(nodo);
}

void cfatNodes::setVersion(int n){
    this->versionActual = versiones[n];
}

int cfatNodes::getinfo(){
    return versionActual->info;
}

QVector<cNode*> cfatNodes:: getVersions(){
    return this->versiones;
}
