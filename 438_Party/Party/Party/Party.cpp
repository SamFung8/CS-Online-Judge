#include <iostream>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

	int taskNum = 0;;

	cin >> taskNum;

	while (taskNum) {

		int num;

		cin >> num;

		if (num == 1 || num == 2) {
			cout << 0 << endl;
		}
		else {
			cout << (num - 2) << endl;
		}

		taskNum--;
	}

}