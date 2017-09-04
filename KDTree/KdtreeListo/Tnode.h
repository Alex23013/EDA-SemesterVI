#ifndef TNODE_H
#define TNODE_H

#include <iostream>
 
using namespace std;

template<typename T>
class Tnode{
public:
	T info;
	Tnode<T>* childs[2];

Tnode(T info, int cd){
	this->info=info;
	childs[0] =NULL;
	childs[1] =NULL;
	}

void print(){
	info.print();
	}
	
};

#endif
