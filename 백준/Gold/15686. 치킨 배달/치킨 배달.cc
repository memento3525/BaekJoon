#include <iostream>
#include <vector>
using namespace std;

int n, m, temp;
int result = INT16_MAX;
vector<pair<int, int>> house;
vector<pair<int, int>> shop;
vector<pair<int, int>> v;

void CalculateDist()
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

void Combi(int index)
{
    if (v.size() == m)
    {
        CalculateDist();
        return;
    }

    for (int i = index + 1; i < shop.size(); ++i)
    {
        v.push_back(shop[i]);
        Combi(i);
        v.pop_back();
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    house.reserve(n);
    shop.reserve(n * 2);

    for (int y = 0; y < n; ++y)
    {
        for (int x = 0; x < n; ++x)
        {
            cin >> temp;

            if (temp == 1)
                house.push_back({ y, x });
            else if (temp == 2)
                shop.push_back({ y, x });
        }
    }

    Combi(-1);
    cout << result;
}