#ifndef GRAPHSCENE_H
#define GRAPHSCENE_H

#include <QGraphicsScene>

class cfatNode;

class GraphScene : public QGraphicsScene {
    Q_OBJECT

private:
    cfatNode* mainVector;
public:
    explicit GraphScene(QObject* parent = 0);
    void createTree();
    void showTree();
    void undoTree();
    void redoTree();
    void insertElement(int x);
    void deleteElement(int x, bool side);

/*protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) override;*/
};


#endif //GRAPHSCENE_H
