#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int taskNum = 0;
    cin >> taskNum;

    while (taskNum > 0) {

        int size = 0;
        cin >> size;


        vector <int> pile;
        for (int i = 0; i < size; i++) {
            char move;
            cin >> move;
            if (move == 'I') {
                char p;
                cin >> p;
                if (p == 'B') {
                    int num;
                    cin >> num;
                    reverse(pile.begin(), pile.end());
                    pile.push_back(num);
                    reverse(pile.begin(), pile.end());
                }
                else {
                    int num;
                    cin >> num;
                    pile.push_back(num);
                }
            }
            else if (move == 'R') {
                char p;
                cin >> p;
                if (p == 'B') {
                    reverse(pile.begin(), pile.end());
                    pile.pop_back();
                    reverse(pile.begin(), pile.end());
                }
                else {
                    pile.pop_back();
                }
            }
            else {
                int num = 0;
                cin >> num;
                reverse(pile.begin(), pile.end());
                cout << pile[num - 1];
                cout << "\n";
                reverse(pile.begin(), pile.end());
            }
        }


        taskNum--;
    }
}

