#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "Tdot.h"

using namespace std;
int main()
{
    ifstream  data("ejm.csv");
    vector <Dot> finalInput;
	vector<double> inputDot;
    string line;
    int cont =0;
    while(getline(data,line))
    {
        stringstream  lineStream(line);
        string        cell;
        int i =0;
        while(getline(lineStream,cell,','))
        {
		if (i == 2 || i == 3){
			string::size_type sz;
			//cout<<" "<<cell;
				inputDot.push_back(stod (cell,&sz));
		}		
			i++;
        }
        //cout<<"\n";
        Dot a(inputDot);
        //a.print();
        finalInput.push_back(a);
        cont++;
		
        inputDot.clear();
    }
    cout<<"A vector of "<<cont<<": 2Dpoints\n";
    for(int i =0 ; i< finalInput.size();i++){
		cout<<"(";
		finalInput[i].print();
		cout<<")";
	    //if(i%10 ==0){cout<<"\n";}
	}
 }
