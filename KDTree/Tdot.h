#ifndef TDOT_H
#define TDOT_H

#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std; 
class Dot{
public:
	vector<double> dotContent;

Dot(){
	for (int i = 0; i <  2; i++){
       dotContent.push_back((double)(rand() % 101));
	   // dotContent.push_back((double)(rand() % 101)/100);
    }	
}

Dot(int numberOfDim){
    for (int i = 0; i <  numberOfDim; i++){
       dotContent.push_back((double)(rand() % 101));
	   // dotContent.push_back((double)(rand() % 101)/100);
    }
}

Dot(int numberOfDim, double deafult){
    for (int i = 0; i <  numberOfDim; i++){
       dotContent.push_back(deafult);
    }
}

Dot( vector<double> deafult){
    for (int i = 0; i <  deafult.size(); i++){
       dotContent.push_back(deafult[i]);
    }
}


void   print(){
    for(int i = 0; i< dotContent.size();i++){
        printf("%g  ",dotContent[i]);
    }
}

int compare (Dot b, int dim){ //-1 soy menor || +1 soy mayor || 0 soy igual
	//cout<<"["<<dotContent[dim]<<"_"<<b.dotContent[dim]<<"]"<<endl;
	if (dotContent[dim] < b.dotContent[dim]){
		return -1;
	}
	else if (dotContent[dim] > b.dotContent[dim]){
		return 1;
	}else{
		return 0;	
	}
}

};

#endif
