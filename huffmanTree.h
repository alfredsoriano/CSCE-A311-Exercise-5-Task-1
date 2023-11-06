#pragma once
#include "node.h"
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class huffmanTree
{
public:
	huffmanTree(string inputString); //constructs and calls createHistogram, createTree
	node* newNode(char ch, int freq, node* left, node* right); //function that makes a new node
	void createTree(); //SUBTASK B; creates a tree from the histogram
	void createHistogram(string inputString); //SUBTASK A; calculates each char occurence in the inputString and stores it in the "histogram" map
	map<char, string> createCodes(node* node, string code); //traverses the tree, creating and storing the binary codes in the "codes" map. NOTE: 2ND PARAMETER SHOULD BE "";
	string createBinaryCode(string inputString); //takes the inputString and converts it into a binary string using the codes map
	string decodeBinaryCode(node* root, string binaryCode); //SUBTASK C; takes in the binaryCode generated from createBinaryCode + the root node, and returns the decoded string
	string getInputString(); //returns the input string
	node* getRoot(); //returns the root node
	string getBinaryCode(); //returns the binary code
	map<char, int> getHistogram(); //returns the histogram map
	map<char, string> getCodes(); //returns the codes map
private:
	string inputString;
	node* root = nullptr;
	string binaryCode = "";
	map<char, int> histogram;
	map<char, string> codes;
};

