/*
* FILE			: abstractDataType.cpp
* PROJECT		: Coursera.Datastructure - Network packet processing simulation
* PROGRAMMER	: Eunjune Wi
* FIRST VERSION	: 2018-07-19
* DESCRIPTION	:
*	This file contains method definitions of abstract data types.
*/



#include "abstractDataType.h"



/* -----< METHOD >-----
* NAME		:	Process
* PURPOSE	:	This method takes each packet and returns how it is processed
* INPUTS
*	const Request&	request	:	Packet
* OUTPUTS	:	None
* RETURNS
*	Response	:	Result of how packet is processed
*/
Response	Buffer::Process(const Request& request)
{
	Response result(true, -1);		// By default, result will be dropping packet

	// 1. If packet arrives, check whether previous packet has been processed.
	//		If it is, element in [finish_time_] should be popped.
	while ((!this->finishTime.empty()) &&
		   (this->finishTime.front() <= request.arrivalTime))
	{
			this->finishTime.pop();
	}

	// 2. Check whether [finish_time_] is full, drop the packet
	if (this->finishTime.size() == this->size)
	{
		result.dropped = true;		// This is not necessary, but written for readability
		result.startTime = -1;
	}
	// 3. If [finish_time_] is available, there are two things to do
	//		a) push the newly arrived packet to the buffer
	//		b) return the result of the packet
	else
	{
		// Set the result of the packet
		result.dropped = false;
		if (this->finishTime.empty())
		{
			result.startTime = request.arrivalTime;
		}
		else
		{
			result.startTime = this->finishTime.back();
		}

		// Push the packet to the buffer
		int newFinishTime = -1;

		if (this->finishTime.empty())
		{
			newFinishTime = request.arrivalTime + request.processTime;
		}
		else
		{
			int lastFinishTime = this->finishTime.back();
			newFinishTime = lastFinishTime + request.processTime;
		}

		this->finishTime.push(newFinishTime);
	}


	return result;
}



/* -----< METHOD >-----
* NAME		:	Request		<< Constructor >>
* PURPOSE	:	This constructor creates instance of a packet.
* INPUTS
*	int		newArrivalTime	:	Arrival time of the packet
*	int		newProcessTime	:	Time required to process the packet
* OUTPUTS	:	None
* RETURNS	:	None
*/
Request::Request(int newArrivalTime, int newProcessTime)
{
	arrivalTime = newArrivalTime;
	processTime = newProcessTime;
}



/* -----< METHOD >-----
* NAME		:	Response		<< Constructor >>
* PURPOSE	:	This constructor creates instance of a response to the packet.
* INPUTS
*	bool	newDropped		:	Whether packet has been dropped or processed
*	int		newStartTime	:	When the packet has started to be processed
* OUTPUTS	:	None
* RETURNS	:	None
*/
Response::Response(bool newDropped, int newStartTime)
{
	dropped = newDropped;
	startTime = newStartTime;
}
	


/* -----< METHOD >-----
* NAME		:	Buffer		<< Constructor >>
* PURPOSE	:	This constructor creates instance of buffer for packet.
* INPUTS
*	int		newSize		:	Size of the buffer
* OUTPUTS	:	None
* RETURNS	:	None
*/
Buffer::Buffer(int newSize)
{
	size = newSize;
}