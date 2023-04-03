#pragma once
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
	int getData() {
		return data;
	}
public:
	int data;
	ListNode* next = NULL;
};

class List
{
public:
	List() {};
	void Print(ListNode*, int);
	void InsertNodeToNext(ListNode*);
	void Search(int, List*, int, int, int);
	void RemoveNode(ListNode*);
public:
	ListNode* first = NULL;
};




