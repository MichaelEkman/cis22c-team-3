/*
        CIS 22C, DE ANZA
        Team Project Group 3
        Jeffery Abbott
        Nicolas Chun
        Michael Ekman
        Hung Nguyen
        Huu Hau Nguyen
 */
#pragma once
#ifndef SORT_H
#define SORT_H

#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Sort {



public:

    //unsorted vectors for testing
    vector<double> data;
    vector<double> sortedData;
    vector<double> reverseSortedData;
    void heapify(vector<double>, long, long);

    Sort();

    void readFile(string filename, vector<double>& vect);
    void swapForQuickSort(vector<double>&, long, long);
    void swap(vector<double>, double, double);
    int partition(vector<double>&, int, int);
    void print(vector<double>);

    vector<double> insertionSort(vector<double>);
    vector<double> shellSort(vector<double>);
    vector<double> quickSort(vector<double>);
    vector<double> heapSort(vector<double>);
    vector<double> selectionSort(vector<double>);

    vector<double> sortUsingStdSort(vector<double>);
};
#endif