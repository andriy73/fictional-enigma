#include "funcs.hpp"

int main()
{
    std::string fileName{"SampleTextFile.txt"};

    vector_i frequency(0x100, 0);

    readFile(fileName, frequency);

    printVector(frequency);

    queue que;

    fillQueue(frequency, que);

    printQueue(que);

    makeBinaryTree(que);

    printQueue(que);

    vector_s codes(0x100, "");

    Node::pointer root = que.top();
    makeCodes(root, "", codes);

    return 0;
}