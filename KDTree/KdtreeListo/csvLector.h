#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "Tdot.h"

vector<Dot> csvLector(string g)
{
    ifstream  data(g);
    vector <Dot> finalInput;
	vector<double> inputDot;
    string line;
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
        finalInput.push_back(a);
        inputDot.clear();
    }
    return finalInput;
 }
