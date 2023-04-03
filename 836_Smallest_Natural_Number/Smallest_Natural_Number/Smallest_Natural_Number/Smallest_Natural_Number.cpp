#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
	
    long long int size;
    unordered_map <long long int, int> map;

    while (cin >> size) {

        for (int i = 0; i < size; i++){
            long long int num;
            cin >> num;
            map[num] = 0;
        }


        long long int counter = 0;
        long long int minCounter = 0;
        while (true) {
            if (map.find(counter) != map.end()) 
                counter++;
            else {
                minCounter = counter;
                break;
            }
        }
        cout << minCounter;
        cout << "\n";

        map.clear();
    }

    return 0;
}
