#ifndef CNODEGRAPHIC_H
#define CNODEGRAPHIC_H


#include <QGraphicsEllipseItem>
#include "cnode.h"
class cnodeGraphic : public QGraphicsEllipseItem
{
private:
    cNode * data; //el level da el centro del circulo

public:

    cnodeGraphic(cNode* data, qreal radius, QGraphicsItem *parent = 0);
    void setColor(const QColor& color);

    cNode* getData() { return data; }
};

#endif // CNODEGRAPHIC_H
