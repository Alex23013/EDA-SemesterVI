#ifndef CBINARYTREE_H
#define CBINARYTREE_H

#include "cnode.h"
#include "cfatnodes.h"
class cbinarytree
{
public:
  cfatNode *root;
  int tiempoActual;


    cbinarytree();
    void test();

    void contenido();
    void contenidoEnT(int tiempo);
    void setTime(int newTime);

    void findNode(int x,cNode*&p,int& level);

    bool insertNode(int x);
    bool removeNode(int x, bool side);
    bool changeNode(int x,int newValue);
    cNode**  swapNode(cNode** q );


    void undo(); // volver un cambio hasta el 0
    void redo(); // retroceder un cambio hasta el actual
};

#endif // CBINARYTREE_H
