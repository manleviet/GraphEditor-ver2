/****************************************************
* Auteur : MAN Le Viet, HO The Nhan, HUYNH Ngoc Tho
* C'est une classe hérité de la classe QGraphicsScene
*
*****************************************************/

#ifndef DIAGRAMSCENE_H
#define DIAGRAMSCENE_H

#include <QGraphicsScene>
#include "node.h"

class DiagramScene : public QGraphicsScene
{
    Q_OBJECT

public:
    enum Mode { InsertCycle, InsertTask, InsertFictiveTask, Move };

    DiagramScene();
    void setMode(Mode mode);
    void reset();

    void setNode(Node *node);
    void setTask(Task *task);

signals:
    void sceneChanged();

protected:
    void keyPressEvent(QKeyEvent * keyEvent);
    void mouseDoubleClickEvent (QGraphicsSceneMouseEvent * mouseEvent);
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);

private:
    int firstId();
    int findIdNode(QString &string);

    const static int MAX_ID_NODE = 100;

    Mode myMode;
    QString idNode[MAX_ID_NODE];
    bool idTaked[MAX_ID_NODE];

    QGraphicsLineItem *line;
};

#endif // DIAGRAMSCENE_H
