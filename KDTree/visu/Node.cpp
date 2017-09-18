#include "Node.h"

cNode::cNode(cCoordinate coor, int cutCoordinate): mCoord(coor)
{
    mChild[0] = mChild[1] = nullptr;
    mCutCoordinate = cutCoordinate;
};


cNode::~cNode(){
};


bool cNode::mIsLeaf(){
    return (mChild[0] || mChild[1]);
};

int cNode::mGetCutCoordinateVal(){
    return mCutCoordinate;
};

double cNode::mGetCoordinate(int dimension){
    return mCoord[dimension];
};


cCoordinate cNode::mGetCoordinate(){
    return mCoord;
}


cNode** cNode::mGetChildDir(bool child){
    return &(mChild[child]);
}


cNode* cNode::mGetChild(bool child){
    return (mChild[child]);
}


void cNode::mPrintCoordinates(){
    mCoord.print();
}
