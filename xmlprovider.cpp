#include <QTextStream>
#include <QDomDocument>
#include <QFile>
#include <QMessageBox>
#include <QQueue>
#include "xmlprovider.h"

XMLProvider::XMLProvider(DiagramScene *scene, const QString &fileName)
{
    _scene = scene;
    _fileName = fileName;
    this->sceneToGraph();
}

bool XMLProvider::readXML()
{
    if (_fileName.isEmpty()) return false;

    QFile file(_fileName);
    /*if (!file.open(QFile::ReadOnly | QFile::Text)) {
        return false;
    }*/

    // xoa du lieu cu, chuan bi de khi du lieu moi vao
    this->clearData();

    QString errorStr;
    int errorLine;
    int errorColumn;

    // Load file XML vao QDomDocument
    QDomDocument doc;
    if (!doc.setContent(&file, true, &errorStr, &errorLine, &errorColumn)){
        QMessageBox::warning(0, QObject::tr("Read XML"),
                             QObject::tr("Parse error at line %1, column %2:\n%3").arg(errorLine).arg(errorColumn).arg(errorStr),
                             QMessageBox::Ok);
        return false;
    }

    // Duyet qua du lieu XML de tao ra _node va _edge
    QDomElement root = doc.documentElement();
    if (root.tagName() != "graph")
        return false;

    QDomElement node = root.firstChildElement();
    while (!node.isNull()){
        if (node.tagName() == "node"){
            QString id = node.attribute("id","0");
            QString x = node.attribute("x","0");
            QString y = node.attribute("y","0");

            Node *nodetemp = new Node(_scene);
            nodetemp->setPos(x.toFloat(), y.toFloat());
            nodetemp->setId(id);

            _node.append(nodetemp);
        } else if (node.tagName() == "edge"){
            QString id = node.attribute("id","");
            QString weight = node.attribute("weight","0");
            QString start = node.attribute("start","0");
            QString end = node.attribute("end","0");

            Node *startNode = _node.at(start.toInt());
            Node *endNode = _node.at(end.toInt());

            Task *tasktemp;
            if (id == "")
                tasktemp = new Task(Task::TaskFictive, startNode, endNode);
            else
                tasktemp = new Task(Task::TaskNormal, startNode, endNode);

            tasktemp->setWeight(weight.toInt());
            tasktemp->setId(id);

            _edge.append(tasktemp);
        }
        node = node.nextSiblingElement();
    }

    // Sau khi ghi du lieu vao _node va _edge, bat dau khoi tao lai scene
    this->graphToScene();

    return true;
}

bool XMLProvider::writeXML()
{
    if (_fileName.isEmpty()) return false;

    QFile file(_fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        return false;
    }

    const int Indent = 4;
    QDomDocument doc;
    QDomElement root = doc.createElement("graph");
    root.setAttribute("id","G");
    root.setAttribute("edgedefault","directed");
    doc.appendChild(root);

    //cout << "So node : " << _node.length();
    for (int i = 0; i < _node.length(); i++)
    {
        Node *nodetemp = _node.at(i);
        QDomElement node = doc.createElement("node");
        node.setAttribute("id", i);
        node.setAttribute("x", nodetemp->x());
        node.setAttribute("y", nodetemp->y());
        root.appendChild(node);
    }

    //cout << "So edge: " << _edge.length();
    for (int i = 0; i < _edge.length(); i++)
    {
        Task *tasktemp = _edge.at(i);
        QDomElement edge = doc.createElement("edge");
        edge.setAttribute("id", tasktemp->id());
        edge.setAttribute("weight", tasktemp->weight());
        int start = _node.indexOf(tasktemp->start());
        edge.setAttribute("start", start);
        int end = _node.indexOf(tasktemp->end());
        edge.setAttribute("end", end);
        root.appendChild(edge);
    }

    QTextStream out(&file);
    //QDomNode xmlNode = doc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"ISO-8859-1\"");
    //doc.insertBefore(xmlNode, doc.firstChild());
    doc.save(out, Indent);

    return true;
}

void XMLProvider::sceneToGraph()
{
    QList<Node *> _nodetemp;
    QList<Task *> _tasktemp;

    foreach (QGraphicsItem *item, _scene->items()){
        Node *node = qgraphicsitem_cast<Node *>(item);
        if (node){
            _nodetemp.append(node);
        }
        Task *task = qgraphicsitem_cast<Task *>(item);
        if (task){
            _tasktemp.append(task);
        }
    }

    if (_nodetemp.length() > 0)
    {
        int len = _nodetemp.length();
        int adjacent[len * len];

        // Khoi tao ma tran lien ke bang 0
        for (int i = 0; i < len * len; i++)
            adjacent[i] = 0;

        // Tao ra ma tran lien ke
        for (int i = 0; i < _tasktemp.length(); i++)
        {
            Task *task = _tasktemp.at(i);
            int i = _nodetemp.indexOf(task->start());
            int j = _nodetemp.indexOf(task->end());

            adjacent[i * len + j] = 1;
            adjacent[j * len + i] = -1;
        }

        /*for (int i = 0; i < _node.length(); i++)
        {
            Node *node = _node.at(i);
            cout << "Dinh " << i << " : " << node->x() << " " << node->y() << "\n";
        }*/

        /*for (int i = 0; i < len; i++){
            for (int j = 0; j < len; j++)
                cout << adjacent[i * len + j] << " ";
            cout << "\n";
        }*/

        // Dua tren ma tran lien ke tim ra duoc node goc
        int root = nodeRoot(adjacent, len);

        // Dua tren node goc sap xep lai thu tu mang node va edge
        QQueue<int> queue;
        QList<int> nodeChecked;
        queue.enqueue(root);

        while (!queue.empty()){
            int i = queue.dequeue();
            nodeChecked.append(i);
            //cout << " " << i;

            _node.append(_nodetemp.at(i));

            for (int j = 0; j < len; j++)
                if ((adjacent[i * len + j] == 1) &&
                    ((nodeChecked.indexOf(j) == -1) && (queue.indexOf(j) == -1)))
                    queue.enqueue(j);
        }

        for (int i=0; i < _nodetemp.length(); i++)
            if (_node.indexOf(_nodetemp.at(i)) == -1)
                _node.append(_nodetemp.at(i));
        /*if (!_nodetemp.empty())
            for (int i = 0; i < _nodetemp.length(); i++){
                _node.append(_nodetemp.at(i));
            }*/

        for (int i = 0; i < len; i++){
            Node *node = _node.at(i);
            for (int j = 0; j < _tasktemp.length(); j++){
                Task *task = _tasktemp.at(j);
                if (node == task->start())
                    _edge.append(task);
            }
        }
    }

    _nodetemp.clear();
    _tasktemp.clear();
}

void XMLProvider::graphToScene()
{
    _scene->reset();
    for (int i = 0; i < _node.length(); i++)
        _scene->setNode(_node.at(i));
    for (int i=0; i < _edge.length(); i++)
        _scene->setTask(_edge.at(i));
}

int XMLProvider::nodeRoot(int adjacent[], int len)
{
    int i = 0;
    while (i < len)
    {
        int j = 0;
        bool check = true;
        while (j < len){
            if (adjacent[i * len + j] == -1) check = false;
            j++;
        }
        if (check) return i;
        i++;
    }
    return -1;
}

void XMLProvider::clearData()
{
    _node.clear();
    _edge.clear();
}
