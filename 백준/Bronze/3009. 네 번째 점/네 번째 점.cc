#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(void)
{
    map<int, int> mapX;
    map<int, int> mapY;

    int x, y;
    for (int i = 0; i < 3; ++i)
    {
        cin >> x >> y;
        mapX[x]++;
        mapY[y]++;
    }

    for (const auto& item : mapX)
    {
        if (item.second == 1)
            cout << item.first << ' ';
    }

    for (const auto& item : mapY)
    {
        if (item.second == 1)
            cout << item.first;
    }
}