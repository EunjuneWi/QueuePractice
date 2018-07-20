/*
* FILE			: packetProcess.cpp
* PROJECT		: Coursera.Datastructure - Network packet processing simulation
* PROGRAMMER	: Eunjune Wi
* FIRST VERSION	: 2018-07-19
* DESCRIPTION	:
*	This file contains function definitions related to packet processing
*/



#include <iostream>
#include <vector>
#include "abstractDataType.h"



using namespace std;



/*
* FUNCTION		: readRequests
* DESCRIPTION	: This function gets information of incoming packets.
* PARAMETERS	: void
* RETURNS		
*	vector		: Vector with information of incoming packets
*/
vector <Request> readRequests(void)
{
	// Vector to return
	vector <Request> requests;

	// Number of packets
	int count;
	cin >> count;

	// Get the information of each packets
	for (int i = 0; i < count; ++i) 
	{
		int arrival_time, process_time;
		cin >> arrival_time >> process_time;
		requests.push_back(Request(arrival_time, process_time));
	}

	return requests;
}



/*
* FUNCTION		: processRequests
* DESCRIPTION	: This function simulates packeet processing.
* PARAMETERS	
*	const vector <Request>&		requests	:	Vector with packets
*	Buffer*						pBuffer		:	Pointer to the buffer
* RETURNS
*	vector		: Vector with information of incoming packets
*/
vector <Response> processRequests(const vector <Request>& requests, Buffer* pBuffer)
{
	// Vector to store result of packet processing.
	vector <Response> responses;

	// Process each packet
	for (int i = 0; i < requests.size(); ++i)
	{
		responses.push_back(pBuffer->Process(requests[i]));
	}

	return responses;
}



/*
* FUNCTION		: printResponses
* DESCRIPTION	: This function prints out result of packet processing
* PARAMETERS
*	const vector <Response>&	responses	:	Vector with result of processing
* RETURNS		: void
*/
void printResponses(const vector <Response> &responses)
{
	for (int i = 0; i < responses.size(); ++i)
	{
		cout << (responses[i].dropped ? -1 : responses[i].startTime) << endl;
	}
}