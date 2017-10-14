#ifndef CBINARYTREE_H
#define CBINARYTREE_H

#include"cnode.h"

class cbinarytree
{
public:
  cNode *root;


    cbinarytree();
    void test();
    void contenido();

    bool findNode(int value);
    bool insertNode(int value);
    bool removeNode(int value);
    bool removeSideNode(int value, bool side);


    void undo(); // volver un cambio hasta el 0
    void redo(); // retroceder un cambio hasta el actual
};

#endif // CBINARYTREE_H
