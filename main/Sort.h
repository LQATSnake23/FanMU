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
#include "DataGenerator.h"
#include <string>
#include <fstream>
using namespace std;

// method used to measure algorithm running time is referenced at 
// https://www.geeksforgeeks.org/measure-execution-time-function-cpp/
#include <chrono>
using namespace std::chrono;

// Data structure for command line arguments
struct Command {
	bool exist = true; // Check if Command is usable
	int type = 0; // Type of command (1-5)
	string mode; // Algorithm: "-a", Comparison: "-c"
	string algorithm; // Name of algorithm 
	string algorithm2; // Name of 2nd algorithm (if using comparison mode)
	string input; // Input method (.txt or a number)
	int inputSize = 0; // Input size n
	string order; // Data Order (-rand, -nsorted, -sorted, -rev)
	string parameter; // Output parameters (-time, -comp, -both)
};

// Read array and input size from an input file
int* readFile(string filename, int& n);

// Write array and input size to output file
void writeFile(string filename, int* arr, int n);

// Sort an array using a algorithm, also calculate running time and comparisons
void sortData(string algorithm, int* arr, int n, double& run_time, double& comp);

// Remove '-' and upper case Algorithm name
string nameAlgorithm(string cmd);