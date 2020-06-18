/*
		CIS 22C, DE ANZA
		Team Project Group 3
		Jeffery Abbott
		Nicolas Chun
		Michael Ekman
		Hung Nguyen
		Huu Hau Nguyen
 */
#include <iostream>
#include <fstream>
#include <vector>
#include "Sort.h"

using namespace std;

Sort::Sort() {
	readFile("sampleData.txt", data);
	readFile("sampleDataSorted.txt", sortedData);
	readFile("sampleDataSortedReverse.txt", reverseSortedData);
}

void Sort::readFile(string fileName, vector<double> vect) {
	ifstream fileReader(fileName);
	if (fileReader.is_open()) {
		double num;
		while (fileReader >> num) {
			vect.push_back(num);
		}
	} else {
		cout << "ERROR reading file " << fileName << endl;
	}
	fileReader.close();
}

void Sort::insertionSort(vector<double> v) {
	vector<double> vect = v;
	//insertionsort
	print(vect);
}

void Sort::selectionSort(vector<double> v) {
	vector<double> vect = v;
	//selectionSortsort
	print(vect);
}

void Sort::shellSort(vector<double> v) {
	vector<double> vect = v;
	//shellsort
	print(vect);
}

vector<double> Sort::quickSort(vector<double> vect) {
	stack<int> stack;
	stack.push(0);
	stack.push(vect.size() - 1);

	while (!stack.empty()) {
		int right = stack.top();
		stack.pop();
		int left = stack.top();
		stack.pop();

		int pivot = partition(vect, left, right);
		if (pivot - 1 > left) {
			stack.push(left);
			stack.push(pivot - 1);
		}

		if (pivot + 1 < right) {
			stack.push(pivot + 1);
			stack.push(right);
		}
	}
	return vect;
}

int Sort::partition(vector<double>& v, int left, int right) {
	bool done = false;
	int leftInd;
	int rightInd;

	double pivot;
	double mid = v[(left + right) / 2];

	//find median
	if ((v[left] < v[right] && v[left] > mid) || (v[left] > v[right] && v[left] < mid)) {
		pivot = v[left];
		swap(v, left, right);
	} else if ((v[right] > v[left] && v[right] < mid) || (v[right] < v[left] && v[right] > mid)) {
		pivot = v[right];
	} else {
		pivot = mid;
		swap(v, (left + right) / 2, right);
	}

	//sort pivot point
	if (left + 1 == right) {
		if (v[left] > v[right]) {
			swap(v, left, right);
		}
		return right;
	}
	while (!done) {
		for (int leftNum = left; leftNum < right; leftNum++) {
			if (v[leftNum] > pivot) {
				leftInd = leftNum;
				break;
			}
		}
		for (int rightNum = right - 1; rightNum > leftInd; rightNum--) {
			done = true;
			if (v[rightNum] < pivot) {
				rightInd = rightNum;
				swap(v, leftInd, rightInd);
				done = false;
				break;
			}
		}
		if (leftInd == right - 1) {
			done = true;
		}
	}
	swap(v, leftInd, right);
	return leftInd;
}

void Sort::heapSort(vector<double> v) {
	vector<double> vect = v;
	//heapsort
	print(vect);
}

void Sort::swap(vector<double> vect, double ind1, double ind2) {
	double temp = vect[ind1];
	vect[ind1] = vect[ind2];
	vect[ind2] = temp;
}

void Sort::print(vector<double> vect) {
	for (int i = 0; i < vect.size(); i++) {
		if (i + 1 != vect.size()) {
			cout << vect[i] << ", ";
		} else {
			cout << vect[i] << endl;
		}
	}
}