#include "cbinarytree.h"
#include <vector>
#include<iostream>   //only for debugging
using namespace std; //only for debugging

cbinarytree::cbinarytree()
{
    root= nullptr;
    tiempoActual =0;
}

void cbinarytree::test(){
    cNode* p1 = new cNode(10,0,0);
    cfatNode** p;
    p=&root;
    *p=new cfatNode(p1);
    contenido();

    cNode* p11 = new cNode(9,1,1);
    (*p)->addNodeVersion(p1,p11,0);
    this->tiempoActual++;
    contenido();

    cNode* p12 = new cNode(11,1,2);
    (*p)->addNodeVersion(p1,p12,1);
    this->tiempoActual++;
    contenido();

    cNode* p22 = new cNode(21,2,3);
    (*p)->addNodeVersion(p12,p22,1);
    this->tiempoActual++;
    contenido();
    insertNode(56);
    contenido();

    insertNode(6);
    contenido();
    /*int a[7]={10,5,12,3,7,11,15};
    for(int i =0;i <7;i++){
        insertNode(a[i]);
    }
    contenido();*/

}

void cbinarytree:: contenido(){
    cout<<"\ncontenido del Arbol en t" <<tiempoActual<<"\n";
          vector <cfatNode*> c;
          c.push_back(root);
          int len;
          while(c.size()!=0){
              len=c.size();
              for(int i=0;i<len;i++){
              if(c[i]){
                  cout<<c[i]->getinfo()<<" ";
                  c.push_back(c[i]->getChilds(0));
                  c.push_back(c[i]->getChilds(1));
              }
              else
                cout << "- ";
              }
              cout<<endl;
              c.erase(c.begin(),c.begin()+len);
          }
}

bool cbinarytree::findNode(int x,cfatNode**&p,cNode* &padre,int & level,bool &dir){
        p=&root;
        cout<<"$"<<root->versionActual->info;
        padre = root->versionActual;
        while(*p && (*p)->getinfo() != x){
            dir =(*p)->getinfo() < x;
            cfatNode* pp =(*p)->getChilds(dir);
            p=&(pp);
            //padre = padre->childs[dir]->getVersions()[0];
            level++;
            }
        return *p;
        }

bool cbinarytree::insertNode(int x){
        cout<<"nodo_in:"<<x<<endl;
        cfatNode** p;
        int level =0;
        bool dir = 0;
        cNode* padre;
        if(findNode(x,p,padre,level,dir)){
            return 0;}
        //cout<<"node sera insertado en: "<<level<<" level";
        cNode* p2 = new cNode(x,level,0);
        *p=new cfatNode(p2);
        (*p)->addNodeVersion(padre,p2,dir);
        this->tiempoActual++;
        return 1;
        }

/*
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
*/
