#include <QPainter>
#include <QGraphicsTextItem>
#include <QStyleOption>

#include "diagramscene.h"
#include "node.h"
#include "task.h"

class QObject;

Node::Node(DiagramScene *diagramscene) : scene(diagramscene)
{
    setRect(-15, -15, 30, 30);
    myPolygon = this->polygon();
    setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
}

QString &Node::id()
{
    return _id;
}

void Node::setId(const QString & id)
{
    _id = id;
}

void Node::addTask(Task *task)
{
    tasks.append(task);
}

void Node::removeTask(Task *task)
{
    int index = tasks.indexOf(task);

    if (index != -1) tasks.removeAt(index);
}

QRectF Node::boundingRect() const
{
    qreal adjust = 2;
    return QRectF(-15 - adjust, -15 - adjust,
                  30 + 3 + adjust, 30 + 3 + adjust);
}

QPainterPath Node::shape() const
{
    QPainterPath path;
    path.addEllipse(-15,-15,30,30);
    return path;
}

void Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::darkGray);
    painter->drawEllipse(rect().x() + 3, rect().y() + 3,
                         rect().width(), rect().height());

    QRadialGradient gradient(-3, -3, 10);
    if (option->state & QStyle::State_Sunken) {
        gradient.setCenter(3, 3);
        gradient.setFocalPoint(3, 3);
        gradient.setColorAt(1, QColor(Qt::yellow).light(120));
        gradient.setColorAt(0, QColor(Qt::darkYellow).light(120));
    } else {
        gradient.setColorAt(0, Qt::yellow);
        gradient.setColorAt(1, Qt::darkYellow);
    }

    painter->setPen(QPen(Qt::black, 0));
    painter->setBrush(gradient);
    painter->drawEllipse(rect());
    painter->drawText(rect(), Qt::AlignCenter | Qt::AlignHCenter , _id);
    if (isSelected()){
        painter->setPen(QPen(Qt::blue, 1, Qt::DashDotLine));
        painter->drawEllipse(rect().x() - 3, rect().y() - 3,
                             rect().width() + 6, rect().height() + 6);
        painter->drawText(rect(), Qt::AlignCenter | Qt::AlignHCenter , _id);
    }
}

QVariant Node::itemChange(GraphicsItemChange change, const QVariant &value)
{
    if (change == QGraphicsItem::ItemPositionChange){
        foreach (Task *task, tasks)
            task->updatePosition();
    }
    return value;
}
