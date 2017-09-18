#ifndef KD_TREE_KDTREE_H
 #define KD_TREE_KDTREE_H
 #include <math.h>
 #include<time.h>
#include<QPainter>
 #include "Node.h"
 #include "radix.h"
 
 class cKDTree {
 	public:
 		cNode* mRoot;
 		int mDimensions;
        vector <QRectF> dotsInX;
        vector <QRectF> dotsInY;
 		cKDTree(int);
 		void mInsert(cCoordinate);
 		bool mInsertAux(cCoordinate,cNode**,int);
        double findClosest(QPointF punto, bool eje,bool dir,QPainter * painter);
 		virtual ~cKDTree ();
        void print(QPainter * painter, int depth );
        void print2(cNode* t, int nivel,QPainter * painter,cNode* father,int depth );
        float distance(cCoordinate , cCoordinate );
        string vocabulary="xyz";
        void build(vector<cCoordinate> x);
 };
  #endif
