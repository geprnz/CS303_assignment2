#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <cstddef>
#include <exception>
#include <fstream>
#include <sstream>
#include <cctype>
using namespace std;

// Node struct
template <typename T>
struct Node {
	T data;
	Node<T>* next;

	Node(T value) : data(value), next(nullptr) {}
};

// Custom exception
class EmptyList : public runtime_error {
public:
	EmptyList(const string& msg) : runtime_error(msg) {}
};

// Linked list class declaration
template <typename T>
class LinkedList {
private:
	// Data items
	Node<T>* head;
	Node<T>* tail;
	size_t num_items;

public:
	// Default constructor
	LinkedList() : head(nullptr), tail(nullptr), num_items(0) {}

	// Destructor
	~LinkedList() {
		Node<T>* temp;
		while (head != nullptr) {
			temp = head;
			head = head->next;
			delete temp;
		}
	}

	void push_front(T value) {
		Node<T>* newVal = new Node<T>(value);
		newVal->next = head;
		head = newVal;
		if (tail == nullptr) tail = newVal;

		++num_items;
	}

	void push_back(T value) {
		Node<T>* newVal = new Node<T>(value);

		if (tail == nullptr) head = tail = newVal;

		else {
			tail->next = newVal;
			tail = newVal;
		}

		++num_items;
	}

	void pop_front() {
		if (head == nullptr) throw EmptyList("List is empty");

		Node<T>* temp = head;
		head = head->next;

		delete temp;

		if (head == nullptr) {
			tail = nullptr;
		}

		--num_items;
	}

	void pop_back() {
		if (head == nullptr) throw EmptyList("List is empty"); // Empty list

		if (head == tail) {								    // List with one element
			delete head;
			head = tail = nullptr;
			--num_items;
			return;
		}

		Node<T>* temp = head;
		while (temp->next != tail) {
			temp = temp->next;
		}

		delete tail;
		tail = temp;
		tail->next = nullptr;

		--num_items;
	}

	T& front() const {
		if (empty()) throw EmptyList("List is empty");
		return head->data;
	}

	T& back() const {
		if (empty()) throw EmptyList("List is empty");
		return tail->data;
	}

	bool empty() const {
		return num_items == static_cast<size_t>(0);
	}

	void insert(size_t index, const T& item) {
		if (index > num_items) throw out_of_range("Index out of range");

		Node<T>* newNode = new Node<T>(item);

		if (index == static_cast<size_t>(0)) {
			newNode->next = head;
			head = newNode;
			if (num_items == 0) {
				tail = newNode;
			}
		}
		else {
			Node<T>* prev = head;
			for (size_t i = 0; i < index - 1; ++i) {
				prev = prev->next;
			}

			newNode->next = prev->next;
			prev->next = newNode;

			if (newNode->next == nullptr) {
				tail = newNode;
			}
		}

		++num_items;
	}

	bool remove(size_t index) {
		if (index >= num_items) {
			return false;
		}

		Node<T>* toDelete = nullptr;

		if (index == static_cast<size_t>(0)) {
			toDelete = head;
			head = head->next;
			if (head == nullptr) {
				tail = nullptr;
			}
		}
		else {
			Node<T>* prev = head;
			for (size_t i = 0; i < index - 1; ++i) {
				prev = prev->next;
			}

			toDelete = prev->next;
			prev->next = toDelete->next;

			if (toDelete == tail) {
				tail = prev;
			}
		}
		delete toDelete;
		--num_items;
		return true;
	}

	size_t find(const T& item) {
		size_t i = 0;
		Node<T>* temp = head;
		while (temp != nullptr) {
			if (temp->data == item) return i;
			temp = temp->next;
			++i;
		}

		return num_items;
	}
};
