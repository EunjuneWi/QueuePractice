#include <iostream>
#include <queue>
#include <vector>

struct Request {
	Request(int arrival_time, int process_time) :
		arrival_time(arrival_time),
		process_time(process_time)
	{}

	int arrival_time;
	int process_time;
};

struct Response {
	Response(bool dropped, int start_time) :
		dropped(dropped),
		start_time(start_time)
	{}

	bool dropped;
	int start_time;
};

class Buffer {
public:
	Buffer(int size) :
		size_(size),
		finish_time_()
	{}

	Response Process(const Request &request) {
		

		Response result(true, -1);		// By default, result will be dropping packet

										// 1. If packet arrives, check whether previous packet has been processed.
										//		If it is, element in [finish_time_] should be popped.
		while ((!this->finish_time_.empty()) &&
			(this->finish_time_.front() <= request.arrival_time))
		{
			this->finish_time_.pop();
		}

		// 2. Check whether [finish_time_] is full, drop the packet
		if (this->finish_time_.size() == this->size_)
		{
			result.dropped = true;		// This is not necessary, but written for readability
			result.start_time = -1;
		}
		// 3. If [finish_time_] is available, there are two things to do
		//		a) push the newly arrived packet to the buffer
		//		b) return the result of the packet
		else
		{
			// Set the result of the packet
			result.dropped = false;
			if (this->finish_time_.empty())
			{
				result.start_time = request.arrival_time;
			}
			else
			{
				result.start_time = this->finish_time_.back();
			}

			// Push the packet to the buffer
			int newFinishTime = -1;

			if (this->finish_time_.empty())
			{
				newFinishTime = request.arrival_time + request.process_time;
			}
			else
			{
				int lastFinishTime = this->finish_time_.back();
				newFinishTime = lastFinishTime + request.process_time;
			}

			this->finish_time_.push(newFinishTime);
		}


		return result;


	}
private:
	int size_;
	std::queue <int> finish_time_;
};

std::vector <Request> ReadRequests() {
	std::vector <Request> requests;
	int count;
	std::cin >> count;
	for (int i = 0; i < count; ++i) {
		int arrival_time, process_time;
		std::cin >> arrival_time >> process_time;
		requests.push_back(Request(arrival_time, process_time));
	}
	return requests;
}

std::vector <Response> ProcessRequests(const std::vector <Request> &requests, Buffer *buffer) {
	std::vector <Response> responses;
	for (int i = 0; i < requests.size(); ++i)
		responses.push_back(buffer->Process(requests[i]));
	return responses;
}

void PrintResponses(const std::vector <Response> &responses) {
	for (int i = 0; i < responses.size(); ++i)
		std::cout << (responses[i].dropped ? -1 : responses[i].start_time) << std::endl;
}

int main() {
	int size;
	std::cin >> size;
	std::vector <Request> requests = ReadRequests();

	Buffer buffer(size);
	std::vector <Response> responses = ProcessRequests(requests, &buffer);

	PrintResponses(responses);
	return 0;
}
