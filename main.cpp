#include "huffmanTree.h"

int main() {
	cout << "EXAMPLE 1:" << endl;
	huffmanTree example1("I AM SAM MAM.");

	//gets input string and creates a histogram
	example1.createHistogram(example1.getInputString());
	cout << "Char:Frequency Histogram" << endl;
	for (auto pair : example1.getHistogram()) {
		cout << "'" << pair.first << "' : " << pair.second << endl;
	} cout << "\n";

	//creates a tree out of histogram frequencies
	example1.createTree();
	
	//creates a code map from traversing the tree
	example1.createCodes(example1.getRoot(), "");
	cout << "Char:Binary Code Map" << endl;
	for (auto pair : example1.getCodes()) {
		cout << "'" << pair.first << "' : " << pair.second << endl;
	} cout << "\n";

	//creates a encoded binary string using the created code map
	example1.createBinaryCode(example1.getInputString());
	cout << "Encoded String: \n" << example1.getBinaryCode() << endl; cout << "\n";

	//decodes the encoded binary string using the tree
	string decodedString = example1.decodeBinaryCode(example1.getRoot(), example1.getBinaryCode());
	cout << "Decoded String: \n" << decodedString << endl;



	//EXAMPLE 2
	cout << "\nEXAMPLE 2:" << endl;
	huffmanTree example2("MMM AJAJJ KDKKDDK");
	example2.createHistogram(example2.getInputString());
	cout << "Char:Frequency Histogram" << endl;
	for (auto pair : example2.getHistogram()) {
		cout << "'" << pair.first << "' : " << pair.second << endl;
	} cout << "\n";

	//creates a tree out of histogram frequencies
	example2.createTree();

	//creates a code map from traversing the tree
	example2.createCodes(example2.getRoot(), "");
	cout << "Char:Binary Code Map" << endl;
	for (auto pair : example2.getCodes()) {
		cout << "'" << pair.first << "' : " << pair.second << endl;
	} cout << "\n";

	//creates a encoded binary string using the created code map
	example2.createBinaryCode(example2.getInputString());
	cout << "Encoded String: \n" << example2.getBinaryCode() << endl; cout << "\n";

	//decodes the encoded binary string using the tree
	string decodedString2 = example2.decodeBinaryCode(example2.getRoot(), example2.getBinaryCode());
	cout << "Decoded String: \n" << decodedString2 << endl;
}

