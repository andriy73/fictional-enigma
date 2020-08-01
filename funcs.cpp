#include "funcs.hpp"

void printVector(const vector_i &vec)
{
    std::cout << '\n';
    int index = 0;
    for (auto it : vec)
    {
        if (it)
            if (index == 10)
                std::cout << "\\n"
                          << ':' << it << ' ';
            else
                std::cout << static_cast<char>(index) << ':' << it << ' ';
        ++index;
    }
    std::cout << '\n';
}
void readFile(const std::string &fileName, vector_i &frequency)
{
    std::ifstream ifs(fileName, std::ifstream::binary);
    if (!ifs)
    {
        std::cerr << "Unable to open" << __PRETTY_FUNCTION__ << fileName << strerror(errno);
    }
    while (true)
    {
        char ch;
        ifs.read(&ch, 1);
        if (ifs.eof())
            break;
        frequency[static_cast<uchar>(ch)]++;
    }
}
void fillQueue(const vector_i &frequency, queue &que)
{
    int index = 0;
    for (auto it : frequency)
    {
        if (it)
            que.push(std::make_shared<Node>(index, it));
        ++index;
    }
}
void printQueue(queue que)
{
    std::cout << '\n';
    while (!que.empty())
    {
        std::cout << *que.top() << ' ';
        que.pop();
    }
    std::cout << '\n';
}
void makeBinaryTree(queue &que)
{
    while (que.size() > 1)
    {
        Node::pointer x = que.top();
        que.pop();
        Node::pointer y = que.top();
        que.pop();
        std::string name = x->getName() + y->getName();
        Node::pointer z = std::make_shared<Node>(name, x->getFrequency() + y->getFrequency());
        x->parent = z;
        y->parent = z;
        z->left = x;
        z->right = y;
        que.push(z);
        //printQueue(que);
    }
}

void makeCodes(Node::pointer &node, std::string str, vector_s &codes)
{
    if (node->left != nullptr)
    {
        makeCodes(node->left, str + "0", codes);
    }
    if (node->right != nullptr)
    {
        makeCodes(node->right, str + "1", codes);
    }
    if (node->left == nullptr && node->right == nullptr)
    {
        node->code(str);
        codes[node->getByte()] = str;
        std::cout << "leaf   " << *node << " code " << node->code() << '\n';
    }
}