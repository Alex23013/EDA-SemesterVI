
#include "KDTree.h"
cKDTree::cKDTree(int dimensions){
    mRoot = nullptr;
    mDimensions = dimensions;
}


cKDTree::~cKDTree(){
    mRoot = nullptr;
}

void cKDTree::print() {
    print2(mRoot,0);
}

void cKDTree::print2(cNode* t, int level) {
    if (t!=NULL)
    {
        print2(t->mGetChild(1), level+1);
        for (int k = 0; k < mDimensions*level; k++)
        {
            cout << "  ";
        }
        cout<<vocabulary[t->mGetCutCoordinateVal()]<<" "<<(t->mGetCoordinate()).mcity<<"-"<<(t->mGetCoordinate()).mcountry<<endl;
        for (int k = 0; k < mDimensions*level; k++)
        {
            cout << "  ";
        }
        t->mPrintCoordinates();
        print2(t->mGetChild(0), level+1);
    }
}

bool cKDTree::mInsertAux(cCoordinate coord, cNode** t,int cd){
    if (*t==NULL)
    {
        cNode* aux = new cNode(coord,cd);
        *t = aux;
        return 1;
    }
    if (coord == (*t)->mGetCoordinate())
    {
        return 0;
    }
    bool c=(coord[cd] >= (*t)->mGetCoordinate(cd));
    cNode** p=(*t)->mGetChildDir(c);
    return mInsertAux(coord,p,(cd+1) % mDimensions);
}


void cKDTree::mInsert(cCoordinate coord){
    if ( mDimensions != coord.mGetDimension() ) {
        cout << "Dimension invalida. Asigne coordenadas de la dimension: "<< mDimensions << endl;
        return;
    }
    if(mInsertAux(coord,&mRoot,0)){
        //cout<<"Insertado correctamente"<<endl;
    }
    else{
        cout<<"La coordenada ya esta en el arbol"<<endl;
    }
}

void cKDTree:: build(vector<cCoordinate> x){ //construye el arbol
	int actualDim = 0;
	int cont =0;
	int tamX = x.size();
	while(!x.empty()){
		//sortPoints(&x,actualDim% mDimensions); //solo con un dataSet , numeros>0
	  	BubbleSort(&x,actualDim% mDimensions);
		//cout<<"\nsort ";	for(int i = 0; i< x.size();i++){       cout<<"(";	x[i].print();       cout<<") ";    }
		int median = x.size()/2;
		//cout<<"\nmediam ";
		//x[median].print();
		mInsert(x[median]);
		///vector<cCoordinate> mitadA(x.begin(),(x.begin()+median));
		///vector<cCoordinate> mitadB(x.begin()+(median+1), x.end());
		//cout<<"\nmitadA ";	for(int i = 0; i< mitadA.size();i++){       cout<<"(";	mitadA[i].print();       cout<<") ";    }
		//cout<<"\nmitadB ";	for(int i = 0; i< mitadB.size();i++){       cout<<"(";	mitadB[i].print();       cout<<") ";    }
		x.erase(x.begin()+median);
		actualDim++;
		}
}
