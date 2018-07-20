/*
* FILE			: Testplan.h
* PROJECT		: Coursera.Datastructure - Network packet processing simulation
* PROGRAMMER	: Eunjune Wi
* FIRST VERSION	: 2018-07-19
* DESCRIPTION	:
*	This file describes problem of this project.
*/



/*
1. Problem Introduction
	This is a program to simulate the processing of network packets.

2. Problem Description
	a) Task
		- The program simulates how packets are processed.
		Packet arrives in some order, and each packet will have when it arrives and how much time is required to process.
		There is only one processor, and it processes the incoming packets in the order of their arrival.
		If the processor started to process some packet, it doesn’t interrupt or stop until it finishes the processing of this packet.
		- There is a network buffer of fixed size.
		When packets arrive, they are stored in the buffer before being processed.
		However, if the buffer is full when a packet arrives, it is dropped and won’t be processed at all.
		If several packets arrive at the same time, they are first all stored in the buffer.
		If there are too many packets arriving at the same time, buffer will take the packet which arrives first,
		and drop rest of them.
		- The computer processes the packets in the order of their arrival,
		and it starts processing the next available packet from the buffer as soon as it finishes processing the previous one.
		If at some point the computer is not busy, and there are no packets in the buffer,
		the computer just waits for the next packet to arrive.
		- Note that a packet leaves the buffer and frees the space in the buffer as soon as the computer finishes processing it.
	b) Input Format
		first line: size of the buffer, the number of incoming network packets
		From second line: arrival time of each packet, processing time of each packet.
							It is guaranteed that the sequence of arrival times is non-decreasing.
							However, it can contain the exact same times of arrival.
		Constraints
		- All the numbers in the input are integers.
		- Buffer size:			1 <= S <= 105
		- Number of pacekts:	1 <= n <= 105
		- Arrival time:			0 <= a <= 106	{ where a.at(n) <= a.at(n+1) }
		- Processing time:		0 <= p <= 103
	c) Output Format
		For each packet output, either the moment of time when the processor began processing it
		or -1 if the packet was dropped
		in the same order as the packets are given in the input
*/