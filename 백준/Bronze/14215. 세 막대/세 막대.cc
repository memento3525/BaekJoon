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
    cin >> v[0] >> v[1] >> v[2];
    
    sort(v.begin(), v.end());

    if (v[2] >= v[0] + v[1])
        v[2] = v[0] + v[1] - 1;

    cout << (v[0] + v[1] + v[2]);
}