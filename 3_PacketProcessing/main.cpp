/*
* FILE			: main.cpp
* PROJECT		: Coursera.Datastructure - Network packet processing simulation
* PROGRAMMER	: Eunjune Wi
* FIRST VERSION	: 2018-07-19
* DESCRIPTION	:
*	This file contains main function of the program.
*	For problem description of this program, refer to [problemDesc.h] file.
*/



#include <iostream>
#include <vector>
#include "abstractDataType.h"
#include "functionPrototypes.h"



using namespace std;



int main() {
	// Get the size of buffer
	int size;
	cin >> size;

	// Get the information of packets
	vector <Request> requests = readRequests();

	// Simulate packet processing
	Buffer buffer(size);
	vector <Response> responses = processRequests(requests, &buffer);

	// Print out the result
	printResponses(responses);

	return 0;
}