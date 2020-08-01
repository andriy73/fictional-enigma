#include <fstream>
#include <memory>
#include <string.h>

using uchar = unsigned char;

struct Node
{
    using pointer = std::shared_ptr<Node>;
    pointer left{nullptr};
    pointer right{nullptr};
    pointer parent{nullptr};

    Node() = default;
    Node(char c, int f) : uch(c), frequency(f) {}
    Node(std::string n, int f) : name(n), frequency(f) {}
    ~Node() = default;

    uchar getByte() const;
    std::string code() const;
    void code(const std::string &c);
    const std::string getName() const;
    const int getFrequency() const;
    const bool operator<(const Node &other) const;
    friend std::ostream &operator<<(std::ostream &os, const Node &node);

private:
    uchar uch{0};
    int frequency{0};
    std::string name{""};
    std::string code_string{""};
};

struct SmallestFirst
{
    const bool operator()(const Node::pointer &lhs, const Node::pointer &rhs) const;
};

std::ostream &operator<<(std::ostream &os, const Node &node);