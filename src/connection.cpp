#include "connection.h"
#include "node.h"

Connection::Connection(std::shared_ptr<Node> from, std::shared_ptr<Node> to)
    : fromNode(from), toNode(to) {}

std::shared_ptr<Node> Connection::getFromNode() const {
    return fromNode;
}

std::shared_ptr<Node> Connection::getToNode() const {
    return toNode;
}
