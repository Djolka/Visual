#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <utility>
#include <QPointF>
#include <QList>

class Node{

public:
    Node();
    explicit Node(std::string name);
    explicit Node(std::string name, QPointF position);

    //getters
    unsigned inDeg() const;
    unsigned outDeg() const;
    unsigned deg() const;
    QPointF position() const;
    std::string name() const;

    //setters
    void setPosition(const QPointF &position);

    //overriding operator == so we can compare the nodes by their name
    bool operator==(const Node &second) const;
    bool operator<(const Node &second) const;

    QList<Node*> neighbours();
    void addNeighbour(Node* n);
    friend std::ostream &operator<< (std::ostream &os, const Node &n);

private:

    unsigned m_inDeg;
    unsigned m_outDeg;
    unsigned m_deg;
    std::string m_name;
    QPointF m_position;

    QList<Node*> m_neighbours;

    void incInDeg();
    void incOutDeg();
    void decInDeg();
    void decOutDeg();
    void incDeg();
    void decDeg();
    void setName(std::string name);

    friend class Graph;
};


#endif // NODE_H
