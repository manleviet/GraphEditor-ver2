#ifndef XMLPROVIDER_H
#define XMLPROVIDER_H

#include "diagramscene.h"

class XMLProvider
{
public:
    XMLProvider(DiagramScene *scene, const QString &fileName);

    void setScene(DiagramScene *scene){_scene = scene;}
    void setFileName(const QString &fileName){_fileName = fileName;}

    bool readXML();
    bool writeXML();

private:
    void sceneToGraph();
    void graphToScene();
    int nodeRoot(int adjacent[], int len);
    void clearData();

    DiagramScene *_scene;
    QString _fileName;

    QList<Node *> _node;
    QList<Task *> _edge;
};

#endif // XMLPROVIDER_H
