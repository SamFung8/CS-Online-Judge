#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
	
    int taskNum = 0;
    int maxGroupNum = 0;
    cin >> taskNum;

    while (taskNum > 0) {
        int length = 0;
        int allGroup[30002];
        int mapLocation[30002];
        

        int m = 0, n = 0;
        cin >> n >> m;

        for (int k = 0; k < n; k++) {
            mapLocation[k + 1] = k + 1;
            allGroup[k+1] = 1;
        }


        for (int k = 0; k < m; k++) {
            int f1 = 0, f2 = 0;

            cin >> f1 >> f2;

            int n1, n2;

            n1 = f1;
            n2 = f2;

            while (true) {
                if (mapLocation[f1] != f1) {
                    f1 = mapLocation[f1];
                    mapLocation[n1] = f1;
                    continue;
                }
                if (mapLocation[f2] != f2) {
                    f2 = mapLocation[f2];
                    mapLocation[n2] = f2;
                    continue;
                }
                break;
            }

            if (f1 != f2) {
                allGroup[f1] += allGroup[f2];

                if (length < allGroup[f1]) {
                    length = allGroup[f1];
                }

                mapLocation[f2] = f1;


                
            }

        }



        cout << length;
        cout << "\n";

        taskNum--;
    }

    return 0;
}


