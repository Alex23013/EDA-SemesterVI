#include "cbinarytree.h"
#include <vector>
#include<iostream>   //only for debugging
using namespace std; //only for debugging

cbinarytree::cbinarytree()
{
    root= nullptr;
}

void cbinarytree::test(){
   /* cNode** p;
    p=&root;
    *p=new cNode(0,3);

    (*p)->childs[0] = new cNode(0,4);
    (*p)->childs[1] = new cNode(0,2);
   */
    int a[7]={10,5,12,3,7,11,15};
    for(int i =0;i <7;i++){
        insertNode(a[i]);
    }
    contenido();

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
                  c.push_back(c[i]->childs[0]);
                  c.push_back(c[i]->childs[1]);
              }
              else
                cout << "- ";
              }
              cout<<endl;
              c.erase(c.begin(),c.begin()+len);
          }
}

bool cbinarytree::findNode(int x,cNode**&p,int & level){
        p=&root;
        while(*p && (*p)->info != x){
            p=&((*p)->childs[(*p)->info < x]);
            level++;
            }
        return *p;
        }

bool cbinarytree::insertNode(int x){
        cout<<"nodo_in:"<<x<<endl;
        cNode** p;
        int level =0;
        if(findNode(x,p,level)){
            return 0;}
        *p=new cNode(x,level,0);
        return 1;
        }


cNode** cbinarytree:: swapNode(cNode** q ){
        q = &(*q)->childs[0];
        while ((*q)->childs[1])
        {
            q = &((*q)->childs[1]);
        }
        return q;
    }

bool cbinarytree::removeNode(int x){
    cNode**p, **q;
    int l=0;
    if (!findNode(x, p,l))
    {
        return 0;
    }
    if ((*p)->childs[0] && (*p)->childs[1])
    {
        q = swapNode(p);
        (*p)->info = (*q)->info;
        p = q;
    }
    cNode* t = *p;
    *p = (*p)->childs[(*p)->childs[1]!=0];
    delete t;
    return 1;
}
