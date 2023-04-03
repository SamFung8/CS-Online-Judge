#include <algorithm>
#include <set>
#include <vector>
#include <iostream>
using namespace std;
#define mod (int)(1e9 + 7)

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    //this vector will store the rank of each station
    vector<int> station_rank(n + 1, 1);
    for (int i = 0; i < m; i++)
    {
        int cnt;
        cin >> cnt;
        //for a given train this vector  will store its stopping stations
        vector<int> stopping_stations(cnt);
        for (auto& station : stopping_stations)
            cin >> station;

        //this variable is a pointer on the stopping_stations array
        int track = 0;
        //this is maximum value for a station on which we don't have to stop
        int max_value = 0;
        for (int j = stopping_stations[0]; j <= stopping_stations[cnt - 1]; j++)
        {
            if (track < cnt && j == stopping_stations[track])
            {
                track++;
                continue;
            }
            max_value = max(max_value, station_rank[j]);
        }

        //now that we have calculated max_value
        //we will make sure that all the stations have the value greater than this max_value
        //so that the train does not stop on any other location
        for (int i = 0; i < cnt; i++)
        {
            int station = stopping_stations[i];
            station_rank[station] = max(station_rank[station], max_value + 1);
        }
    }

    //now we will create a set to hold the unique ranks 
    set<int> unique_rank;
    for (int i = 0; i <= n; i++) unique_rank.insert(station_rank[i]);
    //the size of this set will give us the number of unique ranks
    cout << unique_rank.size();
}