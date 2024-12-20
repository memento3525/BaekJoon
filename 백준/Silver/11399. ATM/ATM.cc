#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, temp;
    cin >> n;

    vector<int> v;
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        v.emplace_back(temp);
    }

    sort(v.begin(), v.end());

    int ret = 0;
    int time = 0;
    for (const int& i : v)
    {
        time += i;
        ret += time;
    }

    cout << ret;
}