#include "Coordinate.h"
#include<sstream>
#include <math.h>
#include <iostream>
using namespace std;

template <typename T>
int digitos_num ( T Number ) //para saber cuantas cifras tiene el numero
{
    string number;
    stringstream ss;
    ss << Number;
    number = ss.str();
    return number.size();
}
template <typename T>
int max_digitos(vector<T>* a,int actualDim){//para encontrar el maximo
    int n = a->size();
    double max=0;
    for(int i =0;i< n;i++){
		if(max < (a->at(i)).mCoordinates[actualDim]){
            max=(a->at(i)).mCoordinates[actualDim];
        }        
    }
    return max;
}

template<typename T>
void sortPoints(vector<T> *a, int actualDim) // RadixSort: solo funciona con numeros>0
{
	int n = a->size();
	int temp[10];
	vector<cCoordinate> res;
	int div =10;
	int digito;	
	int num_digitos = digitos_num(max_digitos(a,actualDim));
	for(int j =0;j<num_digitos;j++){
	    for(int i=0;i<10;i++){
			temp[i]= 0;
			}
	    for(int i =0;i<n;i++){
	        //cout<<(a[i]%div)/(div/10)<<" / ";//para ver que digito se esta analizando
	        digito =(fmod((a->at(i)).mCoordinates[actualDim],div))/(div/10);
	        temp[digito]+=1;
	        vector<double> asd(2,0);
	        cCoordinate tmpDot(asd);
	        res.push_back(tmpDot);
	    	}
	    for(int i=0;i<10;i++){
	        temp[i+1]=temp[i]+temp[i+1];
			}
	    for(int i=n-1;i>=0;i--){
	        digito =(fmod((a->at(i)).mCoordinates[actualDim],div))/(div/10);
	        //cout<<" di: "<<digito;
			temp[digito]-=1;
	        res[temp[digito]]=a->at(i);
	    	}
	    for(int i =0;i <n ;i++){
	        a->at(i)= res[i];
	    	}
	    div=div*10;
	    //cout<<"\n------------------------\n";//para asegurarse la cantidad de loops
	    }
}

template <typename T>
void BubbleSort(vector<T>* a, int actualDim){
    int n = a->size();
    for (int i = 0; i < n; i++){
		for(int j=0; j<n-i-1; j++)
	       {
	          if((a->at(j)).mCoordinates[actualDim]>(a->at(j+1)).mCoordinates[actualDim])
	          {
	            vector<double> asd(2,0);
        		cCoordinate tmpDot(asd);
				tmpDot = (a->at(j+1));
	             (a->at(j+1)) = (a->at(j));
	             (a->at(j)) = tmpDot;
	          }
	       }    
    }
}

/*
int Pivot_Sort(vector<cCoordinate>* _array, cCoordinate _start, cCoordinate _end, int actualDim){
    _array->at(_end)
    cCoordinate x() ;
    int i = (_start - 1);
    for (int j = _start; j <= _end - 1; j++){

        if (_array->at(j).mCoordinates[actualDim] <= x){                            ///Solo considera menores pues al hacer swap los mayores
            i++;
            swap(*(_array->begin()+i), *(_array->begin()+j));
        }
    }

    swap(*(_array->begin()+i+1), *(_array->begin()+_end));
    return (i + 1);                                         ///Siguiente a ordenar
}

void QuickSort(vector<int>* _array, int actuaDim){
    vector<int> pila;
    pila.push_back(0);
    pila.push_back(_array->size()-1);

    while ( !pila.empty() ) {

        int fin = pila.back();
        pila.pop_back();                        ///Elimina de la pila
        int ini = pila.back();                  ///Copia a la pila
        pila.pop_back();

        int tmp = Pivot_Sort(_array, ini, fin, actualDim);     ///Ordena el vector[ini;fin] respecto al pivote

        if(tmp-1 > ini){
            pila.push_back(ini);                    ///Agrega lado izquierdo
            pila.push_back(tmp-1);
        }
        if(tmp+1 < fin){
            pila.push_back(tmp+1);                    ///Agrega lado derecho
            pila.push_back(fin);
        }
    }
}*/

