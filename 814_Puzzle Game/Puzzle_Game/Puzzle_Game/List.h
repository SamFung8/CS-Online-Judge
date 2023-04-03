#pragma once
#include <string>
using namespace std;

class ListNode
{
public:
	ListNode() {};
	ListNode* getNext() {
		return next;
	}
	int getDown() {
		return down;
	}
	int getData() {
		return data;
	}
	int getRight() {
		return right;
	}
public:
	int data;
	ListNode* next = NULL;
	int down;
	int right;
};

class List
{
public:
	List() {};
	string Print(int , int);
	void InsertNodeToNext(ListNode*);
	void Swap(int, int);
public:
	ListNode* first = NULL;
};




