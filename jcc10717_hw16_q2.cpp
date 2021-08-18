
#include <iostream>
#include <vector>
#include <list>

using namespace std;

template<class T>
class vectorQueue {
	vector<T> data;
	int startOfQueue;

public:
	void enqueue(T newItem) { data.push_back(newItem); };
	T dequeue() {
		if (data.size() == 0) {
			cout << "Queue is empty";
			exit(1);//This should be a catch here? i would think? for the error of vector subscript out of range but IDK how to do that 
		}
		T temp = data[startOfQueue];
		startOfQueue += 1;

		if (startOfQueue >= (data.size())) {
			//cout << "empty";
			data.clear();
		}
		return temp;
	};
	vectorQueue() { startOfQueue = 0; };
};

/*
* order entered 1,2,3,4
vector [1 2 3 4]

after dequeue: [2 3 4]
returns 1

*/


int main() {
	//vectorQueue<int> test1;
	////test1.enqueue(1);
	////test1.enqueue(2);
	////test1.enqueue(3);
	////test1.enqueue(4);
	//cout << test1.dequeue();
	//cout << test1.dequeue();
	//cout << test1.dequeue();
	//cout << test1.dequeue();

	list<int> test;
	test.push_back(4);
	test.push_back(3);
	
	for (list<int>::iterator it = test.begin(); it != test.end(); it++) {
		cout << *it;
	}
	cout << endl;
	for (auto const& i : test) {
		cout << i;
		cout << endl;
	}

	return 0;
	
	
}