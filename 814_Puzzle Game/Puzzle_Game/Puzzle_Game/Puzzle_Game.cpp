#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Node {
public:
	int data;
	Node* next;
};



Node* puzzle[1000][1000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long long int row = 0;
	while (cin >> row) {
		long long int col = 0, swap_times = 0;

		cin >> col;
		cin >> swap_times;

		for (long long int i = 0; i < row; i++) {
			Node* head = new Node();

			puzzle[i][0] = head;

			for (long long int j = 1; j <= col; j++) {
				long long int num;
				cin >> num;

				Node* temp = new Node();
				temp->data = num;
				head->next = temp;
				head = temp;

				puzzle[i][j] = temp;
			}

		}


		long long int r1, c1, r2, c2, h, w;

		for (long long int i = 0; i < swap_times; i++) {
			cin >> r1;
			cin >> c1;
			cin >> r2;
			cin >> c2;
			cin >> h;
			cin >> w;
			
			for (long long int j = 0; j < h; j++) {
				swap(puzzle[r1-1 + j][c1], puzzle[r2-1 + j][c2]);
			}
			
		}

		
	}

	return 0;
}