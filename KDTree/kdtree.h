
template<T>
class KdTree{
	T* root;
	int WhatDimension;
	
	Kdtree(){
		this->WhatDimension = 0;
	}
	
	bool find();
	bool insert();
	bool remove();
	
};
