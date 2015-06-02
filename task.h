#ifndef TASK_H
#define TASK_H

#include <QGraphicsLineItem>

#include "node.h"

QT_BEGIN_NAMESPACE
class QGraphicsPolygonItem;
class QGraphicsLineItem;
class QGraphicsScene;
class QRectF;
class QGraphicsSceneMouseEvent;
class QPainterPath;
class Node;
QT_END_NAMESPACE

class Task : public QGraphicsLineItem
{
    //Q_OBJECT

public:
    enum { Type = UserType + 4 };
    enum TypeTask { TaskNormal, TaskFictive };

    Task(TypeTask typeTask, Node *start, Node *end, QGraphicsItem *parent = 0, QGraphicsScene *scene = 0);

    int type() const
        { return Type; }
    TypeTask typeTask()
        { return myTypeTask; }
    QRectF boundingRect() const;
    QPainterPath shape() const;

    Node *start() const
        { return startNode; }
    Node *end() const
        { return endNode; }

    QString &id()
        { return _id; }
    void setId(const QString &id)
        { _id = id; }

    int weight()
        { return _weight; }
    void setWeight(int weight)
        { _weight = weight; }

    void removeNodes(Task *task);

public slots:
    void updatePosition();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

private:
    QString _id;
    int _weight;
    TypeTask myTypeTask;
    Node *startNode;
    Node *endNode;
    QPolygonF arrowHead;
};

#endif // TASK_H
