#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int height, width;
    cin >> height >> width;

    int temp;
    bool findFirst = false;
    int firstX, firstY;

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            cin >> temp;
            if (temp == 1)
            {
                if (!findFirst)
                {
                    firstY = y;
                    firstX = x;
                    findFirst = true;
                }
                else
                {
                    cout << abs(firstY - y) + abs(firstX - x) << endl;
                    break;
                }
            }
        }
    }
}