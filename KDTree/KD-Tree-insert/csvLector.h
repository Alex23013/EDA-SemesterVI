#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "coordinate.h"

vector<cCoordinate> csvLector(string g)
{
    ifstream  data(g);
    vector <cCoordinate> finalInput;
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
		//	cout<<" "<<cell;
				inputDot.push_back(stod (cell,&sz));
		}		
			i++;
        }
        //cout<<"\n";
        cCoordinate a(inputDot);
        finalInput.push_back(a);
        inputDot.clear();
    }
    return finalInput;
 }
