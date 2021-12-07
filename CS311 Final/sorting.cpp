#include <iostream>
#include <vector>
#include "sorting.h"
using namespace std;

void sorting::bubbleSort(vector<int>& data) {

	for (int i = 0; i < data.size() - 1; i++) {
		for (int j = 0; j < data.size() - i - 1; j++) {
			if (data.at(j) > data.at(j + 1))
				swap(data.at(j), data.at(j + 1));
		}
	}
}

void sorting::insertionSort(vector<int>& data) {

	int j; 
	int temp;

	for (int i = 1; i < data.size(); i++) {

		j = i;
		temp = data[i];

		while (j > 0 && temp < data[j - 1]) {

			data[j] = data[j - 1];
			j--;
		}
		data[j] = temp;
	}
}