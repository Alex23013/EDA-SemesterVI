#include<iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <time.h>
#include "Tdot.h"
#include "Tkdtree.h"

using namespace std;

int main(){
	cout<<"Kdtre?\n";	
	///////////////////
	Dot a(2);
	cout<<"dot example\n";
	//a.print();
	/////////////////
	srand((unsigned) time(NULL));
	vector<Dot> TestPoints;
	for(int i ;i < 5;i++){
		Dot b(2);
		TestPoints.push_back(b);
	}
	//////////////////
	KdTree<Dot> tree; 
	tree.build(TestPoints,4);
	tree.contenido();
	
}
