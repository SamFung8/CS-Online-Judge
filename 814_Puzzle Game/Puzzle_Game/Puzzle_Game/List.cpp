#include "List.h"
using namespace std;
#include <iostream>

string List::Print(int col, int row) {
	string s1, s2;
	ListNode* p = first;
	int printRight = 0, printDown = 0;
	string totalString;

	while (printDown < row) {
		while (printRight < col) {
			for (int i = 0; i < p->getRight(); i++) {
				s1 = s1 + to_string(p->getData()) + " ";
			}
			printRight += p->getRight();
			if(printRight < col)
				p = p->getNext();
		}
		s1 = s1.substr(0, s1.length() - 1);
		for (int q = 0; q < p->getDown(); q++) {
			totalString =totalString +  s1 + "\n";
		}
		printDown += p->getDown();
		printRight = 0;
		p = p->getNext();
		s1 = "";
	}
	return totalString;
}

void List::InsertNodeToNext(ListNode* newnode){
	if (first == NULL)
		first = newnode;
	else{
		ListNode* p = first;
		while (p->getNext() != NULL)
			p = p->getNext();
		newnode->next = p->getNext();
		p->next = newnode;
	}
}

void List::Swap(int data1, int data2) {
	ListNode* p = first;
	ListNode* node1 = first;
	ListNode* node2 = first;

	while (p != NULL)
	{
		if (p->getData() == data1)
			node1 = p;
		if (p->getData() == data2)
			node2 = p;
		p = p->getNext();
	}

	if (node1 != NULL && node2 != NULL)
	{
		int data = node1->data;
		node1->data = node2->data;
		node2->data = data;

		int right = node1->right;
		node1->right = node2->right;
		node2->right = right;

		int down = node1->down;
		node1->down = node2->down;
		node2->down = down;
		
	}


}



