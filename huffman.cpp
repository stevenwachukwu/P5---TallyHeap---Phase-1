#include "huffman.h"

void huffman::doTally(string text) {
	for (char ch : text) {
		tally[ch]++;
	}
}; //the do tally function is used to count all the char values from p5message.txt file's string

void huffman::printTally(string text) {
	string unique;
	for (char ch : text) {
		if (unique.find(ch)!=string::npos) {
			continue;
		} //if the same letter appears then the counter would move forward
		else {
			unique += ch;
		} //this else statement is utilized to count the unique char values from the string in the p5message.txt file
	}
	for (char ch : unique) {
		cout << "\nThe tally of " << ch << " is " << tally[ch] << endl; //the printout of the char values for the console output
	}
} //the print tally function for phase 1 and beyond

void huffman::compress() {
	string content; //string from p5message.txt
	getline(fileinput,content); //this is used to get the whole string from p5message.txt
	doTally(content); //calling the do tally function for the string
	printTally(content);//calling the print function for the string
	*rootHuffTree = heapify(content, rootHuffTree);
	unordered_map<char, string> huffmanCode;
	//encode(rootHuffTree, "", huffmanCode);
	ofstream p5_HCO("HuffmanCodesAre.txt");
	p5_HCO << "Huffman Codes are: \n" << '\n';
	for (auto pair : huffmanCode) {
		cout << pair.first << "" << pair.second << '\n';
		p5_HCO << pair.first << " " << pair.second << '\n';
	}
	cout << "\nOriginal string was:\n" << content << '\n'; //this message will print out the original string before the bye message

	string str = "";
	for (char ch : content) {
		str += huffmanCode[ch];
	}
	ofstream ESI("EncodedStringIs.txt");
	ESI << str;
	//cout << "\nEncoded string is :\n" << str << '\n';

	//int index = -1;
	//while (index < (int)str.size() - 2) {
	//	decode(rootHuffTree, index, str);
	//}
}

/*void huffman::encode(Node* root, string str, unordered_map<char, string>& huffmanCode)
{
	if (root == nullptr) {
		return;
	}
	if (!root->left && !root->right) {
		huffmanCode[root->ch] = str;
	}
	encode(root->left, str + "0", huffmanCode);
	encode(root->right, str + "1", huffmanCode);
}*/

/*void huffman::decode(Node* root, int& index, string str) {
	if (root == nullptr) {
		return;
	}
	if (!root->left && !root->right) {
		cout << root->ch;
		return;
	}
	index++;
	if (str[index] == '0') {
		decode(root->left, index, str);
	}
	else {
		decode(root->right, index, str);
	}
}*/
