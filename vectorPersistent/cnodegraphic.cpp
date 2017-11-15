#include <QBrush>
#include <QGraphicsScene>
#include <QStringBuilder>
#include "cnodegraphic.h"

cnodeGraphic::cnodeGraphic(cNode* data, qreal radius, QGraphicsItem* parent)
    : QGraphicsEllipseItem(550-(data->level*100), data->level*100,
                           radius * 2, radius * 2,  parent)
{
    this->data = data;
    this->setPen(QPen(Qt::black, 1));
    this->setBrush(QColor(0, 0, 255, 127));
    this->setFlag(QGraphicsItem::ItemIsSelectable, true);
    //this->setToolTip(QString::number(data->value.x()) % ", " % QString::number(data->value.y()));
}


void cnodeGraphic::setColor(const QColor &color) {
    this->setBrush(color);
}
