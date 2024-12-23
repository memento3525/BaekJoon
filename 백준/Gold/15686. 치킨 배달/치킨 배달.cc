#include <iostream>
#include <vector>
using namespace std;

int n, m, temp;
vector<vector<int>> map;
vector<pair<int, int>> house;
vector<pair<int, int>> shop;

int result = INT16_MAX;

void CalculateDist(vector<pair<int, int>>& v)
{
    int sum = 0;
    for (const auto& h : house)
    {
        int shortest = INT16_MAX;
        for (const auto& s : v)
        {
            int curDist = abs(h.first - s.first) + abs(h.second - s.second);
            if (curDist < shortest)
                shortest = curDist;
        }

        sum += shortest;
    }

    if (sum < result)
        result = sum;
}

void Combi(vector<pair<int, int>>& v, int index)
{
    if (v.size() == m)
    {
        CalculateDist(v);
        return;
    }

    for (int i = index + 1; i < shop.size(); ++i)
    {
        v.push_back(shop[i]);
        Combi(v, i);
        v.pop_back();
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    map.resize(n);

    for (int i = 0; i < n; ++i)
    {
        map[i] = vector<int>(n);

        for (int k = 0; k < n; ++k)
        {
            cin >> temp;
            map[i][k] = temp;

            if (temp == 1)
                house.push_back({ i, k });
            else if (temp == 2)
                shop.push_back({ i, k });
        }
    }

    vector<pair<int, int>> v;
    Combi(v, -1);

    cout << result;
}