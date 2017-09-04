#include "Tdot.h"
#include<sstream>
#include <math.h>
#include <iostream>
using namespace std;

template <typename T>
int digitos_num ( T Number )
{
    string number;
    stringstream ss;
    ss << Number;
    number = ss.str();
    return number.size();
}
template <typename T>
int max_digitos(vector<T>* a,int actualDim){
    int n = a->size();
    double max=0;
    for(int i =0;i< n;i++){
        //cout<<" max : "<<max<<"="<<a->at(i).dotContent[actualDim];
		if(max < (a->at(i)).dotContent[actualDim]){
            max=(a->at(i)).dotContent[actualDim];
        }
        
    }
    return max;
}

template<typename T>
void sortPoints(vector<T> *a, int actualDim){
int n = a->size();
int temp[10];
vector<Dot> res;
int div =10;
int digito;	
int num_digitos = digitos_num(max_digitos(a,actualDim));
//cout<<"\nmax_digitos(a,actualDim) "<<max_digitos(a,actualDim);
//cout<<"\nnum_digitos"<<num_digitos<<endl;
for(int j =0;j<num_digitos;j++){
    for(int i=0;i<10;i++){temp[i]= 0;}

    for(int i =0;i<n;i++){
        //cout<<(a[i]%div)/(div/10)<<" / ";//para ver que digito se esta analizando
        digito =(fmod((a->at(i)).dotContent[actualDim],div))/(div/10);
        temp[digito]+=1;
        Dot tmpDot((a->at(i)).dotContent.size(),0.00);
        res.push_back(tmpDot);
    }
   /* cout<<"\n temp: ";
    for(int i=0;i<10;i++){;
        cout<<temp[i]<<" ";}*/

    for(int i=0;i<10;i++){;
        temp[i+1]=temp[i]+temp[i+1];}
        
/*	cout<<"\n tempSum: ";
    for(int i=0;i<10;i++){;
        cout<<temp[i]<<" ";}
*/    
	for(int i=n-1;i>=0;i--){
        digito =(fmod((a->at(i)).dotContent[actualDim],div))/(div/10);
        //cout<<" di: "<<digito;
		temp[digito]-=1;
        res[temp[digito]]=a->at(i);
    }
    /*cout<<"\n tempPostSum: ";
    for(int i=0;i<10;i++){;
        cout<<temp[i]<<" ";}
*/  
    for(int i =0;i <n ;i++){
        a->at(i)= res[i];
    }
    div=div*10;
    //cout<<"\n------------------------\n";//para asegurarse la cantidad de loops
    }

}

/*template <typename T>
void radix_sort(vector<T> *a){
int n = a->size();
int temp[10];
int res[n];
int div =10;
int digito;
int num_digitos = digitos_num(max_digitos(a));
for(int j =0;j<num_digitos;j++){
    for(int i=0;i<10;i++){temp[i]= 0;}

    for(int i =0;i<n;i++){
        //cout<<(a[i]%div)/(div/10)<<" / ";//para ver que digito se esta analizando
        digito =(a->at(i)%div)/(div/10);
        temp[digito]+=1;
    }
    for(int i=0;i<10;i++){;
        temp[i+1]=temp[i]+temp[i+1];}

    for(int i=n-1;i>=0;i--){
        digito =(a->at(i)%div)/(div/10);
        temp[digito]-=1;
        res[temp[digito]]=a->at(i);
    }
    for(int i =0;i <n ;i++){
        a->at(i)= res[i];
    }
    div=div*10;
    //cout<<"\n------------------------\n";//para asegurarse la cantidad de loops
    }
}*/
