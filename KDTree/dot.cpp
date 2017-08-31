#include "dot.h"

Dot :: Dot(int numberOfDim){
    for (int i = 0; i <  numberOfDim; i++){
        dotContent.push_back((double)(rand() % 101)/100);
    }
}

void Dot ::  print(){
    for(int i = 0; i< dotContent.size();i++){
        printf("%g  ",dotContent[i]);
    }
}



