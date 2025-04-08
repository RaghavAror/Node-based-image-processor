#include "Node.h"
#include "Connection.h"

Node::Node(const std::string& name) : name(name) {}

Node::~Node() {}

std::string Node::getName() const {
    return name;
}

void Node::addInputConnection(std::shared_ptr<Connection> connection) {
    inputConnections.push_back(connection);
}

void Node::addOutputConnection(std::shared_ptr<Connection> connection) {
    outputConnections.push_back(connection);
}

const std::vector<std::shared_ptr<Connection>>& Node::getInputConnections() const {
    return inputConnections;
}

const std::vector<std::shared_ptr<Connection>>& Node::getOutputConnections() const {
    return outputConnections;
}
