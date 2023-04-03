#include <iostream>
#include <vector>
using namespace std;

vector <int> postOrder;

int findIndex(int order[], int x, int num) {
	for (int i = 0; i < num; i++) {
		if (order[i] == x) {
			return i;
		}
	}
	return 0;
}

void findOrder(int inOrder[], int preOrder[], int num) {
	int rootPostion = findIndex(inOrder, preOrder[0], num);
	if (rootPostion != 0) {
		findOrder(inOrder, preOrder + 1, rootPostion);
	}
	if (rootPostion != num - 1) {
		findOrder(inOrder  + (1 + rootPostion), preOrder + (1 + rootPostion), num - (1 + rootPostion));
	}
	postOrder.push_back(preOrder[0]);
}

int main() {
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
	
	int taskNum = 0, currentTaskNum = 0;
	cin >> taskNum;
	while (taskNum > currentTaskNum) {
		int preOrder[100], inOrder[100], num = 0;
		cin >> num;
		for (int i = 0; i < num; i++) {
			cin >> preOrder[i];
		}
		for (int i = 0; i < num; i++) {
			cin >> inOrder[i];
		}
		findOrder(inOrder, preOrder, num);
		for (int i = 0; i < num; i++) {
			if (i != num - 1)
				cout << postOrder[i] << " ";
			else
				cout << postOrder[i] << endl;
		}
		postOrder.clear();
		currentTaskNum++;
	}
	return 0;
}