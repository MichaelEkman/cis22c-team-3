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

void Sort::quickSort(vector<double> v) {
	vector<double> vect = v;
	//quicksort
	print(vect);
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