#ifndef NODE_H
#define NODE_H

#include <QGraphicsEllipseItem>

#include "task.h"

class DiagramScene;
class Task;

class Node : public QGraphicsEllipseItem
{
public:
    enum {Type = UserType +15};

    Node(DiagramScene *diagramscene);

    QString &id();
    void setId(const QString &id);
    int type() const
    {return Type;}

    int countTask()
        { return tasks.count(); }
    void addTask(Task *task);
    void removeTask(Task *task);

    QPolygonF polygon() const
        { return myPolygon; }

protected:
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);

private:
    QString _id;
    DiagramScene *scene;
    QList<Task *> tasks;
    QPolygonF myPolygon;
};

#endif // NODE_H
