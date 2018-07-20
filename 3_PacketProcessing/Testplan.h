/*
* FILE			: Testplan.h
* PROJECT		: Coursera.Datastructure - Network packet processing simulation
* PROGRAMMER	: Eunjune Wi
* FIRST VERSION	: 2018-07-19
* DESCRIPTION	:
*	This file is a test suite for functional test of the program.
*/



/*
1. Test1
	a. Purpose: To check [Buffer.finish_time_] is popped properly
	b. Input (buffer size 1, 10 packets)
		1 10
		0 1
		1 1
		2 1
		3 1
		4 1
		5 1
		6 1
		7 1
		8 1
		9 1
	c. Expected output
		0 1 2 3 4 5 6 7 8 9

+++++++++++++++++++++++++++++++++++++++++

2. Test2
	a. Purpose: To check whether packets can wait until previous packets are processed
	b. Input (buffer size 5, 5 packets)
		10 5
		0 100
		1 100
		2 100
		3 100
		4 100
	c. Expected Output
		0 100 200 300 400

+++++++++++++++++++++++++++++++++++++++++

3. Test3
	a. Purpose: To check whether packets are dropped properly when buffer is full
	b. Input (buffer size 1, 5 packets)
		1 5
		0 100
		1 1
		2 2
		3 3
		4 4
	c. Expected Output
		0 -1 -1 -1 -1

+++++++++++++++++++++++++++++++++++++++++

4. Test4
	a. Purpose: To check packet is dropped properly when all of them comes at the same time
	b. Input (buffer size 5, 10 packets)
		5 10
		0 1
		0 1
		0 1
		0 1
		0 1
		0 1
		0 1
		0 1
		0 1
		0 1
	c. Expected output
		0 1 2 3 4 -1 -1 -1 -1 -1


+++++++++++++++++++++++++++++++++++++++++

5. Test5
	a. Purpose: To check whether test 1 ~ 4 works well when combined
	b. Input (buffer size 10, 0 packet)
		10 0
	c. Expected output
		N/A (no ouput at all)

+++++++++++++++++++++++++++++++++++++++++

6. Test6
	a. Purpose: To check whether the program works for complex input
	b. Input (buffer size 2, 10 packets)
		2 7
		0 10		
		2 5			
		3 10		
		10 5		
		15 5		
		15 10		
		100	1		
	c. Expected output
		0 10 -1 15 20 -1 100
*/