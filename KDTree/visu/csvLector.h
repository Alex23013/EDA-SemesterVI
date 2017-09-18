#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "Coordinate.h"

vector<cCoordinate> csvLector(string g)
{
    ifstream  data(g);
    vector <cCoordinate> finalInput;
	vector<double> inputDot;
    string line;
    while(getline(data,line))
    {
        stringstream  lineStream(line);
        string  cell;
		int i =0;
        while(getline(lineStream,cell,','))
        {
		if (i == 0 || i == 1){
            //string::size_type sz;
            //cout<<" "<<cell;
            //inputDot.push_back(stod (cell,&sz));
            std::istringstream iss(cell);
            double ins;
            iss >> ins;
            inputDot.push_back(ins);
		}		
			i++;
        }
        //cout<<"\n";
        cCoordinate a(inputDot);
        //cout<<"{"<<a.mCoordinates[0]<<","<<a.mCoordinates[1]<<"}";
        finalInput.push_back(a);
        inputDot.clear();
    }
    return finalInput;
 }
