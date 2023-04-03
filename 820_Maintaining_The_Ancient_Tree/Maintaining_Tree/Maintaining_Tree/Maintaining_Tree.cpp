#include <queue>
#include <iostream>
#include <map>
using namespace std;

int total = 0;

struct Node
{
	int branches;
	int leaves;
	vector <Node*> child;
};

Node* newNode(int key)
{
	Node* temp = new Node;
	temp->branches = key;
	temp->leaves = 0;
	return temp;
}



int findMin(Node* KRoot, Node* CRoot)
{
	Node* keepTree = KRoot;
	Node* cutTree = CRoot;

	int num = 0;

	num += cutTree->leaves;

	int findCount = 0;
	for (int i = 0; i < keepTree->child.size(); i++) {
		int findNum = keepTree->child[i]->branches;
		bool find = false;
		int p = 0;

		for (int j = 0; j < cutTree->child.size(); j++) {
			if (cutTree->child[j]->branches == findNum) {
				find = true;
				p = j;
				findCount++;
				break;
			}
		}

		if (find) {
			num += findMin(keepTree->child[i], cutTree->child[p]);
		}

	}

	num += cutTree->child.size() - findCount;

	return num;
}



int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
	
	int taskNum = 0;
	cin >> taskNum;

	while (taskNum > 0) {
		Node* root = newNode(0);

		int needCut = 0, notCut = 0;
		cin >> needCut >> notCut;

		for (int i = 0; i < needCut; i++) {
			vector <int> temTree;

			while (true) {
				int tem = 0;
				cin >> tem;

				if (tem == -1) {
					Node* first = root;
					for (int j = 0; j < temTree.size() - 1; j++) {
						bool find = false;
						int nextNode = 0;
						for (int k = 0; k < first->child.size(); k++) {
							if (first->child[k]->branches == temTree[j]) {
								find = true;
								nextNode = k;
								break;
							}
						}
						if (find) {
							first = first->child[nextNode];
						}
						else {
							first->child.push_back(newNode(temTree[j]));
							first = first->child[first->child.size() - 1];
						}
					}
					first->leaves++;
					break;
				}
				else {
					temTree.push_back(tem);
				}
			}

		}


		Node* keepRoot = newNode(0);


		for (int i = 0; i < notCut; i++) {
			vector <int> temTree;
			while (true) {
				int tem = 0;
				cin >> tem;

				if (tem == -1) {
					Node* first = keepRoot;
					for (int j = 0; j < temTree.size() - 1; j++) {
						bool find = false;
						int nextNode = 0;
						for (int k = 0; k < first->child.size(); k++) {
							if (first->child[k]->branches == temTree[j]) {
								find = true;
								nextNode = k;
								break;
							}
						}
						if (find) {
							first = first->child[nextNode];
						}
						else {
							first->child.push_back(newNode(temTree[j]));
							first = first->child[first->child.size() - 1];
						}
					}
					first->leaves++;
					break;
				}
				else {
					temTree.push_back(tem);
				}
			}
		}


		if (notCut == 0) {
			int min = 0;
			min += root->leaves;
			min += root->child.size();
			cout << min;
			cout << "\n";
		}
		else {
			int min = 0;

			min += findMin(keepRoot, root);

			cout << min;
			cout << "\n";
		}



		taskNum--;
	}

	return 0;
}
