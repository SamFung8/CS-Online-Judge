#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
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

        vector <long long int> pile;

        for (int i = 0; i < size; i++) {
            long long int num;
            cin >> num;

            pile.push_back(num);
        }

        int operation;
        cin >> operation;

        for (int i = 0; i < operation; i++) {
            char move;
            cin >> move;

            if(move == 'm'){
                cout << *max_element(pile.begin(), pile.end());
                cout << "\n";
            }
            else if (move == 'a') {
                long long int tem;
                cin >> tem;

                pile.push_back(tem);
            }
            else if (move == 'r') {
                pile.pop_back();
            }
        }

        taskNum--;
    }

    return 0;
}


