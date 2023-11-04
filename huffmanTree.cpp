#include "huffmanTree.h"

//constructor calculates histogram from the input string, then creates a tree from that histogram
huffmanTree::huffmanTree(string inputString)
{
	createHistogram(inputString);
	createTree();
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

	//once the tree is constructed, create codes for each leaf node, and put
	//the results in the "codes" map.
	createCodes(root, "");
	for (auto pair : codes) {
		cout << pair.first << " " << pair.second << '\n';
	}
}

void huffmanTree::createHistogram(string inputString)
{
	//for each character in the input string, iterate it on the map.
	for (int i = 0; i < inputString.size(); i++) {
		histogram[inputString[i]]++;
	}
}

//Subtask B) "convert this string into a binary string using the Huffman tree"
void huffmanTree::createCodes(node* node, string code)
{
	if (node->left) {
		createCodes(node->left, code + "0");
	}
	if (node->right) {
		createCodes(node->right, code + "1");
	}
	if (!node->left && !node->right) {
		codes[node->ch] = code;
	}
}


//uses inorder traversal to print the tree
void huffmanTree::printTree(node* node)
{
	if (node != nullptr) {
		printTree(node->left);
		if (node->ch != NULL)
			cout << "Char: " << node->ch << ", Frequency: " << node->freq << endl;
		printTree(node->right);
	}
}

node* huffmanTree::getRoot()
{
	return root;
}
