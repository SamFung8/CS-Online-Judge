#include <iostream>
#include <queue>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
	
	int taskNum = 0;
	while (cin >> taskNum) {
		queue <int> line;
		int totalWaittingTime = 0;
		while (taskNum > 0) {
			taskNum--;
			int arrivalTime, orderTime, waitTime;
			cin >> arrivalTime >> orderTime >> waitTime;
			if (arrivalTime > totalWaittingTime)
				totalWaittingTime = arrivalTime;
			while (true) {
				if (line.empty())
					break;
				else if (line.front() <= arrivalTime)
					line.pop();
				else
					break;
			}

			if (waitTime < line.size()) {
				if (taskNum == 0) {
					cout << "-1" << endl;
					break;
				}
			}
			else {
				if (taskNum == 0) {
					cout << totalWaittingTime << endl;
					break;
				}
				totalWaittingTime += orderTime;
				line.push(totalWaittingTime);

			}
		}
	}
	return 0;
}