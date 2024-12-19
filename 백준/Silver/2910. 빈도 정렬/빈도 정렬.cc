#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, c;
    cin >> n >> c;

    unordered_map<int, int> map;
    unordered_map<int, int> map_first;

    int temp;
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;

        if (map_first[temp] == 0)
            map_first[temp] = i + 1;

        ++map[temp];
    }

    vector<pair<int, int>> sortV;
    for (const auto& item : map)
    {
        sortV.emplace_back(item.first, item.second);
    }

    sort(sortV.begin(), sortV.end(), [&](const pair<int, int>& a, const pair<int, int>& b)
        {
            if (a.second == b.second)
                return map_first[a.first] < map_first[b.first];

            return (a.second > b.second);
        });

    for (const auto& item : sortV)
    {
        for (int i = 0; i < item.second; ++i)
        {
            cout << item.first << ' ';
        }
    }
}