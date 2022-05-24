#pragma once
#include <iostream>
template<class T>


class queue {
private:
	class node {//node of the queue
	public:
		int info;
		node* next;
		node(int info = 0) {//constructor with the parameter
			this->info = info;
			next = NULL;
		}
	};
	int size;
	node* head;
	node* tail;

public:
	queue() { //constructor
		tail = head = NULL;
		size = 0;
	}

	~queue() { //destructor
		while (size > 0) {
			pop();
		}
	}

	void push(T info) {//adding an item
		if (size == 0)
			tail = head = new node(info);
		else
			tail = tail->next = new node(info);
		size++;
	}

	int pop() {//return the first item in the queue and delet them
		if (empty())
			throw "The queue is empty";
		else {
			int top_info = head->info;
			node* cur = head->next;
			delete head;
			head = cur;
			size--;
			return top_info;
		}
	}

	int get_size() { //return the queue size
		return size;
	}

	bool empty() { //is the queue empty?
		return (size == 0);
	}

	T front() {
		return head->info;
	}
};