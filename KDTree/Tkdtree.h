#include "Tnode.h"
#include "radix.h"
#include <vector>
template<typename T>
class KdTree{
public:	
	Tnode<T> *root;
	

Kdtree(){
		root=NULL;
	}
	
bool find(T x, Tnode<T>**&p, int dim ){
	p=&root;
	cout<<"f "<<(*p)->info.dotContent[dim];
	while(*p && (*p)->info.dotContent[dim] != x.dotContent[dim]){
		p=&((*p)->childs[((*p)->info).dotContent[dim] < x.dotContent[dim]]);		
		}
	return *p;
	}
	
void build(vector<T> x, int depth){
	cout<<" depth "<<depth<<endl;
	int actualDim =0;
	while(actualDim < depth){
		//for(int i = 0; i< x.size();i++){       cout<<"(";	x[i].print();       cout<<") ";    }
	    sortPoints(&x,actualDim);
	  	cout<<"\nsort ";	for(int i = 0; i< x.size();i++){       cout<<"(";	x[i].print();       cout<<") ";    }
		int median = x.size()/2;
		cout<<"\nmediam ";
		x[median].print();
		
		if (!root){
			root = new Tnode<T> (x[median]); //TODO: ver xq solo funciona con 2D
		
		}else{
			Tnode<T> ** p;
			if(find(x[median],p,actualDim)){
				cout<<"repe";	
			}else{
				*p=new Tnode<T>(x[median]);
			}
		}
		
		x.erase(x.begin()+median);
		//root->info.print();
		/*vector<T> mitadA(x.begin(),(x.begin()+median));
		vector<T> mitadB(x.begin()+(median+1), x.end());
		cout<<"mitadA ";	for(int i = 0; i< mitadA.size();i++){       cout<<"(";	mitadA[i].print();       cout<<") ";    }
		cout<<"mitadB ";	for(int i = 0; i< mitadB.size();i++){       cout<<"(";	mitadB[i].print();       cout<<") ";    }
		*/
		actualDim++;
	}
	
	
	//root->childs[0] = insert(mitadA,depth+1);
	//root->childs[1] = insert(mitadB,depth+1);
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
