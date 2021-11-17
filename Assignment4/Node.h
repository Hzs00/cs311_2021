#pragma once

#include<iostream>
#include <vector>
using namespace std;

class Node {

public:
	void addChild(Node* child);
	vector<Node*> children = vector<Node*>();
	vector<float> childrenWeights = vector<float>();
	void recursivePrint(int recursion);
	void recursiveWeight(int recursion);
	string nodeName;
};
