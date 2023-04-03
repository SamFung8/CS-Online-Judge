#include <iostream>
#include<queue>
using namespace std;

int main()
{
    int taskNum = 0;

    while (cin >> taskNum) {
        queue <int> line;
        while (taskNum > 0) {
            int arrivedTime = 0, peopleNum = 0;
            cin >> arrivedTime >> peopleNum;
            line.push(arrivedTime);

            for (int i = 0; i < peopleNum; i++) {

            }

            taskNum--;
        }
    }
}
