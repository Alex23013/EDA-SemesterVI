#ifndef CBINARYTREE_H
#define CBINARYTREE_H
#include "cnode.h"

class cbinarytree
{
public:
  cNode *root;
  int tiempoActual;


    cbinarytree(int tiempo);
    void contenido();
    void setTime(int newTime);

    void findNode(int x,cNode*&p,int& level);
    //bool findNode(int x,cNode**&p,int& level);

    bool insertNode(int x);
    bool removeNode(int x, bool side);
    bool changeNode(int x,int newValue);

};

#endif // CBINARYTREE_H
