#ifndef GRAPHSCENE_H
#define GRAPHSCENE_H

#include <QGraphicsScene>

class CoordGraph;
class GraphicNode;
class cbinarytree;

class GraphScene : public QGraphicsScene {
    Q_OBJECT

private:
    CoordGraph* graph;
    QGraphicsRectItem* selectRect;
    QPointF selectFirstPoint;
    GraphicNode* selecNodes[2];

    ///////////
    cbinarytree*  binTree;



    void removeSelected(QRectF rect);

public:
    explicit GraphScene(QObject* parent = 0);

    void showGraph();
    void randomizeGraph(int nodesN, int edgesN, double distance, double limitA, double limitB);
/////
    void createTree(int nodos, int valor, int level);
    void showTree();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
};


#endif //GRAPHSCENE_H
