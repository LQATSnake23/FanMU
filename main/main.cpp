#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <string.h>
#include "DataGenerator.h"
#include "Sort.h"
#include <chrono>
#include <iomanip>
using namespace std::chrono;
using namespace std;

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

int* readFile(string filename, int& n) {
	n = 0;
	ifstream infile(filename);
	if (!infile.is_open()) return NULL;

	infile >> n;
	int* a = new int[n] {0};
	int i = 0;
	while (!infile.eof()) {
		infile >> a[i];
		i++;
		if (i >= n) break;
	}
	infile.close();
	return a;
}

void writeFile(string filename, int* arr, int n) {
	ofstream outfile(filename);
	if (!outfile.is_open()) return;

	outfile << n << endl;
	for (int i = 0; i < n - 1; i++) {
		outfile << arr[i] << " ";
	}
	outfile << arr[n - 1];
	outfile.close();
}

void sortData(string algorithm, int* arr, int n, int& run_time, double &comp) {
	comp = 0;
	if (algorithm == "selection-sort") {
		auto start = high_resolution_clock::now();
		SelectionSort(arr, n, comp);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<milliseconds>(stop - start);
		run_time = duration.count();
		return;
	}
	if (algorithm == "insertion-sort") {
		auto start = high_resolution_clock::now();
		InsertionSort(arr, n, comp);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<milliseconds>(stop - start);
		run_time = duration.count();
		return;
	}
	if (algorithm == "bubble-sort") {
		auto start = high_resolution_clock::now();
		BubbleSort(arr, n, comp);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<milliseconds>(stop - start);
		run_time = duration.count();
		return;
	}
	if (algorithm == "Shaker-sort") {
		auto start = high_resolution_clock::now();
		ShakerSort(arr, n, comp);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<milliseconds>(stop - start);
		run_time = duration.count();
		return;
	}
	if (algorithm == "shell-sort") {
		auto start = high_resolution_clock::now();
		ShellSort(arr, n, comp);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<milliseconds>(stop - start);
		run_time = duration.count();
		return;
	}
	if (algorithm == "heap-sort") {
		auto start = high_resolution_clock::now();
		HeapSort(arr, n, comp);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<milliseconds>(stop - start);
		run_time = duration.count();
		return;
	}
	if (algorithm == "merge-sort") {
		auto start = high_resolution_clock::now();
		MergeSort(arr, 0, n - 1, comp);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<milliseconds>(stop - start);
		run_time = duration.count();
		return;
	}
	if (algorithm == "quick-sort") {
		auto start = high_resolution_clock::now();
		QuickSort(arr, 0, n - 1, comp);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<milliseconds>(stop - start);
		run_time = duration.count();
		return;
	}
	if (algorithm == "counting-sort") {
		auto start = high_resolution_clock::now();
		CountingSort(arr, n, comp);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<milliseconds>(stop - start);
		run_time = duration.count();
		return;
	}
	if (algorithm == "radix-sort") {
		auto start = high_resolution_clock::now();
		RadixSort(arr, n, comp);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<milliseconds>(stop - start);
		run_time = duration.count();
		return;
	}
	if (algorithm == "flash-sort") {
		auto start = high_resolution_clock::now();
		FlashSort(arr, n, comp);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<milliseconds>(stop - start);
		run_time = duration.count();
		return;
	}
}

string nameAlgorithm(string cmd) {
	string name = cmd;
	name[0] -= 32;
	for (int i = 1; i < name.length() - 1; i++) {
		if (name[i] == '-') {
			name[i] = ' ';
			name[i + 1] -= 32;
		}
	}
	return name;
}

int main(int argc, char* argv[])
{
	Command cmdLine;
	int* array = NULL, runtime = 0, runtime2 = 0, order;
	double comps = 0, comps2 = 0;
	
	cmdLine.mode = argv[1];
	if (cmdLine.mode != "-a" && cmdLine.mode != "-c") {
		cmdLine.exist = false;
	}

	if (cmdLine.exist && cmdLine.mode == "-a") {
		cmdLine.algorithm.assign(argv[2], strlen(argv[2]));

		cmdLine.input.assign(argv[3], strlen(argv[3]));
		bool isFile = false;
		for (int i = 0; i < cmdLine.input.length(); i++) {
			if (cmdLine.input[i] == '.') {
				isFile = true;
				break;
			}
		}
		if (isFile) {
			array = readFile(cmdLine.input, cmdLine.inputSize);
			cmdLine.parameter = argv[4];
			cmdLine.type = 1;
		}
		else {
			cmdLine.inputSize = stoi(cmdLine.input);
		}
		cmdLine.order = argv[4];
		if (cmdLine.order == "-time" || cmdLine.order == "-comp" || cmdLine.order == "-both") {
			cmdLine.parameter = cmdLine.order;
			cmdLine.order = "";
			if (cmdLine.type != 1) {
				cmdLine.type = 3;
			}
		}
		else {
			cmdLine.parameter = argv[5];
			cmdLine.type = 2;
		}
	}
	else if (cmdLine.exist && cmdLine.mode == "-c") {
		cmdLine.algorithm.assign(argv[2], strlen(argv[2]));
		cmdLine.algorithm2.assign(argv[3], strlen(argv[3]));

		cmdLine.input.assign(argv[4], strlen(argv[4]));
		bool isFile = false;
		for (int i = 0; i < cmdLine.input.length(); i++) {
			if (cmdLine.input[i] == '.') {
				isFile = true;
				break;
			}
		}
		if (isFile) {
			array = readFile(cmdLine.input, cmdLine.inputSize);
			cmdLine.type = 4;
		}
		else {
			cmdLine.inputSize = stoi(cmdLine.input);
			cmdLine.order = argv[5];
			cmdLine.type = 5;
		}
	}
	else {
		cout << "Invalid input!" << endl;
		return 0;
	}

	if (cmdLine.mode == "-a") {
		cout << "ALGORITHM MODE" << endl;
		cout << "Algorithm: " << nameAlgorithm(cmdLine.algorithm) << endl;
		if (cmdLine.type == 1) {
			cout << "Input file: " << cmdLine.input << endl;
		}
		cout << "Input size: " << cmdLine.inputSize << endl;
	}

	if (cmdLine.mode == "-c") {
		cout << "COMPARISON MODE" << endl;
		cout << "Algorithm: " << nameAlgorithm(cmdLine.algorithm) << " | " << nameAlgorithm(cmdLine.algorithm2) << endl;
		if (cmdLine.type == 1) {
			cout << "Input file: " << cmdLine.input << endl;
		}
		cout << "Input size: " << cmdLine.inputSize << endl;
	}
	
	cout << endl;
	switch (cmdLine.type) {
	case 1:
		sortData(cmdLine.algorithm, array, cmdLine.inputSize, runtime, comps);
		cout << "---------------------------------------" << endl;
		if (cmdLine.parameter == "-time" || cmdLine.parameter == "-both") {
			cout << "Running time: " << runtime << "ms" << endl;
		}
		if (cmdLine.parameter == "-comp" || cmdLine.parameter == "-both") {
			cout << "Comparisons: " << fixed << setprecision(0) << comps << endl;
		}
		break;
		
	case 2:
		if (cmdLine.order == "-rand") order = 0;
		else if (cmdLine.order == "-sorted") order = 1;
		else if (cmdLine.order == "-rev") order = 2;
		else if (cmdLine.order == "-nsorted") order = 3;
		array = new int[cmdLine.inputSize];
		GenerateData(array, cmdLine.inputSize, order);

		sortData(cmdLine.algorithm, array, cmdLine.inputSize, runtime, comps);
		cout << "---------------------------------------" << endl;
		if (cmdLine.parameter == "-time" || cmdLine.parameter == "-both") {
			cout << "Running time: " << runtime << "ms" << endl;
		}
		if (cmdLine.parameter == "-comp" || cmdLine.parameter == "-both") {
			cout << "Comparisons: " << fixed << setprecision(0) << comps << endl;
		}
		break;

	case 3:
		order = 0;
		array = new int[cmdLine.inputSize];
		while (order < 4) {
			GenerateData(array, cmdLine.inputSize, order);
			sortData(cmdLine.algorithm, array, cmdLine.inputSize, runtime, comps);

			cout << "Input Order: ";
			if (order == 0) cout << "Randomized" << endl;
			if (order == 1) cout << "Sorted" << endl;
			if (order == 2) cout << "Reversed" << endl;
			if (order == 3) cout << "Nearly Sorted" << endl;
			cout << "---------------------------------------" << endl;
			if (cmdLine.parameter == "-time" || cmdLine.parameter == "-both") {
				cout << "Running time: " << runtime << "ms" << endl;
			}
			if (cmdLine.parameter == "-comp" || cmdLine.parameter == "-both") {
				cout << "Comparisons: " << fixed << setprecision(0) << comps << endl;
			}
			cout << endl;
			order++;
		}
		break;

	case 4: 
		sortData(cmdLine.algorithm, array, cmdLine.inputSize, runtime, comps);
		array = readFile(cmdLine.input, cmdLine.inputSize);
		sortData(cmdLine.algorithm2, array, cmdLine.inputSize, runtime2, comps2);

		cout << "---------------------------------------" << endl;
		cout << "Running time: " << runtime << "ms" << " | " << runtime2 << "ms" << endl;
		cout << "Comparisons: " << fixed << setprecision(0) << comps;
		cout << " | " << fixed << setprecision(0) << comps2 << endl;

		break;

	case 5:
		if (cmdLine.order == "-rand") order = 0;
		else if (cmdLine.order == "-sorted") order = 1;
		else if (cmdLine.order == "-rev") order = 2;
		else if (cmdLine.order == "-nsorted") order = 3;
		array = new int[cmdLine.inputSize];
		int* copy = new int[cmdLine.inputSize];
		GenerateData(array, cmdLine.inputSize, order);
		for (int i = 0; i < cmdLine.inputSize; i++) {
			copy[i] = array[i];
		}

		sortData(cmdLine.algorithm, array, cmdLine.inputSize, runtime, comps);
		sortData(cmdLine.algorithm2, copy, cmdLine.inputSize, runtime2, comps2);

		cout << "Input Order: ";
		if (order == 0) cout << "Randomized" << endl;
		if (order == 1) cout << "Sorted" << endl;
		if (order == 2) cout << "Reversed" << endl;
		if (order == 3) cout << "Nearly Sorted" << endl;
		cout << "---------------------------------------" << endl;
		cout << "Running time: " << runtime << "ms" << " | " << runtime2 << "ms" << endl;
		cout << "Comparisons: " << fixed << setprecision(0) << comps;
		cout << " | " << fixed << setprecision(0) << comps2 << endl;
		
		delete[] copy;
		break;
	}
	
	delete[] array;

	return 0;
}

//main.exe -a bubble-sort 30000 -both