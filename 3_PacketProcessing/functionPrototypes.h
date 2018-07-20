/*
* FILE			: functionPrototypes.h
* PROJECT		: Coursera.Datastructure - Network packet processing simulation
* PROGRAMMER	: Eunjune Wi
* FIRST VERSION	: 2018-07-19
* DESCRIPTION	:
*	This file contains definition of function prototypes of the project.
*/
#pragma once



#include <vector>
#include "abstractDataType.h"



using namespace std;



vector <Request> readRequests(void);
vector <Response> processRequests(const vector <Request>& requests, Buffer* pBuffer);
void printResponses(const vector <Response>& responses);