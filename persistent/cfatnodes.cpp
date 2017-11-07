#include "cfatnodes.h"
#include "cnode.h"
#include <iostream>///debugging
using namespace std;///debugging

cfatNode :: cfatNode(){

}

void cfatNode :: addVersion(){
    versiones.push_back(versiones.back());
    versionActual = versiones.back();
}

void cfatNode :: deleteVersion(){
    versionActual = versiones[versiones.size()-2];
    versiones.remove(versiones.size()-1);
}

void cfatNode :: changeVersionActual(int newActualVersion){
    int borrar = versiones.size()-newActualVersion;
    while(borrar > 0){
        deleteVersion();
        borrar--;
    }
}
