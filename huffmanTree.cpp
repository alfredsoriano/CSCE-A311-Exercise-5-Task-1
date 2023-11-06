#include "huffmanTree.h"

//constructor makes a histogram of char occurences in inputString, then makes the tree using that histogram,
//then creates the code map using the created tree, then creates the binary code using that code map, 
//then decodes the binary code using the tree.
huffmanTree::huffmanTree(string inputString)
{
	this->inputString = inputString;
}

node* huffmanTree::newNode(char ch, int freq, node* left, node* right)
{
	node* temp = new node();
	temp->ch = ch;
	temp->freq = freq;
	temp->left = left;
	temp->right = right;
	return temp;
}

//Subtask A) "create a huffman binary tree for a given string"
void huffmanTree::createTree()
{
	vector<node*> nodes;

	//for each char:freq pair in the histogram map, add it to a vector of nodes
	//to use later in building the tree. Also sorts the vector.
	for (auto pair : histogram) {
		nodes.push_back(new node(pair.first, pair.second));
	}

	//sorts the vector nodes according to node freq. in ascending order
	sort(nodes.begin(), nodes.end(), [](node* low, node* high) {
		return low->freq < high->freq;
		});
		
	while (nodes.size() != 1) {
		node* left = nodes.front();
		nodes.erase(nodes.begin());
		node* right = nodes.front();
		nodes.erase(nodes.begin());

		nodes.push_back(newNode('\0', left->freq + right->freq, left, right));
	}
	root = nodes.front();
}

void huffmanTree::createHistogram(string inputString)
{
	//for each character in the input string, iterate it on the map.
	for (int i = 0; i < inputString.size(); i++) {
		histogram[inputString[i]]++;
	}
}

//Subtask B) "convert this string into a binary string using the Huffman tree"
map<char, string> huffmanTree::createCodes(node* node, string code)
{
	if (node->left) 
		createCodes(node->left, code + "0");

	if (node->right) 
		createCodes(node->right, code + "1");

	if (!node->left && !node->right)
		codes[node->ch] = code;

	return codes;
}

string huffmanTree::createBinaryCode(string inputString)
{
	//for each character in the input string...
	for (char ch : inputString) {
		for (auto pair : codes) {
			if (ch == pair.first)
				binaryCode += pair.second;
		}
	}

	return binaryCode;
}

string huffmanTree::decodeBinaryCode(node* root, string binaryCode)
{
	string decodedString = "";
	node* curr = root;

	//for each character in binaryCode...
	for (char ch : binaryCode) {
		if (ch == '0')
			curr = curr->left;
		else
			curr = curr->right;

		//if we reached a leaf node...
		if ((curr->left == nullptr) and (curr->right == nullptr)) {
			decodedString += curr->ch;
			curr = root;
		}
	}

	return decodedString;
}

string huffmanTree::getInputString()
{
	return inputString;
}

node* huffmanTree::getRoot()
{
	return root;
}

string huffmanTree::getBinaryCode()
{
	return binaryCode;
}

map<char, int> huffmanTree::getHistogram()
{
	return histogram;
}

map<char, string> huffmanTree::getCodes()
{
	return codes;
}
