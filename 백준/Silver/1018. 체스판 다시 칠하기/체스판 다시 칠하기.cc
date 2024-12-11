#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int height, width;
    cin >> height >> width;

    vector<vector<bool>> v;

    char mark[2] = { 'W', 'B' };

    string line;
    for (int y = 0; y < height; ++y)
    {
        v.push_back(vector<bool>(width));

        cin >> line;
        for (int x = 0; x < width; ++x)
        {
            int markIndex = (x + y) % 2;
            v[y][x] = (line[x] == mark[markIndex]);
        }
    }

    int minValue = 99999999999;
    for (int startY = 0; startY <= height - 8; ++startY)
    {
        for (int startX = 0; startX <= width - 8; ++startX)
        {
            int count = 0;

            for (int y = startY; y < startY + 8; ++y)
            {
                for (int x = startX; x < startX + 8; ++x)
                {
                    if (!v[y][x])
                        ++count;
                }
            }

            minValue = min(minValue, count);
            minValue = min(minValue, 64 - count); // 반전은 64개에서 최대값을 뺀 값
        }
    }

    cout << minValue;
}