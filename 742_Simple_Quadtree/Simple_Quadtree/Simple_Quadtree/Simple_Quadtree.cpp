#include <iostream>
#include <cmath>
using namespace std;
char pixel[1234][1234];
int totalNode = 0;

void findColor(int left, int right, int up, int down) {
	int skipC = (left + right) / 2;
	int skipR = (up + down) / 2;
	int color = pixel[up][left];
	bool stop = false;

	for (int x = up; x < down; x++) {
		for (int y = left; y < right; y++) {
			if (color != pixel[x][y]) {
				stop = true;
				break;
			}
		}
		if (stop)
			break;
	}

	totalNode += 1;

	if (stop) {
		findColor(left, skipC , up, skipR);
		findColor(left , skipC, skipR, down );
		findColor(skipC, right , up , skipR);
		findColor(skipC, right, skipR, down);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
	
	int N;
	while (cin >> N) {
		int m = pow(2, N);
		totalNode = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				cin >> pixel[i][j];
			}
		}

		findColor(0, m, 0, m);
		cout << totalNode;
		cout << "\n";
	}
	return 0;
}