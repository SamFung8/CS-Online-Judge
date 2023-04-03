#include <stack>
#include <queue>
#include <iostream>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
	
    int taskNum;
    cin >> taskNum;

    while (taskNum > 0) {
        int size;
        cin >> size;
        stack <int> input;

        for (int i = 0; i < size; i++) {
            int num;
            cin >> num;

            input.push(num);
        }

        int testSize;
        cin >> testSize;


        for (int i = 0; i < testSize; i++) {
            queue <int> test;
            stack <int> B;
            stack <int> S;
            stack <int> A = input;

            int num;
            for (int j = 0; j < size; j++) {
                cin >> num;
                test.push(num);
            }

            while (!test.empty()) {
                if (!S.empty()) {
                    if (test.front() == S.top()) {
                        B.push(S.top());
                        S.pop();
                        test.pop();
                        continue;
                    }

                    if (A.empty() && test.front() != S.top()) {
                        break;
                    }
                }

                while (test.front() != A.top()) {
                    S.push(A.top());
                    A.pop();
                    if (A.empty())
                        break;
                }
                if (!A.empty()) {
                    S.push(A.top());
                    A.pop();
                    B.push(S.top());
                    S.pop();
                    test.pop();
                }
            }

            if (A.empty() && S.empty()) {
                cout << "Aye";
                cout << "\n";
            }
            else {
                cout << "Impossible";
                cout << "\n";
            }
        }

        

        taskNum--;
    }
}
