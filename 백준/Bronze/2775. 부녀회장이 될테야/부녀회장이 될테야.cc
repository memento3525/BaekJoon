#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, height, width;
    cin >> t;

    while (cin >> height)
    {
        cin >> width;
        --width;

        int arr[15][14]{};
        for (int i = 0; i <= width; ++i)
            arr[0][i] = i + 1;

        for (int y = 1; y <= height; ++y)
        {
            for (int x = 0; x <= width; ++x)
            {
                int count = 0;
                
                if (x > 0)
                    count += arr[y][x - 1];

                if (y > 0)
                    count += arr[y - 1][x];

                arr[y][x] = count;
            }
        }

        cout << arr[height][width] << '\n';
    }
}