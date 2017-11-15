#include "cfatnodes.h"
#include "cnode.h"
#include <iostream>///debugging
using namespace std;///debugging

cfatNode :: cfatNode(){
cbinarytree* firstChild =new cbinarytree(0);
versiones.push_back( firstChild);
versionActual= versiones[0];
cambio =0;
}

void cfatNode :: insertValue(int x){
 if(cambio == 0){
     addVersion();
     versionActual->insertNode(x);
 }
}

void cfatNode:: deleteValue(int x, bool side){
    if(cambio == 0){
        addVersion();
        versionActual->removeNode(x,side);
    }
}


void cfatNode :: changeValue(int x, int newX){
    if (cambio == 0){
        addVersion();
        versionActual->changeNode(x, newX);
    }
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

void cfatNode ::reset(){
    for (int i =1;i<versiones.size();i++){
        versiones[i] = nullptr;
    }
}

void cfatNode :: test(){

    cout<<"TEST INIZIALATED\n";
    //versionActual->contenido();
    int input[7]={20,4,17,89,200,3,55};
    for(int i =0;i< 0;i++){
        insertValue(input[i]);
    }

/*    int numVersiones = versiones.size();
    cout<<"versiones creadas: "<<numVersiones<<endl;
    for(int i =0;i<numVersiones;i++){
        contenidoEnT(i);}
*/
}

void cfatNode :: contenidoActual(){
    cout<<"\ncontenido del Arbol en tiempo Actual\n";
    versionActual->contenido();
}


void cfatNode :: contenidoEnT(int tiempo){
    cout<<"\ncontenido del Arbol en tiempo = " <<tiempo<<"\n";
    versiones[tiempo]->contenido();
}

void cfatNode ::undo(){
    cambio ++;
    int p =versiones.size()-1-cambio;
    if(p >= 0){
        versionActual = versiones[p];
    }else{
        cambio--;
    }

}

void cfatNode ::redo(){
    cambio--;
    int p = versiones.size()-1-cambio;
    if (p < versiones.size()){
        versionActual = versiones[p];
    }else{
        cambio++;
    }

}
