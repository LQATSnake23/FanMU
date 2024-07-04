#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

template <class T>
void HoanVi(T& a, T& b);

// Generate a randomized array
void GenerateRandomData(int a[], int n);

// Generate an array with ascending order
void GenerateSortedData(int a[], int n);

// Generate an array with descending order
void GenerateReverseData(int a[], int n);

// Generate a nearly sorted array (in ascending order)
void GenerateNearlySortedData(int a[], int n);

void GenerateData(int a[], int n, int dataType);

