#include <iostream>
#include <algorithm>
#include <string>
#include <algorithm>
#include<vector>

using namespace std;

long long int counter[10000001];
vector <long long int> tem[5000000];


long long int generateArray(long long int n, long long int m, long long int seed) {
    unsigned x = seed;
    long long int num = -1;
    long long int temNum;
    for (long long int i = 0; i < n; i++) {
        x ^= x << 13;
        x ^= x >> 17;
        x ^= x << 5;
        temNum = x % m + 1;
        counter[temNum]++;
        if (num == -1 || temNum < num)
            num = temNum;
    }
    return num;
}




int main()
{
    long long int size = 0;
    long long int num = 0;
    long long int seekNum = 0;


    cin >> size;
    cin >> num;
    cin >> seekNum;

    long long int min = generateArray(size, num, seekNum);


    long long int overCount = 0;
    long long int overCountNum = 0;
    long long int overCountSize = -1;

    for (long long int i = size; i > 1; i--) {
        long long int num1 = min + (overCount * 10000000);
        counter[min]--;

        while (true) {
            if (10000000 < min || overCountSize == 0) {
                overCount++;
                while (tem[overCount].size() == 0)
                    overCount++;
                overCountSize = tem[overCount].size();

                for (long long int j = 0; j < tem[overCount].size(); j++) {
                    counter[tem[overCount][j]]++;
                }
                overCountNum = 0;
                min = tem[overCount][overCountNum];
                overCountNum++;
                overCountSize--;
                break;
            }

            if (overCount > 0) {
                min = tem[overCount][overCountNum];
                overCountNum++;
                overCountSize--;
                break;
            }
            else {
                if (counter[min] == 0) {
                    min++;
                }
                else
                    break;
            }
        }

        long long int num2 = min + (overCount * 10000000);
        counter[min]--;
        num2 = num1;

        if ((num1 + num2) <= (10000000 + (overCount * 10000000))) {
            if ((num1 + num2) % 10000000 == 0)
                counter[10000000]++;
            else
                counter[(num1 + num2) % 10000000]++;

            if (min > (num1 + num2) % 10000000)
                min = (num1 + num2) % 10000000;

            if (overCount != 0) {
                overCountSize++;
                tem[overCount].push_back((num1 + num2) % 10000000);
                sort(tem[overCount].begin(), tem[overCount].end());
            }
        }
        else {
            long long int num = (long long int)(num1 + num2) / 10000000;
            tem[num].push_back((num1 + num2) % 10000000);
        }

        while (true) {
            if (10000000 < min || overCountSize == 0) {
                overCount++;
                while (tem[overCount].size() == 0)
                    overCount++;
                overCountSize = tem[overCount].size();

                for (long long int j = 0; j < tem[overCount].size(); j++) {
                    counter[tem[overCount][j]]++;
                }
                overCountNum = 0;
                min = tem[overCount][overCountNum];
                overCountNum++;
                overCountSize--;
                break;
            }

            if (overCount > 0) {
                min = tem[overCount][overCountNum];
                overCountNum++;
                overCountSize--;
                break;
            }
            else {
                if (counter[min] == 0) {
                    min++;
                }
                else
                    break;
            }
        }
    }



    cout << min + (10000000 * overCount);
    cout << "\n";



    return 0;

}