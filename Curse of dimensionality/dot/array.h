#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include"dot.h"
using namespace std;

double calcDotDistancia(Dot A, Dot B){
    double sumaDif=0;
    for(int i = 0; i < A.dotContent.size(); i++){
       sumaDif += pow(A.dotContent[i]-B.dotContent[i],2);
    }
    return sqrt(sumaDif);
}

class Array{
public:
	vector<Dot> arrayContent;
	double minDistance;
	double maxDistance;
	double promDistance;

Array(int numOfDots, int numOfDim){
    srand((unsigned) time(NULL));

    for (int i = 0; i <  numOfDots; i++){
        Dot tmp(numOfDim);
        arrayContent.push_back(tmp);
        }
	this->promDistance=0;
	this->minDistance=10000;
	this->maxDistance=0;
}

void print(){
    for(int i = 0; i< arrayContent.size();i++){
       cout<<"(";
	arrayContent[i].print();
       cout<<")\t";
    }
}

double caldistance(){
double tmp =0; 
int cont =0;   
cout<<"ejm dt: ";
//arrayContent[0].print();
for(int i = 0; i< arrayContent.size();i++){
       for(int j = i+1; j< arrayContent.size();j++){
       	tmp=calcDotDistancia(arrayContent[i],arrayContent[j]);
	/*cout<<"[";
		cout<<tmp;
	cout<<"]";*/
	if(tmp<minDistance){
		minDistance=tmp;
		}
	if(tmp>maxDistance){
		maxDistance=tmp;
		}

	promDistance+=tmp;
cont++;
	//cout<<"\n min: "<<minDistance<<" max: "<<maxDistance<<endl;
  
	}
    }
promDistance=promDistance/cont;
cout<<"\nmin: "<<minDistance;
cout<<"\nmax: "<<maxDistance;
return promDistance;
}


};

//la implementacion en el .cpp
//los includes en el .cpp
//en vez de <vector> usar double **tmp;
