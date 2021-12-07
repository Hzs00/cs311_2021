#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "sorting.h"
using namespace std;

int main() {
	
	vector<int> data;
	void csvCreate1(vector<int> & data);
	void csvCreate2(vector<int> & data);

	// creating class object to run bubbleSort method
	sorting bubble = sorting();

	// creating class object to run insertionSort method
	sorting insertion = sorting();

	// creating an array of 1000 numbers
	for (int i = 0; i < 1000; i++) {

		data.push_back(i + 1);
	}

	// data is shuffled randomly
	for (int i = 0; i < 1000; i++) {

		random_shuffle(data.begin(), data.end());
	}

	// data is sorted
	bubble.bubbleSort(data);
	// call to csv with bubbleSort data
	csvCreate1(data);

	// data is shuffled again randomly for next sorting algorithm
	for (int i = 0; i < 1000; i++) {

		random_shuffle(data.begin(), data.end());
	}

	// data is sorted again with insertionSort
	insertion.insertionSort(data);

	// call to different csv with insertionSort data
	csvCreate2(data);
}

void csvCreate1(vector<int>& data) {
	
	ofstream sortedData;

	sortedData.open("sortedData.csv");

	sortedData << "bubbleSort numbers" << endl;
	
	// loops through data to put in sortedData.csv
	for (int i = 0; i < data.size(); i++) {

		sortedData  << data[i] << "," << endl;
	}
}

void csvCreate2(vector<int>& data) {

	ofstream sortedData;

	sortedData.open("sortedData2.csv");

	sortedData << "insertionSort numbers" << endl;

	// loops through data to put in sortedData.csv
	for (int i = 0; i < data.size(); i++) {

		sortedData << data[i] << "," << endl;
	}
}