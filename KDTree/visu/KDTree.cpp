#include "KDTree.h"
int leftBorder = 620;
int topBorder = 350;
float scaleFactor = 3.5;

float xcenter = +87.6;
float ycenter = -41.8;

int xScale = 1500;//150;
float yScale = 1000;//300;

//MIN //-87.7267334541	41.7690809958
//MAX //-87.5845672362	41.8789661034


cKDTree::cKDTree(int dimensions){
    mRoot = nullptr;
    mDimensions = dimensions;
}


cKDTree::~cKDTree(){
    mRoot = nullptr;
}

void cKDTree::print(QPainter * painter,int depth ) {
    print2(mRoot,0,painter,mRoot,depth);
}

double cKDTree:: findClosest(QPointF punto , bool eje, bool dir,QPainter * painter){
    double dist=10000;
    QPen linepen;
    linepen.setWidth(5);
    linepen.setColor(Qt::red);
    painter->setPen(linepen);
    double res;
    qreal p1x,p1y,p2x,p2y;
    if(eje == 0){  
       if(dir == 0){
        res = 0;
        for(int i =0;i < dotsInY.size();i++){
        dotsInY[i].getCoords(&p1x,&p1y,&p2x,&p2y);
        if( p2x<punto.x() && p2y < punto.y() && p2y-punto.y() < dist ){
                res = p2y;
                dist = p2y-punto.y();
                //QPointF a (punto.x(),p2y);//ok--verde
                //cout<<"ifi"<<dist;
                //painter->drawPoint(a);
                }
            }
        }
       else{//dir ==1
        res = topBorder*2;
        for(int i =0;i < dotsInY.size();i++){
        dotsInY[i].getCoords(&p1x,&p1y,&p2x,&p2y);
        if( p2x<punto.x() && p2y > punto.y() && p2y-punto.y() < dist ){
                res = p2y;
                dist = p2y-punto.y();
                //QPointF a (punto.x(),p2y);//ok--amarilo-hacia:abajo
                //cout<<"ifi"<<dist;
               // painter->drawPoint(a);
            }
         }
       }
       return res;
    }else{//eje ==1
        if(dir == 0){
          res = 0;
          for(int i =0;i < dotsInX.size();i++){
              dotsInX[i].getCoords(&p1x,&p1y,&p2x,&p2y);
              if( p2x<punto.x() && p2y < punto.y() && p2x-punto.x() < dist ){
                      res = p2x;
                      dist = p2x-punto.x();
                      //QPointF a (punto.y(),p2x);//parece
                      //cout<<"ifi"<<dist;
                      //painter->drawPoint(a);
                  }
               }
        }else{//dir ==1
          res = leftBorder*2; //azul
          for(int i =0;i < dotsInX.size();i++){
              dotsInX[i].getCoords(&p1x,&p1y,&p2x,&p2y);
              if( p2x>punto.x() && p1y > punto.y() && p2x-punto.x() < dist ){
                      res = p2x;
                      dist = p2x-punto.x();
                      //QPointF a (punto.y(),p2x);//falta
                      //cout<<"ifi"<<dist;
                      //painter->drawPoint(a);
                  }
               }
        }
        return res;
    }
}

void cKDTree::print2(cNode* t, int level,QPainter * painter,cNode* father,int depth ) {
    if(level > depth){
        return;
    }
    if (t!=NULL)
    {
        //print2(t->mGetChild(1), level+1,painter,t,depth);
        for (int k = 0; k < mDimensions*level; k++)
        {
            cout << "  ";
        }
        cout<<vocabulary[t->mGetCutCoordinateVal()]<<" "<<(t->mGetCoordinate()).mcity<<"-"<<(t->mGetCoordinate()).mcountry<<endl;
        for (int k = 0; k < mDimensions*level; k++)
        {
            cout << "  ";
        }
        ///////////////////////////////
        QPen linepen;
        //puntos
        QPointF a(((t->mGetCoordinate(0)+xcenter)*xScale)+leftBorder,((t->mGetCoordinate(1)+ycenter)*yScale)+topBorder);
        //cout<<"["<<a.x()-leftBorder<<","<<a.y()-topBorder<<"]"<<endl;
        if(t == mRoot){
            linepen.setWidth(3);
            linepen.setColor(Qt::black);
            painter->setPen(linepen);

            QPointF ayLow(a.x(),(0+topBorder)-topBorder);
            QPointF ayHigh(a.x(),(0+topBorder)+topBorder);
            QLineF line2(a,ayLow);
            QLineF line3(a,ayHigh);
            painter->drawLine(line2);
            painter->drawLine(line3);


        }else{

            if(vocabulary[t->mGetCutCoordinateVal()]=='y')
            {
                linepen.setWidth(2);
                QPointF axLow;
                QPointF axHigh;
                axLow.setY(a.y());
                axHigh.setY(a.y());
                if(t == father->mGetChild(0))
                {//soy hijo izq
                    axLow.setX(((father->mGetCoordinate(0)+xcenter)*xScale)+leftBorder);
                   // axHigh.setX((((t->mGetCoordinate(0)+xcenter)*xScale)+leftBorder));
                    axHigh.setX(findClosest(a,1,0,painter));
                    linepen.setWidth(2);
                    linepen.setColor(Qt::red);
                    cout<<"ROJO";
                    painter->setPen(linepen);
                }
                else
                {//soy hijo der

                    //axLow.setX((((t->mGetCoordinate(0)+xcenter)*xScale)+leftBorder));//ok
                    axHigh.setX(((father->mGetCoordinate(0)+xcenter)*xScale)+leftBorder);
                    axLow.setX(findClosest(a,1,1,painter));
                    linepen.setWidth(2);
                    linepen.setColor(Qt::blue);
                    cout<<"AZUL";
                    painter->setPen(linepen);
                }
                QLineF line(a,axLow);
                QLineF line1(a,axHigh);
                painter->drawLine(line);
                painter->drawLine(line1);
                QRectF store(axLow,axHigh);
                dotsInY.push_back(store);
               // cout<<"["<<axLow.x()<<","<<axLow.y()<<"+"<<axHigh.x()<<","<<axHigh.y()<<"]";
            }
            else
            {
                linepen.setWidth(2);
                QPointF ayLow;
                QPointF ayHigh;
                ayLow.setX(a.x());
                ayHigh.setX(a.x());
                if(t == father->mGetChild(0))
                {//soy hijo arriba
                    ayLow.setY(((father->mGetCoordinate(1)+ycenter)*yScale)+topBorder);
                    //ayHigh.setY(((t->mGetCoordinate(1)+ycenter)*yScale)+topBorder);
                    ayHigh.setY(findClosest(a,0,0,painter));
                    linepen.setWidth(2);
                    linepen.setColor(Qt::green);
                    cout<<"VERDE";
                    painter->setPen(linepen);
                }
                else
                {//soy hijo abajo
                    //ayLow.setY(((t->mGetCoordinate(1)+ycenter)*yScale)+topBorder);
                    ayLow.setY(findClosest(a,0,1,painter));
                    linepen.setWidth(2);
                    linepen.setColor(Qt::yellow);
                    cout<<"AMAILLO";
                    painter->setPen(linepen);
                    ayHigh.setY(((father->mGetCoordinate(1)+ycenter)*yScale)+topBorder);
                }

                painter->setPen(linepen);
                QLineF line2(a,ayLow);
                QLineF line3(a,ayHigh);
                painter->drawLine(line2);
                painter->drawLine(line3);
                QRectF store(ayLow,ayHigh);
                dotsInX.push_back(store);


           }
        }

        linepen.setWidth(2);
        linepen.setColor(Qt::black);
        painter->setPen(linepen);
        painter->drawPoint(a);
        QString slevel = QString::number(level);
        painter->drawText(a,slevel);

        //X,Ypoint//painter->drawPoint((t->mGetCoordinate(0)*scaleFactor)+leftBorder,((t->mGetCoordinate(1)*-1)*scaleFactor)+topBorder);
        ///////////////////////////////
        print2(t->mGetChild(1), level+1,painter,t,depth);
        t->mPrintCoordinates();
        print2(t->mGetChild(0), level+1,painter,t,depth);
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

int cKDTree:: myfind(vector<cCoordinate> y,cCoordinate x){
    for(int i = 0;i<y.size();i++){
        if(y[i]== x){return i;}
    }

}

void cKDTree:: build(vector<cCoordinate> x){ //construye el arbol
	int actualDim = 0;
    int cont =0;
    vector<cCoordinate> y(x);
    BubbleSort(&x,0);
    BubbleSort(&y,1);
    cout<<"Mdimension"<<mDimensions;
    while(!x.empty()){
		//sortPoints(&x,actualDim% mDimensions); //solo con un dataSet , numeros>0
        //cout<<"\nsort ";	for(int i = 0; i< x.size();i++){       cout<<"(";	x[i].print();       cout<<") ";    }
        int median;

        if(actualDim % mDimensions == 0){
            median = x.size()/2;
            mInsert(x[median]);
          // if( x[median] ==  y[myfind(y,x[median])]){cout <<"SON IGUALEs\n";};
            x.erase(x.begin()+median);
            y.erase(y.begin()+myfind(y,x[median]));
        }else{
            median = y.size()/2;
            mInsert(y[median]);
           // if( y[median] ==  x[myfind(x,y[median])]){cout <<"SON Y IGUALEs\n";};
            y.erase(y.begin()+median);
            x.erase(x.begin()+myfind(x,y[median]));
        }
        cont+=1;
        if(cont%10==0) cout<<cont<<endl;
		actualDim++;

    }
}
