#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    vector<int> v(3);
    cin >> v[0] >> v[1] >> v[2];

    sort(v.begin(), v.end());

    if (v[0] == v[1] && v[1] == v[2])
        cout << 2;
    else if (v[2] * v[2] == v[0] * v[0] + v[1] * v[1])
        cout << 1;
    else
        cout << 0;
}