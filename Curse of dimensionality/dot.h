#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <vector>
using namespace std;



class Dot{
public:
vector<double> dotContent;

Dot(int numberOfDim){
    for (int i = 0; i <  numberOfDim; i++){
        dotContent.push_back((double)(rand() % 101)/100);
    }
}

void print(){
    for(int i = 0; i< dotContent.size();i++){
        printf("%g  ",dotContent[i]);
    }
}


};
