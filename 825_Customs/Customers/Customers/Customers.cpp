#include <iostream>
#include<queue>
#include <unordered_map>
#include <set>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
	
    vector <int> output;
    int taskNum = 0;
    
    while (cin >> taskNum) {
        queue <int> queueTime;
        queue <vector <int>> allP;
        set <int> currentP;
        unordered_map <int, int> m;

        while (taskNum--) {

            int time;
            int size;
            cin >> time >> size;

            while (!queueTime.empty()) {
                int t;
                t = queueTime.front();
                if ((time - t) >= 86400) {
                    queueTime.pop();
                    vector <int> tem = allP.front();
                    allP.pop();
                    for(int i =0;i<tem.size();i++){
                        m[tem[i]]--;
                        if(m[tem[i]] == 0)
                            currentP.erase(tem[i]);
                    }                        
                }
                else
                    break;
            }

            queueTime.push(time);

            vector <int> tem;
            for (int i = 0; i < size; i++) {
                int p;
                cin >> p;

                currentP.insert(p);
                tem.push_back(p);
                m[p]++;
            }

            allP.push(tem);
            output.push_back(currentP.size());
        }

        for (int i = 0; i < output.size(); i++) {
            cout << output[i];
            cout << "\n";
        }


        output.clear();
        while (!queueTime.empty()) {
            queueTime.pop();
        }
    }
}
