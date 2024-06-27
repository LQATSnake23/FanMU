#include "Sort.h"

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

void sortData(string algorithm, int* arr, int n, int& run_time, double& comp) {
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