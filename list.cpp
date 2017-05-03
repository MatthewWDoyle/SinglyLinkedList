// list.cpp

#include <iostream>
#include "cmpt_error.h"

using namespace std;

struct Node {
	int val;
	Node* next;
};// struct Node

void test1() {
	Node* head = new Node{5, nullptr};
	cout << head->val << "\n";

	Node* p = new Node{3, nullptr};
	p->next = head;
	head = p;

	cout << head->val << " ";
	cout << head->next->val << "\n";

	delete head->next;
	delete head;
}

// Note that it is essential that head be passed by reference here, i.e. using
// the &. That's because the value of head is being modified.
void push(int x, Node*& head) {
	head = new Node{x, head};
}

// Note that it is essential that head be passed by reference here, i.e. using
// the &. That's because the value of head is being modified.
int pop(Node*& head) {
	if (head == nullptr) cmpt::error("can't pop empty list");
	Node* p = head;
	head = head->next;
	int result = p->val;
	delete p;
	return result;
}

void clear(Node*& head) {
	while (head != nullptr) {
		Node* p = head;
		head = head->next;
		delete p;
	}
}

void test2() {
	Node* head = nullptr;

	for(int i = 0; i < 100; ++i) push(i,head);

	cout << "Head Value : " << head->val << " ";
	cout << "Next Value: " << head->next->val << "\n";

	// Print the list
	for(Node* p = head; p != nullptr; p = p->next) {
		cout << "Printing list: " << p->val << " \n";
	}

	// Node* p = head;
	// while (p != nullptr) {
	// 	cout << p->val << " ";
	// 	p = p->next;
	// }

	// // delete all the elements from the list
	// while (head != nullptr) {
	// 	cout << pop(head) << " popped\n";
	// }

	clear(head);
}

int main() {
	//test1();
	test2();
}