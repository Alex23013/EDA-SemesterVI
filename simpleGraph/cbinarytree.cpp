#include "cbinarytree.h"
#include <vector>
#include<iostream>   //only for debugging
using namespace std; //only for debugging

cbinarytree::cbinarytree()
{
    root= nullptr;
}

void cbinarytree::test(){
    cNode** p;
    p=&root;
    *p=new cNode(0,300);

}

void cbinarytree:: contenido(){
    cout<<"\ncontenido del Arbol\n";
          vector <cNode*> c;
          c.push_back(root);
          int len;
          while(c.size()!=0){
              len=c.size();
              for(int i=0;i<len;i++){
              if(c[i]){
                  cout<<c[i]->info<<" ";
                  c.push_back(c[i]->hijos[0]);
                  c.push_back(c[i]->hijos[1]);
              }
              else
                cout << "- ";
              }
              cout<<endl;
              c.erase(c.begin(),c.begin()+len);
          }
}
