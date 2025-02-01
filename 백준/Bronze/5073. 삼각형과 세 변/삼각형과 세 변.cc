#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> v(3);

    while (true)
    {
        cin >> v[0] >> v[1] >> v[2];

        if (v[0] == 0 && v[1] == 0 && v[2] == 0)
            break;

        sort(v.begin(), v.end());
        if (v[2] >= v[0] + v[1])
        {
            cout << "Invalid" << '\n';
        }
        else if (v[0] == v[2])
        {
            cout << "Equilateral" << '\n';
        }
        else if (v[0] == v[1] || v[1] == v[2])
        {
            cout << "Isosceles" << '\n';
        }
        else 
        {
            cout << "Scalene" << '\n';
        }
    }
}