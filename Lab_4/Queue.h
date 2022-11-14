#pragma once
#include <iostream>
#include <ostream>
#include <iomanip>
#include  <conio.h>
using namespace std;

template <class T>
struct Node {
	T data;
	Node<T>* previous = nullptr;
	Node<T>* next = nullptr;
};

template <class T>
class Queue {
private:
	Node<T> *head = nullptr;
	Node<T> *tail = nullptr;
	int amount = 0;

public:
	Queue() {};
	~Queue();
	int size() { return this->amount; }
	void pushHead(T obj);
    void pushPos(T obj, int num);
	void push(T obj, int num);
	void pushTail(T input_object);
	T popHead();
	T pop(int num);
	T popTail();
	T& operator[](int num);
	void output();
	void deleteAll();
};

template<class T>
void Queue<T>::pushHead(T obj) {
	if (head == nullptr) {
		head = new Node<T>;
		head->data = obj;
		head->next = nullptr;
		head->previous = nullptr;
		tail = head;
		amount++;
	}
	else {
		auto *node = new Node<T>;
		node->data = obj;
		node->next = head;
		node->previous = nullptr;
		head->previous = node;
		head = node;
		amount++;
	}
}


template<typename T>

void Queue<T>::pushPos(T obj, int num)
{
    if(!head)
    {
        pushHead(obj);
        return;
    }

    Node<T>* node = new Node<T>;
    node->data = obj;

    Node<T>* curr = head;

    for(int i = 0; i < num-1 && i < amount-1; i++)
        curr = curr->next;

    if(!curr)
    {
        pushTail(obj);
        return;
    }

    if(curr == head)
    {
        node->next = head;
        head->previous = node;
        head = node;
        amount++;
        return;
    }

    node->next = curr;
    node->previous = curr->previous;
    curr->previous->next = node;
    curr->previous = node;
    amount++;
}


template<class T>
void Queue<T>::push(T obj, int num) {

    auto *node = new Node<T>;
    Node<T> *curr = head;
    for(int i = 0 ; i < num; i++)
        curr = curr->next;
	Node<T> *next = curr->next;
	Node<T> *prev = curr->previous;
	node->data = obj;
	node->next = next;
	next->previous = node;
	node->previous = prev;
	prev->next = node;
	amount++;
}

template<class T>
void Queue<T>::pushTail(T input_object) {
	if (head == nullptr) {
		head = new Node<T>;
		head->data = input_object;
		head->next = nullptr;
		head->previous = nullptr;
		tail = head;
		amount++;
		return;
	}
	auto *node = new Node<T>;
	node->data = input_object;
	node->next = nullptr;
	node->previous = tail;
	tail->next = node;
	tail = node;
	amount++;
}

template<class T>
T& Queue<T>::operator[](int num) {
	Node<T> *curr = head;
	if (num < 0 || num >= amount) return curr->data;
	for (int i = 0; i < num; i++)
		curr = curr->next;
	return curr->data;
}

template<class T>
Queue<T>::~Queue() {
	while (this->head)
		this->popHead();
}

template<class T>
T Queue<T>::popHead() {
    T data;
	if (!(head)) return data;
	data = head->data;
	Node<T>* node = head;
	if (head != tail) {
		head = head->next;
		head->previous = nullptr;
		Node<T>* tmp = head;
	}
	else {
		head = tail = nullptr;
	}
	delete node;
	amount--;
	return data;
}

template<class T>
T Queue<T>::pop(int num) {
	if (num == 0)  return popHead();
	if (num == amount - 1) return popTail();
	Node<T> *curr = head;
	for (int i = 0; i < num; i++)
		curr = curr->next;
	Node<T>*prev = curr->previous;
	Node<T>*next = curr->next;
	T data = curr->data;
	amount--;
	prev->next = next;
	next->previous = prev;
	delete curr;
	return data;
}

template<class T>
T Queue<T>::popTail() {
	if (!(head)) return T();
	T data = tail->data;
	Node<T> *node = tail;
	if (tail != head) {
		tail = tail->previous;
		tail->next = nullptr;
	}
	else {
		head = tail = nullptr;
	}
	delete node;
	amount--;
	return data;
}

template<class T>
void Queue<T>::deleteAll() {
	while (this->head) { this->popHead(); }
}

template<class T>
void Queue<T>::output() {
	int i = 0;
	for (Node<T> *node = head; node != nullptr; node = node->next) {
		std::cout << "¹" << i + 1 << "|" << node->data;
		std::cout << std::endl;
		i++;
	}
}

