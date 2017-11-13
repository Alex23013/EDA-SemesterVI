#include "cfatnodes.h"
#include "cnode.h"
#include <iostream>///debugging
using namespace std;///debugging

cfatNode :: cfatNode(){
cbinarytree* firstChild =new cbinarytree(0);
versiones.push_back( firstChild);
versionActual= versiones[0];
}

void cfatNode :: insertValue(int x){
 addVersion();
 versionActual->insertNode(x);
}

void cfatNode :: changeValue(int x, int newX){
 addVersion();
 versionActual->changeNode(x, newX);
}

void cfatNode::addVersion(){
     int newTiempo = versionActual->tiempoActual +1;
    cbinarytree* newChild =new cbinarytree(newTiempo);
    versiones.push_back(newChild);
    versionActual= versiones[newTiempo];

   // cout<<"to copy \n";
    vector <cNode*> c;
    cNode* tmpChild =versiones[newTiempo-1]->root;
    c.push_back(tmpChild);
    int len;
    while(c.size()!=0){
        len=c.size();
        for(int i=0;i<len;i++){
        if(c[i]){
     //       cout<<c[i]->info<<"("<<c[i]->version<<") ";
            versionActual->insertNode(c[i]->info);
            c.push_back(c[i]->childs[0]);
            c.push_back(c[i]->childs[1]);
        }
    //    else
    //      cout << "- ";
        }
        cout<<endl;
        c.erase(c.begin(),c.begin()+len);
    }

}

void cfatNode :: deleteVersion(){
    versiones.pop_back();
}

void cfatNode :: changeVersionActual(int newActualVersion){ /*aun no es utilizada*/
 versionActual = versiones[newActualVersion];
}

void cfatNode :: test(){

    cout<<"TEST INIZIALATED\n";

   /// versionActual->insertNode(12);
    //versionActual->contenido();
    int input[4]={20,3,17,89};
    for(int i =0;i< 4;i++){
        insertValue(input[i]);
    }
    /*addVersion();
    versionActual-> insertNode(233);
    addVersion();
    versionActual->removeNode(23,1);
    addVersion();*/

    /*int numVersiones = versiones.size();
    cout<<"versiones creadas: "<<numVersiones<<endl;
    for(int i =0;i<numVersiones;i++){
        contenidoEnT(i);}*/

}

void cfatNode :: contenidoActual(){
    cout<<"\ncontenido del Arbol en tiempo Actual\n";
    versionActual->contenido();
}


void cfatNode :: contenidoEnT(int tiempo){
    cout<<"\ncontenido del Arbol en tiempo = " <<tiempo<<"\n";
    versiones[tiempo]->contenido();
}
