#include <iostream>
#include <vector>
using namespace std;

int height, width, maxSum = 0;
int map[4][4];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> height >> width;

    string str;
    for (int y = 0; y < height; ++y)
    {
        cin >> str;
        for (int x = 0; x < width; ++x)
            map[y][x] = str[x] - '0';
    }

    for (int mask = 0; mask < (1 << height * width); ++mask)
    {
        int sum = 0;

        // 가로합
        for (int y = 0; y < height; ++y)
        {
            int cur = 0;
            for (int x = 0; x < width; ++x)
            {
                int k = (y * width + x);
                if ((mask & (1 << k)) == 0)
                {
                    cur = cur * 10 + map[y][x];
                }
                else
                {
                    sum += cur;
                    cur = 0;
                }
            }

            // 남은 숫자 더함
            sum += cur;
        }

        // 세로합
        for (int x = 0; x < width; ++x)
        {
            int cur = 0;
            for (int y = 0; y < height; ++y)
            {
                int k = (y * width + x);
                if ((mask & (1 << k)) != 0)
                {
                    cur = cur * 10 + map[y][x];
                }
                else
                {
                    sum += cur;
                    cur = 0;
                }
            }

            // 남은 숫자 더함
            sum += cur;
        }

        if (sum > maxSum)
            maxSum = sum;
    }

    cout << maxSum;
}