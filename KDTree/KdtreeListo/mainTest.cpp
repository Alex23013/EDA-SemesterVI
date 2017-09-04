#include<iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <time.h>
#include "Tdot.h"
#include "Tkdtree.h"
#include "csvLector.h"

using namespace std;

int main(){
	cout<<"Kdtre?\n";	
	///////////////////
	srand((unsigned) time(NULL));
	vector<Dot> TestPoints;
	for(int i ;i < 5;i++){
		Dot b(2);
		TestPoints.push_back(b);
	}	
	
	
	//string a ="as.csv";
 	//vector<Dot> TestPoints;
 	//TestPoints = csvLector(a);
 
 cout<<"A vector of : 2Dpoints\n";
    for(int i =0 ; i< TestPoints.size();i++){
		cout<<"(";
		TestPoints[i].print();
		cout<<")";
	}
	//////////////////
	KdTree<Dot> tree; 
	//tree.build(TestPoints,3,0);
	tree.mInsert(TestPoints[0]);
	//tree.content();
	
}
