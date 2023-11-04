#pragma once
#include "node.h"
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class huffmanTree
{
public:
	huffmanTree(string inputString); //constructs and calls createHistogram, createTree
	node* newNode(char ch, int freq, node* left, node* right); //function that makes a new node
	void createTree(); //SUBTASK B; creates a tree from the histogram
	void createHistogram(string inputString); //SUBTASK A; calculates each char occurence in the inputString and stores it in the "histogram" map
	void createCodes(node* node, string code); //traverses the tree, creating and storing the binary codes in the "codes" map
	void printTree(node* node); //prints the tree using inorder traversal
	node* getRoot(); //returns the root node
private:
	node* root = nullptr;
	map<char, int> histogram;
	map<char, string> codes;
};

