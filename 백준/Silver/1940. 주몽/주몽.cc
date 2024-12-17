#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    int temp;
    vector<int>v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        v[i] = temp;
    }

    int count = 0;
    for (int x = 0; x < n; ++x)
    {
        for (int y = x + 1; y < n; ++y)
        {
            if (v[x] + v[y] == m)
                ++count;
        }
    }

    cout << count;
}