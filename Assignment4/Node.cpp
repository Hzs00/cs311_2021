#include "Node.h"

void Node::addChild(Node* child) {

	float random = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	children.push_back(child);
	childrenWeights.push_back(random);
}

void Node::recursivePrint(int recursion) {

	for (int i = 0; i < recursion; i++) {
		
		cout << "\t";
	}
	cout << this->nodeName << " is connected to ";
	cout << "\n";

	for (int i = 0; i < children.size(); i++) {
		
		children[i]->recursivePrint(recursion + 1);
	}
}

void Node::recursiveWeight(int recursion) {

	for (int i = 0; i < recursion; i++) {

		cout << "\t";
	}
	cout << this->nodeName << " is connected to ";
	cout << "\n";

	for (int i = 0; i < children.size(); i++) {

		children[i]->recursiveWeight(recursion + 1);

		for (int i = 0; i < recursion; i++) {

			cout << "\t";
		}

		cout << "with weight " << childrenWeights[i];
		cout << "\n";
	}
}