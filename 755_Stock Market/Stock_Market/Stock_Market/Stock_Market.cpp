#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
	
	int T, N, ni, temp;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		stack <long long int> stck;
		int hist[100000];
		for (int i = 0; i < N; i++) {
			cin >> ni;
			hist[i] = ni;
		}
		long long int topArea = 0, maxArea = 0;
		int n = 0;
		while (n < N) {
			if (stck.empty() || hist[stck.top()] <= hist[n]) {
				stck.push(n++);
			}
			else {
				temp = stck.top();
				stck.pop();
				topArea = hist[temp] * (!stck.empty() ? n - stck.top() - 1 : n);
				if (maxArea < topArea) maxArea = topArea;
			}
		}
		while (!stck.empty()) {
			temp = stck.top();
			stck.pop();
			topArea = hist[temp] * (!stck.empty() ? n - stck.top() - 1 : n);
			if (maxArea < topArea) maxArea = topArea;
		}
		cout << maxArea << endl;
	}
	return 0;
}