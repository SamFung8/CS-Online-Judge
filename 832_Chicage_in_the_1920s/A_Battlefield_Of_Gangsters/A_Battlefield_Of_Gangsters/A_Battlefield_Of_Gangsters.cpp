#include <iostream>

using namespace std;

int F[1100], E[1100], group[1100];

int find(int num)
{
    if (F[num] == num)
        return num;
    return F[num] = find(F[num]);
}

void unionF(int num1, int num2)
{
    int f1 = find(num1);
    int f2 = find(num2);
    if (f1 != f2)
        F[f1] = f2;
}

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n = 0, m = 0, count = 0;

    cin >> n;
    cin >> m;


    for (int i = 1; i <= n; i++)
        F[i] = i;

    for (int i = 1; i <= m; i++)
    {
        int p = 0, q = 0;
        char type;
        cin >> type >> p >> q;


        if (type == 'F')
            unionF(p, q);

        else{
            if (E[p] == 0)
                E[p] = q;
            else
                unionF(E[p], q);

            if (E[q] == 0)
                E[q] = p;
            else
                unionF(E[q], p);
        }
    }

    for (int i = 1; i <= n; i++)
        group[find(i)] = 1;

    for (int i = 1; i <= n; i++)
        if (group[i] == 1)
            count++;

    cout << count;
    cout << "\n";

    return 0;
}