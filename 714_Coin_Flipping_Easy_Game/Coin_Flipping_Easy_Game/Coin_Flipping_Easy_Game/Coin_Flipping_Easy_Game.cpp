#include <iostream>
#include <cmath>
using namespace std;


int main() {
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
	
	char coin[100][10];
	char checkCoin[100][10];
	bool check[10];
	int row, col;


	while (cin >> row >> col) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				char num;
				cin >> num;
			
				coin[i][j] = num;
			}
		}


		for (int i = 0; i < col; i++) {
			check[i] = false;
		}


		int total = 0;
		int maxCol = 0;
		maxCol = pow(2, col);

		for (int x = 0; x < maxCol; x++) {

			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					checkCoin[i][j] = coin[i][j];
				}
			}

			for (int j = 0; j < col; j++) {
				if (check[j] == true)
					for (int i = 0; i < row; i++) {
						if (checkCoin[i][j] == '1') {
							checkCoin[i][j] = '0';
						}
						else {
							checkCoin[i][j] = '1';
						}
					}
			}


			int chceckTotal = 0;
			for (int i = 0; i < row; i++) {
				int temNum = 0;
				for (int j = 0; j < col; j++) {
					if (checkCoin[i][j] == '0')
						temNum++;
				}
				if (temNum > col / 2) {
					chceckTotal += temNum;
				}
				else {
					chceckTotal += col - temNum;
				}
			}


			for (int i = 0; i < col; i++) {
				if (check[i] == true) {
					check[i] = false;
				}
				else {
					check[i] = true;
					break;
				}
			}


			if (chceckTotal > total) {
				total = chceckTotal;
			}
		}

		cout << total << endl;
	}

	return 0;
}