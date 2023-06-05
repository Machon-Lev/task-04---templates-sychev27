#pragma once

#include <iostream>
#include <list>
#include <exception>
using std::list;

template <class T>
struct MyComparator
{
	T operator()(const T& a, const T& b)  {
		return a - b;
	}
};

// any templates?
template <class T>
class PriorityQueue {
   
public:
	
   // You need to complete the implement : 
    void push(const T& t); 
	T poll();
	PriorityQueue();


private:
// add relevant data members
    list<T> myQueue;
};

template <class T>
PriorityQueue<T>::PriorityQueue()
{
	myQueue = {}; 
}

template <class T>
void PriorityQueue<T>::push(const T& t)
{
	MyComparator<T> comperator;
	if (myQueue.empty())
	{
		myQueue.push_front(t);
	}
	else
	{
		auto iterator = myQueue.begin();
		while (iterator != myQueue.end() && comperator(*iterator, t) < 0)
		{
			++iterator;
		}
		myQueue.insert(iterator, t);
	}
}

template <class T>
T PriorityQueue<T>::poll()
{
	if (myQueue.empty())
		throw std::runtime_error("PriorityQueue empty !");

	T element = myQueue.front();
	myQueue.pop_front();
	return element;
}
