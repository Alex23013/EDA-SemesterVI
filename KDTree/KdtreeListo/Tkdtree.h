#include "Tnode.h"
#include "radix.h"
#include <vector>
template<typename T>
class KdTree{
public:	
	Tnode<T>* root;
	int mDimensions;
	

Kdtree(){
		root=NULL;
		mDimensions = 2; 
	}

	
Tnode<T>* split(vector<T> x,int actualDim){
	//for(int i = 0; i< x.size();i++){       cout<<"(";	x[i].print();       cout<<") ";    }
    sortPoints(&x,actualDim);
  	cout<<"\nsort ";	for(int i = 0; i< x.size();i++){       cout<<"(";	x[i].print();       cout<<") ";    }
	int median = x.size()/2;
	cout<<"\nmediam ";
	x[median].print();
	return new Tnode<T>* (x); 	
	}


bool mInsertAux(Dot coord, Tnode<T>** t,int cd){
    if (*t==NULL)
    {
        Tnode<T>* aux = new Tnode<T>(coord,cd);
        *t = aux;
        return 1;
    }
    if (coord.dotContent == ((*t)->info).dotContent)
    {
        return 0;
    }
    bool c=(coord.dotContent[cd] >= ((*t)->info).dotContent[cd]);
    Tnode<T>** p=&(*t)->childs[c];
    return mInsertAux(coord,p,(cd+1) % mDimensions);
}


void mInsert(Dot point){
    if ( mDimensions != point.getDimensions() ) {
        cout << "Dimension invalida. Asigne coordenadas de la dimension: "<< mDimensions << endl;
        return;
    }
    if(!mInsertAux(point,&root,0)){
        cout<<"Insertado correctamente"<<endl;
    }
    else{
        cout<<"La coordenada ya esta en el arbol"<<endl;
    }
}

void build (vector<T> x,int depth){ 
	
}	
bool remove();
void contenido(){
	cout<<"\ncontenido del Arbol\n";
          vector <Tnode<T>* > c;
          c.push_back(root);
          int len;
          while(c.size()!=0){
              len=c.size();
              for(int i=0;i<len;i++){
              if(c[i]){
		          c[i]->print();
				  cout<<" ";
		          c.push_back(c[i]->childs[0]);
		          c.push_back(c[i]->childs[1]);
              }
              else
              	cout << "- ";
              }
              cout<<endl;
              c.erase(c.begin(),c.begin()+len);
          }
      }
};

/*

Tnode<T>* build(vector<T> x, int depth, int dimBusqueda){
	while(actualDim < depth){
		//for(int i = 0; i< x.size();i++){       cout<<"(";	x[i].print();       cout<<") ";    }
	    sortPoints(&x,actualDim);
	  	cout<<"\nsort ";	for(int i = 0; i< x.size();i++){       cout<<"(";	x[i].print();       cout<<") ";    }
		int median = x.size()/2;
		cout<<"\nmediam ";
		x[median].print();
		
		vector<T> mitadA(x.begin(),(x.begin()+median));
		vector<T> mitadB(x.begin()+(median+1), x.end());
		cout<<"\nmitadA ";	for(int i = 0; i< mitadA.size();i++){       cout<<"(";	mitadA[i].print();       cout<<") ";    }
		cout<<"\nmitadB ";	for(int i = 0; i< mitadB.size();i++){       cout<<"(";	mitadB[i].print();       cout<<") ";    }
		x.erase(x.begin()+median);
		actualDim++;
		}
	}
*/

/*	
bool find(T x, Tnode<T>**&p, int dim ){
	p=&root;
	cout<<"f "<<(*p)->info.dotContent[dim];
	while(*p && (*p)->info.dotContent[dim] != x.dotContent[dim]){
		p=&((*p)->childs[((*p)->info).dotContent[dim] < x.dotContent[dim]]);		
		}
	return *p;
	}
*/
