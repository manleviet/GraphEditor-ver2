#ifndef EDGEXML_H
#define EDGEXML_H

#include <QString>

class EdgeXML
{
public:
    EdgeXML(QString id, int weight, int start, int end);

    QString id(){return _id;}
    int weight(){return _weight;}
    int start(){return _start;}
    int end(){return _end;}

private:
    QString _id;
    int _weight;
    int _start;
    int _end;
};

#endif // EDGEXML_H
