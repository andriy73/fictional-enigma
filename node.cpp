#include "node.hpp"

const bool Node::operator<(const Node &other) const
{
    return frequency < other.frequency;
}
std::ostream &operator<<(std::ostream &os, const Node &node)
{
    if (node.uch == 10)
        return os << "\\n"
                  << ':' << node.frequency << ' ';
    return os << node.getName() << ':' << node.frequency << ' ';
}
uchar Node::getByte() const
{
    return uch;
}

std::string Node::code() const
{
    return code_string;
}
void Node::code(const std::string &c)
{
    code_string = c;
}
const int Node::getFrequency() const
{
    return frequency;
}
const bool SmallestFirst::operator()(const Node::pointer &lhs, const Node::pointer &rhs) const
{
    return lhs->getFrequency() > rhs->getFrequency();
}
const std::string Node::getName() const
{
    if (uch == 0)
        return name;
    if (uch == 10)
        return "\\n";
    return std::string(1, static_cast<char>(uch));
}