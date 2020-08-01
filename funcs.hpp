#include "node.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using vector_i = std::vector<int>;
using vector_s = std::vector<std::string>;
using queue = std::priority_queue<Node::pointer, std::vector<Node::pointer>, SmallestFirst>;

void printVector(const vector_i &vec);
void readFile(const std::string &fileName, vector_i &frequency);
void printQueue(queue que);
void fillQueue(const vector_i &frequency, queue &que);
void makeBinaryTree(queue &que);
void makeCodes(Node::pointer &node, std::string str, vector_s &codes);