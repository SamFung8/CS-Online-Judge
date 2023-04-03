// 8404(Hard_ver).cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

long long int arr[10000000];

void generateArray(long long int* arr, long long int n, long long int m, long long int seed) {
    unsigned x = seed;
    for (long long int i = 0; i < n; i++) {
        x ^= x << 13;
        x ^= x >> 17;
        x ^= x << 5;
        arr[i] = x % m + 1;
    }
}



int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    long long int size = 0;
    long long int endSize = 0;
    long long int num = 0;
    long long int seekNum = 0;

    priority_queue<long long int> pq;

    cin >> size;
    cin >> num;
    cin >> seekNum;


    generateArray(arr, size, num, seekNum);

    for (long long int i = 0; i < size; i++) {
        pq.push((-1) * arr[i]);
    }

    while (size > 1) {
        long long int num1 = (pq.top()) * (-1);
        pq.pop();
        long long int num2 = (pq.top()) * (-1);
        pq.pop();
        num2 = num1;
        pq.push((-1) * (num1 + num2));
        size--;
    }

    cout << (pq.top() * -1);
    cout << "\n";


    return 0;

}

