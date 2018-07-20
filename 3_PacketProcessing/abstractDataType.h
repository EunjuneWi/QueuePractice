/*
* FILE			: abstractDataType.h
* PROJECT		: Coursera.Datastructure - Network packet processing simulation
* PROGRAMMER	: Eunjune Wi
* FIRST VERSION	: 2018-07-19
* DESCRIPTION	:
*	This file contains definition of abstract data types in the project.
*/
#pragma once



#include <queue>



using namespace std;



/* ------------------------------------------ */
/*             STRUCT DEFINITION              */
/* ------------------------------------------ */

/*
* NAME		:	Request
* PURPOSE	:	Request has been created to accurately model the attributes of network packets.
*				The Request has member to represent when it arrives to the processor,
*				and how much time is required for processor to process the packet.
*/
struct Request
{
	// Attributes
	int		arrivalTime;
	int		processTime;

	// Constructor
	Request(int newArrivalTime, int newProcessTime);

};



/*
* NAME		:	Response
* PURPOSE	:	Response has been created to accurately model result of packet processing.
*				The Response has member to represent whether packet has been dropped,
*				and the time that processor started to process the packet.
*/
struct Response
{
	// Attributes
	bool	dropped;
	int		startTime;

	// Constructor
	Response(bool newDropped, int newStartTime);
};



/* ------------------------------------------ */
/*              CLASS DEFINITION              */
/* ------------------------------------------ */

/*
* NAME		:	Buffer
* PURPOSE	:	The Buffer class has been created to accurately model buffer to store incoming packet
*				The PioneerCarRadio has members to represent how many packets it can store,
*				and expected time of finish time of packet processing
*				PioneerCarRadio has the ability	to simulate result of packet processing.
*/
class Buffer
{
	/* ----------------------- */
	/*         PRIVATE         */
	/* ----------------------- */
private:
	// Attributes
	int size;
	queue <int> finishTime;



	/* ----------------------- */
	/*         PUBLIC          */
	/* ----------------------- */
public:
	// Constructor
	Buffer(int newSize);

	// Method to process packets in the buffer
	Response Process(const Request &request);
};