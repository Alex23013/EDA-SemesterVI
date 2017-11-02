#ifndef FATNODES_H
#define FATNODES_H
#include"cnode.h"
#include<QVector>

class cNode;
class cfatNode
{
    QVector <cNode*> versiones;
public:

    cNode* versionActual;

    cfatNode(cNode* nodo);
    int numVersiones();
    void addNodeVersion(cNode* nodo,cNode* n1, bool side);
    void setVersion(int n);
    int getinfo();
    cfatNode* getChilds(bool side);
    QVector<cNode*> getVersions();
};

#endif // FATNODES_H
