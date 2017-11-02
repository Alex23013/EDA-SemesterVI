#ifndef CBINARYTREE_H
#define CBINARYTREE_H

#include "cnode.h"
#include "cfatnodes.h"
class cbinarytree
{
public:
  cNode *root;


    cbinarytree();
    void test();
    void contenido();

    bool findNode(int x,cNode**&p,int &level);
    bool insertNode(int x);
    bool removeNode(int x);
    cNode**  swapNode(cNode** q );


    void undo(); // volver un cambio hasta el 0
    void redo(); // retroceder un cambio hasta el actual
};

#endif // CBINARYTREE_H
