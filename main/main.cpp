#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <string.h>
#include "DataGenerator.h"
#include "Sort.h"
#include <iomanip>
using namespace std;

int main(int argc, char* argv[])
{
	Command cmdLine;
	int* array = NULL, order = 0;
	double runtime = 0, runtime2 = 0, comps = 0, comps2 = 0;
	
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
			cout << "Running time: " << fixed << setprecision(4) << runtime / 1000 << "ms" << endl;
		}
		if (cmdLine.parameter == "-comp" || cmdLine.parameter == "-both") {
			cout << "Comparisons: " << fixed << setprecision(0) << comps << endl;
		}
		writeFile("output.txt", array, cmdLine.inputSize);
		break;
		
	case 2:
		if (cmdLine.order == "-rand") order = 0;
		else if (cmdLine.order == "-nsorted") order = 1;
		else if (cmdLine.order == "-sorted") order = 2;
		else if (cmdLine.order == "-rev") order = 3;
		array = new int[cmdLine.inputSize];
		GenerateData(array, cmdLine.inputSize, order);
		writeFile("input.txt", array, cmdLine.inputSize);

		sortData(cmdLine.algorithm, array, cmdLine.inputSize, runtime, comps);

		cout << "Input Order: ";
		if (order == 0) cout << "Randomized" << endl;
		if (order == 1) cout << "Nearly Sorted" << endl;
		if (order == 2) cout << "Sorted" << endl;
		if (order == 3) cout << "Reversed" << endl;
		cout << "---------------------------------------" << endl;
		if (cmdLine.parameter == "-time" || cmdLine.parameter == "-both") {
			cout << "Running time: " << fixed << setprecision(4) << runtime / 1000 << "ms" << endl;
		}
		if (cmdLine.parameter == "-comp" || cmdLine.parameter == "-both") {
			cout << "Comparisons: " << fixed << setprecision(0) << comps << endl;
		}
		writeFile("output.txt", array, cmdLine.inputSize);
		break;

	case 3:
		array = new int[cmdLine.inputSize];
		while (order < 4) {
			GenerateData(array, cmdLine.inputSize, order);
			string inputFile = "input_" + to_string(order + 1) + ".txt";
			writeFile(inputFile, array, cmdLine.inputSize);
			sortData(cmdLine.algorithm, array, cmdLine.inputSize, runtime, comps);

			cout << "Input Order: ";
			if (order == 0) cout << "Randomized" << endl;
			if (order == 1) cout << "Nearly Sorted" << endl;
			if (order == 2) cout << "Sorted" << endl;
			if (order == 3) cout << "Reversed" << endl;
			cout << "---------------------------------------" << endl;
			if (cmdLine.parameter == "-time" || cmdLine.parameter == "-both") {
				cout << "Running time: " << fixed << setprecision(4) << runtime / 1000 << "ms" << endl;
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
		cout << "Running time: " << fixed << setprecision(4) << runtime / 1000 << "ms" << " | " << runtime2 << "ms" << endl;
		cout << "Comparisons: " << fixed << setprecision(0) << comps;
		cout << " | " << fixed << setprecision(0) << comps2 << endl;

		break;

	case 5:
		if (cmdLine.order == "-rand") order = 0;
		else if (cmdLine.order == "-nsorted") order = 1;
		else if (cmdLine.order == "-sorted") order = 2;
		else if (cmdLine.order == "-rev") order = 3;
		array = new int[cmdLine.inputSize];
		int* copy = new int[cmdLine.inputSize];
		GenerateData(array, cmdLine.inputSize, order);
		writeFile("input.txt", array, cmdLine.inputSize);
		for (int i = 0; i < cmdLine.inputSize; i++) {
			copy[i] = array[i];
		}

		sortData(cmdLine.algorithm, array, cmdLine.inputSize, runtime, comps);
		sortData(cmdLine.algorithm2, copy, cmdLine.inputSize, runtime2, comps2);

		cout << "Input Order: ";
		if (order == 0) cout << "Randomized" << endl;
		if (order == 1) cout << "Nearly Sorted" << endl;
		if (order == 2) cout << "Sorted" << endl;
		if (order == 3) cout << "Reversed" << endl;
		cout << "---------------------------------------" << endl;
		cout << "Running time: " << fixed << setprecision(4) << runtime / 1000 << "ms" << " | " << runtime2 << "ms" << endl;
		cout << "Comparisons: " << fixed << setprecision(0) << comps;
		cout << " | " << fixed << setprecision(0) << comps2 << endl;
		
		delete[] copy;
		break;
	}
	
	delete[] array;

	return 0;
}

//main.exe -a bubble-sort 30000 -both