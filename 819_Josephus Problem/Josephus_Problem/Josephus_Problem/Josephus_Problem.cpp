#include <iostream>
#include <list>
#include "List.h"
#include <chrono>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	
	List link;
	ListNode node[100000];
	int start = 0;
	int end = 0;
	int linkLength = 0;


	cin >> end;
	cin >> start;

	for (int i = 1; i <= end; i++) {
		node[i].data = i;
		link.InsertNodeToNext(&node[i]);
		linkLength++;
	}

	link.Search(start, &link, end, start, linkLength);


}
