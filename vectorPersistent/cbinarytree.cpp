#include "cbinarytree.h"
#include <vector>
#include<iostream>   //only for debugging
using namespace std; //only for debugging

cbinarytree::cbinarytree(int tiempo)
{
    root= nullptr;
    tiempoActual =tiempo;
}

/**/
void cbinarytree:: contenido()
{
   // cout<<"\ncontenido del Arbol en tiempoActual" <<tiempoActual<<"\n";
          vector <cNode*> c;
          c.push_back(root);
          int len;
          while(c.size()!=0){
              len=c.size();
              for(int i=0;i<len;i++){
              if(c[i]){
                  cout<<c[i]->info<<"("<<c[i]->level<<") ";
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
}

void cbinarytree::findNode(int x,cNode*&p,int & level){
    p=root;
    while(p && (p)->info != x){
        //cout<<"p: "<<p->info<<endl;
        bool dir = p->info < x;
        if(p->childs[dir]){
            p=(p)->childs[dir];
            level++;
        }else
            {
            level++;
            return ;
            }
        }
}

bool cbinarytree::insertNode(int x){
    cout<<"nodo_in:"<<x<<endl;
    int level =0;
    if(root){
        //cout<<"es otro hijo \n";
        cNode* p;
        findNode(x,p,level);
        cout<<"p->"<<p->info;
        cout<<"l: "<<level;
        cNode* newChild = new cNode(x,level,tiempoActual);
        bool dir = p->info < x;
        p->inject(newChild,dir);
    }else{
        //cout<<"es raiz\n";
       root = new cNode(x,level,tiempoActual);
      }

    return 1;
}

/**/
bool cbinarytree::removeNode(int x, bool side){
    cout<<"del nodo "<<x<<" delete child["<<side<<"]\n";
    int level =0;
    ///root->addVersion();
    cNode* p;
    findNode(x,p,level);
    cout<<"p->"<<p->info;
    p->eject(side);
    return 1;
}

/**/
bool cbinarytree:: changeNode(int x,int newValue){
     cout<<"replace nodo "<<x<<" por "<<newValue<<"\n";
     int level =0;
     ///root->addVersion();
     cNode* p;
     findNode(x,p,level);
     cout<<"p->"<<p->info;
     p->changeValue(newValue);
     return 1;
 }



