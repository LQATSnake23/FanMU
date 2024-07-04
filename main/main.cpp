#include <iostream>
#include <string>
#include <iomanip>
#include "Sort.h"
using namespace std;

int main(int argc, char* argv[])
{
	// Initialize values
	Command cmdLine;
	int* array = NULL, order = 0;
	double runtime = 0, runtime2 = 0, comps = 0, comps2 = 0;
	
	// Read mode input
	cmdLine.mode = argv[1];
	if (cmdLine.mode != "-a" && cmdLine.mode != "-c") {
		cmdLine.exist = false;
	}

	// If the mode is algorithm mode
	if (cmdLine.exist && cmdLine.mode == "-a") {
		cmdLine.algorithm = argv[2];
		cmdLine.input = argv[3];
		
		// Check whether the input method is file or number
		bool isFile = false;
		for (int i = 0; i < cmdLine.input.length(); i++) {
			if (cmdLine.input[i] == '.') {
				isFile = true;
				break;
			}
		}
		if (isFile) {
			// Command type 1 if input method is file
			array = readFile(cmdLine.input, cmdLine.inputSize);
			cmdLine.parameter = argv[4];
			cmdLine.type = 1;
		}
		else {
			cmdLine.inputSize = stoi(cmdLine.input);
		}

		// Check if the command specifies a data order
		cmdLine.order = argv[4];
		if (cmdLine.order == "-time" || cmdLine.order == "-comp" || cmdLine.order == "-both") {
			// If no data order is given
			cmdLine.parameter = cmdLine.order;
			cmdLine.order = "";
			if (cmdLine.type != 1) {
				cmdLine.type = 3; // Command type 3 if the input method is number and no data order is specified
			}
		}
		else {
			// Command type 2 the input method is number and a data order is given
			cmdLine.parameter = argv[5];
			cmdLine.type = 2;
		}
	}

	// If the mode is comparison mode
	else if (cmdLine.exist && cmdLine.mode == "-c") {
		cmdLine.algorithm = argv[2];
		cmdLine.algorithm2 = argv[3];
		cmdLine.input = argv[4];

		// Check whether the input method is file or number
		bool isFile = false;
		for (int i = 0; i < cmdLine.input.length(); i++) {
			if (cmdLine.input[i] == '.') {
				isFile = true;
				break;
			}
		}
		if (isFile) {
			// If the input method is file, command type is 4
			array = readFile(cmdLine.input, cmdLine.inputSize);
			cmdLine.type = 4;
		}
		else {
			// If the input method is number, command type is 5
			cmdLine.inputSize = stoi(cmdLine.input);
			cmdLine.order = argv[5];
			cmdLine.type = 5;
		}
	}

	// If the command line doesn't specify a valid mode
	else {
		cout << "Invalid input!" << endl;
		return 0;
	}

	// Printing command line information
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

	// Process based on command type
	switch (cmdLine.type) {
	case 1: // Sort an array from an input file 

		// Sort the array with running time and comparisons
		sortData(cmdLine.algorithm, array, cmdLine.inputSize, runtime, comps);

		// Output results based on parameters
		cout << "---------------------------------------" << endl;
		if (cmdLine.parameter == "-time" || cmdLine.parameter == "-both") {
			cout << "Running time: " << fixed << setprecision(3) << runtime / 1000 << "ms" << endl;
		}
		if (cmdLine.parameter == "-comp" || cmdLine.parameter == "-both") {
			cout << "Comparisons: " << fixed << setprecision(0) << comps << endl;
		}

		// Write the sorted array to output file
		writeFile("output.txt", array, cmdLine.inputSize);

		break;
		
	case 2: // Sort an array with a given input size and data order 

		// Create the array using the data order and input size
		if (cmdLine.order == "-rand") order = 0;
		else if (cmdLine.order == "-nsorted") order = 1;
		else if (cmdLine.order == "-sorted") order = 2;
		else if (cmdLine.order == "-rev") order = 3;
		array = new int[cmdLine.inputSize];
		GenerateData(array, cmdLine.inputSize, order);

		// Write the created array to input.txt
		writeFile("input.txt", array, cmdLine.inputSize);

		// Sort the array with running time and comparisons
		sortData(cmdLine.algorithm, array, cmdLine.inputSize, runtime, comps);

		// Output results based on parameters
		cout << "Input Order: ";
		if (order == 0) cout << "Randomized" << endl;
		if (order == 1) cout << "Nearly Sorted" << endl;
		if (order == 2) cout << "Sorted" << endl;
		if (order == 3) cout << "Reversed" << endl;
		cout << "---------------------------------------" << endl;
		if (cmdLine.parameter == "-time" || cmdLine.parameter == "-both") {
			cout << "Running time: " << fixed << setprecision(3) << runtime / 1000 << "ms" << endl;
		}
		if (cmdLine.parameter == "-comp" || cmdLine.parameter == "-both") {
			cout << "Comparisons: " << fixed << setprecision(0) << comps << endl;
		}

		// Write the sorted array to output file
		writeFile("output.txt", array, cmdLine.inputSize);

		break;

	case 3: // The input method is an input size number with no data order given

		// Sort through all possible data orders
		array = new int[cmdLine.inputSize];
		while (order < 4) {
			// Generate the input array
			GenerateData(array, cmdLine.inputSize, order);

			// Write input array to different input files
			string inputFile = "input_" + to_string(order + 1) + ".txt";
			writeFile(inputFile, array, cmdLine.inputSize);

			// Sort the array with running time and comparisons
			sortData(cmdLine.algorithm, array, cmdLine.inputSize, runtime, comps);

			// Output results based on parameters
			cout << "Input Order: ";
			if (order == 0) cout << "Randomized" << endl;
			if (order == 1) cout << "Nearly Sorted" << endl;
			if (order == 2) cout << "Sorted" << endl;
			if (order == 3) cout << "Reversed" << endl;
			cout << "---------------------------------------" << endl;
			if (cmdLine.parameter == "-time" || cmdLine.parameter == "-both") {
				cout << "Running time: " << fixed << setprecision(3) << runtime / 1000 << "ms" << endl;
			}
			if (cmdLine.parameter == "-comp" || cmdLine.parameter == "-both") {
				cout << "Comparisons: " << fixed << setprecision(0) << comps << endl;
			}
			cout << endl;

			order++; // Continue to the next data order
		}

		break;

	case 4: // Compare 2 algorithms using input file

		// Sort the array using the first algorithm
		sortData(cmdLine.algorithm, array, cmdLine.inputSize, runtime, comps);

		// Sort the array using the second algorithm
		array = readFile(cmdLine.input, cmdLine.inputSize);
		sortData(cmdLine.algorithm2, array, cmdLine.inputSize, runtime2, comps2);

		// Output results based on parameters
		cout << "---------------------------------------" << endl;
		cout << "Running time: " << fixed << setprecision(3) << runtime / 1000 << "ms" << " | " << runtime2 / 1000 << "ms" << endl;
		cout << "Comparisons: " << fixed << setprecision(0) << comps;
		cout << " | " << fixed << setprecision(0) << comps2 << endl;

		break;

	case 5: // Compare 2 algorithms using an input size and data order

		// Create the input array based on the data order and input size
		if (cmdLine.order == "-rand") order = 0;
		else if (cmdLine.order == "-nsorted") order = 1;
		else if (cmdLine.order == "-sorted") order = 2;
		else if (cmdLine.order == "-rev") order = 3;
		array = new int[cmdLine.inputSize];
		GenerateData(array, cmdLine.inputSize, order);

		// Create a 2nd input array with the same value
		int* copy = new int[cmdLine.inputSize]; 
		for (int i = 0; i < cmdLine.inputSize; i++) {
			copy[i] = array[i];
		}

		// Write the input array to input file
		writeFile("input.txt", array, cmdLine.inputSize);
		
		// Sort the array using the first algorithm
		sortData(cmdLine.algorithm, array, cmdLine.inputSize, runtime, comps);

		// Sort the 2nd array using the second algorithm
		sortData(cmdLine.algorithm2, copy, cmdLine.inputSize, runtime2, comps2);

		// Output results based on parameters
		cout << "Input Order: ";
		if (order == 0) cout << "Randomized" << endl;
		if (order == 1) cout << "Nearly Sorted" << endl;
		if (order == 2) cout << "Sorted" << endl;
		if (order == 3) cout << "Reversed" << endl;
		cout << "---------------------------------------" << endl;
		cout << "Running time: " << fixed << setprecision(3) << runtime / 1000 << "ms" << " | " << runtime2 / 1000 << "ms" << endl;
		cout << "Comparisons: " << fixed << setprecision(0) << comps;
		cout << " | " << fixed << setprecision(0) << comps2 << endl;
		
		// Delete the 2d array
		delete[] copy;

		break;
	}
	
	// Delete the input array
	delete[] array;

	return 0;
}