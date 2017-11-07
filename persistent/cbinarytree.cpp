#include "cbinarytree.h"
#include <vector>
#include<iostream>   //only for debugging
using namespace std; //only for debugging

cbinarytree::cbinarytree()
{
    root= new cfatNode();
    tiempoActual =0;
}

void cbinarytree::test(){
   cout<<"TEST INIZIALATED\n";
    insertNode(12);
    insertNode(23);
    insertNode(120);
    insertNode(3);
    insertNode(1);
    //contenido();
    removeNode(3,0);
    //contenido();
    changeNode(3,2);
    contenido();

    cout<<"Tiempo actual"<<tiempoActual<<endl;
    contenidoEnT(1);
    int numVersiones = root->versiones.size();
    cout<<"versiones creadas: "<<numVersiones<<endl;
    for(int i =0;i<numVersiones;i++){
        contenidoEnT(i);
    }
}


void cbinarytree:: contenido(){
    cout<<"\ncontenido del Arbol en tiempoActual" <<tiempoActual<<"\n";
          vector <cNode*> c;
          c.push_back(root->versionActual);
          int len;
          while(c.size()!=0){
              len=c.size();
              for(int i=0;i<len;i++){
              if(c[i]){
                  cout<<c[i]->info<<"("<<c[i]->version<<") ";
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

void cbinarytree:: contenidoEnT(int tiempo){
    cout<<"\ncontenido del Arbol en tiempo = " <<tiempo<<"\n";
          vector <cNode*> c;
          c.push_back(root->versiones[tiempo]);
          int len;
          while(c.size()!=0){
              len=c.size();
              for(int i=0;i<len;i++){
              if(c[i]){
                  if(c[i]->version <= tiempo){
                    cout<<c[i]->info<<"("<<c[i]->version<<") ";
                  }

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

void cbinarytree:: setTime(int newTime){
    tiempoActual = newTime;
    root->changeVersionActual(newTime);
}


void cbinarytree::findNode(int x,cNode*&p,int & level){
    p=root->versionActual;
    while(p && (p)->info != x){
        //cout<<"p: "<<p->info<<endl;
        bool dir = p->info < x;
        if(p->childs[dir]){
            p=(p)->childs[dir];
            level++;
        }else
            {
            return ;
            }
        }
}

bool cbinarytree::insertNode(int x){
    cout<<"nodo_in:"<<x<<endl;
    int level =0;
    if(root->versiones.size()==0){
        cNode* firstChild = new cNode(x,level,tiempoActual);
        root->versiones.push_back(firstChild);
        root->versionActual = root->versiones[0];
    }else{
         tiempoActual++;
        root->addVersion();
        cNode* p;
        findNode(x,p,level);
        //cout<<"p->"<<p->info;
        cNode* newChild = new cNode(x,level,tiempoActual);
        bool dir = p->info < x;
        p->inject(newChild,dir);
    }

    return 1;
}

bool cbinarytree::removeNode(int x, bool side){
    cout<<"del nodo "<<x<<" delete child["<<side<<"]\n";
    int level =0;
    root->addVersion();
    cNode* p;
    findNode(x,p,level);
    //cout<<"p->"<<p->info;
    p->eject(side);
    tiempoActual++;
    return 1;
}

bool cbinarytree:: changeNode(int x,int newValue){
     cout<<"replace nodo "<<x<<" por "<<newValue<<"\n";
     int level =0;
     root->addVersion();
     cNode* p;
     findNode(x,p,level);
     //cout<<"p->"<<p->info;
     p->changeValue(newValue);
     tiempoActual++;
     return 1;
 }



