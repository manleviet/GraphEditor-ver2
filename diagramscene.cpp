#include <QGraphicsSceneMouseEvent>
#include <QMessageBox>
#include <QKeyEvent>

#include "diagramscene.h"
#include "task.h"
#include "taskdialog.h"

DiagramScene::DiagramScene() : myMode(Move)
{
    for (int i = 0; i < MAX_ID_NODE; i++){
        idNode[i] = tr("%1").arg(i);
        idTaked[i] = false;
    }
}

void DiagramScene::setMode(Mode mode)
{
    myMode = mode;
}

void DiagramScene::reset()
{
    clear();
    for (int i = 0; i < MAX_ID_NODE; i++){
        idNode[i] = tr("%1").arg(i);
        idTaked[i] = false;
    }
}

void DiagramScene::setNode(Node *node)
{
    Node *nodetemp = new Node(this);
    addItem(nodetemp);
    nodetemp->setPos(node->x(), node->y());
    nodetemp->setId(node->id());
    idTaked[node->id().toInt()] = true;
}

void DiagramScene::setTask(Task *task)
{
    // xac dinh dinh dau va dinh cuoi
    QGraphicsItem *startItem = this->itemAt(QPointF(task->start()->x(), task->start()->y()));
    QGraphicsItem *endItem = this->itemAt(QPointF(task->end()->x(), task->end()->y()));

    Node *startNode = qgraphicsitem_cast<Node *>(startItem);
    Node *endNode = qgraphicsitem_cast<Node *>(endItem);

    // Khoi tao 1 task moi
    Task *tasktemp;
    if (task->typeTask() == Task::TaskNormal)
        tasktemp = new Task(Task::TaskNormal, startNode, endNode);
    else
        tasktemp = new Task(Task::TaskFictive, startNode, endNode);

    startNode->addTask(tasktemp);
    endNode->addTask(tasktemp);
    tasktemp->setZValue(-1000.0);
    addItem(tasktemp);
    tasktemp->updatePosition();

   tasktemp->setId(task->id());
   tasktemp->setWeight(task->weight());
}

void DiagramScene::keyPressEvent(QKeyEvent * keyEvent)
{
    if (myMode == Move){
        if (keyEvent->key() == Qt::Key_Delete)
            foreach (QGraphicsItem *item, this->selectedItems()){
                Node *node = qgraphicsitem_cast<Node *>(item);
                if (node){
                    if (node->countTask() == 0){
                        QString string = qgraphicsitem_cast<Node *>(item)->id();
                        int index = findIdNode(string);
                        idTaked[index] = false;
                        this->removeItem(item);

                        emit this->sceneChanged();
                    } else
                        QMessageBox::information(0, tr("Information"), tr("Khong the xoa Node con Task"));
                }

                Task *task = qgraphicsitem_cast<Task *>(item);
                if (task){
                    task->removeNodes(task);
                    this->removeItem(item);

                    emit this->sceneChanged();
                }
            }
    }
    QGraphicsScene::keyPressEvent(keyEvent);
}

void DiagramScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent * mouseEvent)
{
    if (myMode == Move){
        foreach (QGraphicsItem *item, this->selectedItems()){
            Task *task = qgraphicsitem_cast<Task *>(item);
            if (task && task->typeTask() == Task::TaskNormal){
                TaskDialog *taskdialog = new TaskDialog(task->id(), tr("%1").arg(task->weight()));
                if (taskdialog->exec()){
                    task->setId( taskdialog->getId() );
                    task->setWeight( taskdialog->getWeight().toInt() );

                    emit this->sceneChanged();
                }
                delete taskdialog;
            }
        }
    }
    QGraphicsScene::mouseDoubleClickEvent(mouseEvent);
}

void DiagramScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (mouseEvent->button() != Qt::LeftButton)
        return;

    int index;
    switch (myMode){
        case InsertCycle:
            index = firstId();
            if (index != -1){
                Node *node = new Node(this);
                addItem(node);
                node->setPos(mouseEvent->scenePos());
                node->setId(idNode[index]);
                idTaked[index] = true;
            }

            emit this->sceneChanged();
            break;
        case InsertTask:
            line = new QGraphicsLineItem(QLineF(mouseEvent->scenePos(), mouseEvent->scenePos()));
            line->setPen(QPen(Qt::black, 2));
            addItem(line);
            break;
        case InsertFictiveTask:
            line = new QGraphicsLineItem(QLineF(mouseEvent->scenePos(), mouseEvent->scenePos()));
            line->setPen(QPen(Qt::black, 2, Qt::DashLine));
            addItem(line);
            break;
    }
    QGraphicsScene::mousePressEvent(mouseEvent);
}

void DiagramScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if ((myMode == InsertTask || myMode == InsertFictiveTask) && line != 0){
        QLineF newLine(line->line().p1(), mouseEvent->scenePos());
        line->setLine(newLine);
    } else if (myMode == Move)
        QGraphicsScene::mouseMoveEvent(mouseEvent);
    update(sceneRect());
}

void DiagramScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (line != 0 && (myMode == InsertTask || myMode == InsertFictiveTask)){
        QList<QGraphicsItem *> startItems = items(line->line().p1());
        if (startItems.count() && startItems.first() == line)
            startItems.removeFirst();
        QList<QGraphicsItem *> endItems = items(line->line().p2());
        if (endItems.count() && endItems.first() == line)
            endItems.removeFirst();

        removeItem(line);
        delete line;

        if (startItems.count() > 0 && endItems.count() > 0 &&
            startItems.first()->type() == Node::Type &&
            endItems.first()->type() == Node::Type &&
            startItems.first() != endItems.first()) {

            Node *startItem = qgraphicsitem_cast<Node *>(startItems.first());
            Node *endItem = qgraphicsitem_cast<Node *>(endItems.first());

            Task *task;
            if (myMode == InsertTask)
                task = new Task(Task::TaskNormal, startItem, endItem);
            else
                task = new Task(Task::TaskFictive, startItem, endItem);

            startItem->addTask(task);
            endItem->addTask(task);
            task->setZValue(-1000.0);
            addItem(task);
            task->updatePosition();

            if (myMode == InsertTask){
                // goi form giao dien de nhap id va weight cua Task
                TaskDialog *taskdialog = new TaskDialog("", "");

                if (taskdialog->exec()){
                    task->setId( taskdialog->getId() );
                    task->setWeight( taskdialog->getWeight().toInt() );
                }
                delete taskdialog;
            }
        }

        emit this->sceneChanged();
    }
    line = 0;
    QGraphicsScene::mouseReleaseEvent(mouseEvent);
}

int DiagramScene::findIdNode(QString &string)
{
    for (int i = 0; i < MAX_ID_NODE; i++)
        if (idNode[i] == string) return i;
    return 0;
}

int DiagramScene::firstId()
{
    int i = 0;
    while ((i < MAX_ID_NODE) && (idTaked[i])) i++;
    if (i < MAX_ID_NODE) return i;
    return -1;
}
