#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> v(3);

    for (int i = 0; i < n; ++i)
    {
        cout << "Case #" << (i + 1) << ": ";

        cin >> v[0] >> v[1] >> v[2];

        sort(v.begin(), v.end());
        if (v[2] >= v[0] + v[1])
        {
            cout << "invalid!" << '\n';
        }
        else if (v[0] == v[2])
        {
            cout << "equilateral" << '\n';
        }
        else if (v[0] == v[1] || v[1] == v[2])
        {
            cout << "isosceles" << '\n';
        }
        else 
        {
            cout << "scalene" << '\n';
        }
    }
}