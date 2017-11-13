#ifndef GRAPHSCENE_H
#define GRAPHSCENE_H

#include <QGraphicsScene>

//class cbinarytree;
class cfatNode;

class GraphScene : public QGraphicsScene {
    Q_OBJECT

private:
  //  cbinarytree*  binTree;
    cfatNode* mainVector;
public:
    explicit GraphScene(QObject* parent = 0);
    void createTree();
    void showTree();

/*protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) override;*/
};


#endif //GRAPHSCENE_H
