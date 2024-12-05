#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> v;

    for (int i = 0; i < n; ++i)
        v.push_back(vector<int>(m));

    int temp;

    for (int i = 0; i < 2; ++i)
    {
        for (int y = 0; y < n; ++y)
        {
            for (int x = 0; x < m; ++x)
            {
                cin >> temp;
                v[y][x] += temp;
            }
        }
    }

    for (int y = 0; y < n; ++y)
    {
        for (int x = 0; x < m; ++x)
        {
            if (x != 0)
                cout << ' ';

            cout << v[y][x];
        }

        cout << '\n';
    }
}
