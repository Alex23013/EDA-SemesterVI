#include "array.h"

double calcDotDistancia(Dot A, Dot B){
    double sumaDif=0;
    for(int i = 0; i < A.dotContent.size(); i++){
       sumaDif += pow(A.dotContent[i]-B.dotContent[i],2);
    }
    return sqrt(sumaDif);
}

Array :: Array(int numOfDots, int numOfDim){
    for (int i = 0; i <  numOfDots; i++){
        Dot tmp(numOfDim);
        arrayContent.push_back(tmp);
        }
	this->promDistance=0;
	this->minDistance=10000;
	this->maxDistance=0;
}

void Array :: print(){
    for(int i = 0; i< arrayContent.size();i++){
       cout<<"(";
	arrayContent[i].print();
       cout<<")\t";
    }
}

double Array :: caldistance(){
	double tmp =0; 
	int cont =0;   
	//cout<<"\npoint example: (";arrayContent[0].print();cout<<")"; //para ver el primer punto
	for(int i = 0; i< arrayContent.size();i++){
	       for(int j = i+1; j< arrayContent.size();j++){
	       	tmp=calcDotDistancia(arrayContent[i],arrayContent[j]);
		/*cout<<"[";
			cout<<tmp; //para ver el vector de distancias calculadas
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

