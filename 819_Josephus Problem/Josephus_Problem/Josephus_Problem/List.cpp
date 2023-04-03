#include "List.h"
using namespace std;
#include <iostream>

void List::InsertNodeToNext(ListNode* newnode) {
	if (first == NULL) {
		first = newnode;
		first->next = first;
	}
	else {
		ListNode* p = first;

		while (p->getNext() != first)
			p = p->getNext();
		newnode->next = first;
		p->next = newnode;
	}
}

void List::Search(int data, List* link, int printNum, int skipNum, int linkLength)
{
	ListNode* p = first;
	data = data % linkLength;
	if (data != 1)
		data = data - 1;
	else
		data = linkLength;
	while (true)
	{
		if (p->getData() == data) {
			link->Print(p, skipNum);
			break;
		}
		p = p->getNext();
	}
}

void List::Print(ListNode* node, int skipNum) {
	ListNode* p = node;
	while (true)
	{
		cout << to_string(p->next->getData()) + " ";
		RemoveNode(p);
		if (p->next == p) {
			cout << to_string(p->next->getData()) + "\n";
			break;

		}
		for (int j = 0; j < skipNum - 1; j++) {
			p = p->getNext();
		}

	}
}

void List::RemoveNode(ListNode* p) {
	p->next = p->next->next;
}






