#include <iostream>
#include "KDTree.h"
#include "csvLector.h"
using namespace std;

string vocabulario ="xyz"; //aqi se modificaria si qisieramos etiquetar mas de una dimension

/*Funcion para insertar elementos por teclado*/
void addCoordinates(vector<double>* coord, int dim)
{
    for (int i=0;i<dim;i++)
    {
        cout<<vocabulario[i]<<" = ";
        double coordinateI;
        cin>>coordinateI;
        coord->push_back(coordinateI);
    }
}

/*Funcion para insertar elementos Random*/
void addCoordinatesRan(vector<double>* coord, int dim)
{
    for (int i=0;i<dim;i++)
    {
        double coordinateI=rand() % 100;
        coord->push_back(coordinateI);
    }
}

void menu()
{

    cout<<"1) Insertar Datos Random"<<endl;
    cout<<"2) Insertar Datos por Consola"<<endl;
    cout<<"3) Insertar Datos por csv "<<endl;
	cout<<"6) Salir"<<endl;
    cout<<"Opcion -> ";
}


int main() {
	srand(time(NULL));
    cout<<"-------------------------------------KDTree--------------------------------"<<endl;
    int dimensions;
    cout<<"Ingresa la cantidad de dimensiones: ";
    cin>>dimensions;
    cKDTree tree(dimensions);
    int option;
    int quantity;
    vector<double> cord;
    menu();
    cin>>option;
    while (option<6){
        switch(option){
            case 1: //Insert random
            {
                cout << "Ingrese la cantidad de datos a insertar: ";
                cin >> quantity;
                for (int i = 0; i < quantity; i++) {
                    addCoordinatesRan(&cord, dimensions);
                    cCoordinate cordenadita(cord);
                    cordenadita.print();
                    tree.mInsert(cordenadita);
                    cord.clear();
                }
                cout << "-----------------------------Arbol-------------------------" << endl;
                tree.print();
                cout << endl;
                break;
            }
            case 2: // Insert for console
            {
                cout << "Ingrese la cantidad de datos a insertar: ";
                cin >> quantity;
                for (int i = 0; i < quantity; i++) {
                    addCoordinates(&cord, dimensions);
                    cCoordinate cordenadita(cord);
                    cordenadita.print();
                    tree.mInsert(cordenadita);
                    cord.clear();
                }
                cout << "-----------------------------Arbol-------------------------" << endl;
                tree.print();
                cout << endl;
                break;
            }
            case 3: {
            	string archivo;
            	string ext =".csv";
                cout<<"Ingrese el nombre del archivo .csv: ";
                cin>>archivo;
                archivo+=ext;
                cout<<"archivo por abrir: "<<archivo<<endl;
                vector <cCoordinate> asd = csvLector(archivo);
               /* cout<<"A vector of : 2Dpoints\n";
			    for(int i =0 ; i< asd.size();i++){
					asd[i].print();
				}*/
				tree.build(asd);
				cout << "-----------------------------Arbol-------------------------" << endl;
                tree.print();
                cout << endl;
                break;
            }
			default:
				break;
        }
        menu();
        cin>>option;
    }
    return 0;
}
