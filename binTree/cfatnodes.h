#ifndef FATNODES_H
#define FATNODES_H
#include"cnode.h"
#include<QVector>

class cfatNodes
{
    QVector <cNode*> versiones;
public:

    cNode* versionActual;

    cfatNodes(cNode* nodo);
    int numVersiones();
    void addNode(cNode* nodo);
    void setVersion(int n);
    int getinfo();
    QVector<cNode*> getVersions();
};

#endif // FATNODES_H
