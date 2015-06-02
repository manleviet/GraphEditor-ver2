#ifndef NODEXML_H
#define NODEXML_H

#include <QString>

class NodeXML
{
public:
    NodeXML(int x, int y);

    int x(){return _x;}
    int y(){return _y;}

private:
    int _x;
    int _y;
};

#endif // NODEXML_H
