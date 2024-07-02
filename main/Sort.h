#pragma once

#include "BubbleSort.h"
#include "CountingSort.h"
#include "FlashSort.h"
#include "HeapSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "RadixSort.h"
#include "SelectionSort.h"
#include "ShakerSort.h"
#include "ShellSort.h"
#include <chrono>
#include <string>
#include <fstream>
using namespace std;
using namespace std::chrono;

struct Command {
	bool exist = true;
	int type = 0;
	string mode;
	string algorithm;
	string algorithm2;
	string input;
	int inputSize = 0;
	string order;
	string parameter;
};

int* readFile(string filename, int& n);
void writeFile(string filename, int* arr, int n);
void sortData(string algorithm, int* arr, int n, double& run_time, double& comp);
string nameAlgorithm(string cmd);