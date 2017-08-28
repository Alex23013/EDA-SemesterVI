#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include"dot.h"
using namespace std;

double calcDotDistancia(Dot A, Dot B){
    double sumaDif=0;
	//cout<<"dfi: "<<sumaDif;
    for(int i = 0; i < A.dotContent.size(); i++){
	//cout<<"!"<<A.dotContent[i]<<"-"<<B.dotContent[i]<<"!";
	//cout<<"("<<pow(A.dotContent[i]-B.dotContent[i],2)<<")";

       sumaDif += pow(A.dotContent[i]-B.dotContent[i],2);
	//	cout<<"dfi: "<<sumaDif<<"\n";
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
for(int i = 0; i< arrayContent.size();i++){
       for(int j = i+1; j< arrayContent.size();j++){
          // cout<< i<<","<<j
tmp=calcDotDistancia(arrayContent[i],arrayContent[j]);
cout<<"[";
	cout<<tmp;
cout<<"]";
if (i==0){minDistance = maxDistance=tmp;}
if(tmp<minDistance){
minDistance=tmp;
}
if(tmp>maxDistance){
maxDistance=tmp;
}

promDistance+=tmp;


        }
    }
promDistance=promDistance/arrayContent.size();
cout<<"\nmin"<<minDistance;
cout<<"\nmax"<<maxDistance;
return promDistance;
}

/*1 2 3 4
12 13 14
23 24
34
*/

};

//la implementacion en el .cpp
//los includes en el .cpp
//en vez de <vector> usar double **tmp;
