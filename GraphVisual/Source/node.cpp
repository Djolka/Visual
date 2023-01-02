#include "node.h"
#include <utility>
#include <QPointF>
#include <cmath>

Node::Node(){
    m_inDeg=0;
    m_outDeg=0;
    m_deg=0;
    m_name="";
    m_position=QPointF(0,0);
}

Node::Node(const Node *other) {
    m_inDeg = other->inDeg();
    m_outDeg = other->outDeg();
    m_deg = other->m_deg;
    m_name = other->m_name;
    m_position = other->m_position;
}

Node::Node(std::string name){
    m_inDeg=0;
    m_outDeg=0;
    m_deg=0;
    m_name=name;
    m_position=QPointF(0,0);
}

Node::Node(std::string name, QPointF position){
    m_inDeg=0;
    m_outDeg=0;
    m_deg=0;
    m_name=name;
    m_position=position;
}

Node::~Node() {
    for(auto node : m_neighbours) {
        delete node;
    }
}

unsigned Node::inDeg() const{
    return m_inDeg;
}

unsigned Node::outDeg() const{
    return m_outDeg;
}

unsigned Node::deg() const{
    return m_deg;
}

QPointF Node::position() const{
    return m_position;
}

std::string Node::name() const{
    return m_name;
}

void Node::setPosition(const QPointF &position){
    m_position=position;
}

bool Node::operator==(const Node &second) const{
    return m_name==second.m_name;
}

bool Node::operator<(const Node &second) const{
    int res = m_name.compare(second.m_name);

    if (res < 0)
        return true;
    else
        return false;
}

bool Node::removeNeighbour(Node *n){
    QList<Node*>::iterator it = std::find(m_neighbours.begin(), m_neighbours.end(), n);
    if(it != m_neighbours.end()){
        m_neighbours.erase(it);
        return true;
    }
    return false;
}

QList<Node*> Node::neighbours(){
    return m_neighbours;
}

bool Node::addNeighbour(Node* n){
    auto it = std::find(m_neighbours.begin(), m_neighbours.end(), n);
    if(it == m_neighbours.end()){
        m_neighbours.append(n);
        return true;
    }
    return false;

}

void Node::incInDeg(){
    m_inDeg++;
}

void Node::incOutDeg(){
    m_outDeg++;
}

void Node::decInDeg(){
    if(m_inDeg>0){
        m_inDeg--;
    }else{
        std::cerr<<"There are no edges to be deleted"<<std::endl;
    }
}

void Node::decOutDeg(){
    if(m_outDeg>0){
        m_outDeg--;
    }else{
        std::cerr<<"There are no edges to be deleted"<<std::endl;
    }
}

void Node::incDeg(){
    m_deg++;
}

void Node::decDeg(){
    if(m_deg>0){
        m_deg--;
    }else{
        std::cerr<<"There are no edges to be deleted"<<std::endl;
    }
}

void Node::setName(const std::string name){
    m_name=name;
}

std::ostream &operator<< (std::ostream &os, const Node &n){
    os<< n.name() << " " << n.inDeg() << " " << n.outDeg() << " " << n.deg() << std::endl;
    return os;
}

