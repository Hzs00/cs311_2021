#include <iostream>
#include<vector>
#include "Node.h"
using namespace std;

constexpr int levelSize = 3;
string gen_random(const int len);

int main() {

	Node* main = new Node();
	vector<Node*> currentNodes = vector<Node*>();
	vector<Node*> previousNodes = vector<Node*>();
	int levels[levelSize] = { 4,3,2 };

	main->nodeName = "mainNode";
	currentNodes.push_back(main);

	for (int i = 0; i < levelSize ; i++) {
		
		previousNodes = currentNodes;
		currentNodes.resize(levels[i]);

		for (int j = 0; j < levels[i]; j++) {
			
			Node* nodeAdd = new Node();
			nodeAdd->nodeName = gen_random(4);
			currentNodes[j] = nodeAdd;
		}
		for (int j = 0; j < previousNodes.size(); j++) {
			for (int k = 0; k < currentNodes.size(); k++) {

				previousNodes[j]->addChild(currentNodes[k]);

			}
		}
	}
	main->recursivePrint(0);
	main->recursiveWeight(0);
	return 0;
}

string gen_random(const int len) {
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";
	string tmp_s;
	tmp_s.reserve(len);

	for (int i = 0; i < len; ++i) {
		tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
	}

	return tmp_s;
}
