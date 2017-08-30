#include<iostream>
#include"array.h"
using namespace std;



int main(){
cout<<"Curse of Dimensionality\n";
srand((unsigned) time(NULL));

int dim[8]={2,3,10,100,200,500,1000,5000};
double minDistance=0;
double maxDistance=0;

for(int i=0;i<3;i++){
	cout<<"\n\n#"<<dim[i]<<"dim";
	Array array1(2,dim[i]);
	cout<<"\nprom: "<<array1.caldistance();
	}
}
