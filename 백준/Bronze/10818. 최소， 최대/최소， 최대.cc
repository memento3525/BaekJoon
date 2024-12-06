#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    vector<int> v;
    int r;
    for (int i = 0; i < n; ++i)
    {
        cin >> r;
        v.emplace_back(r);
    }

    auto minIt = std::min_element(v.begin(), v.end());
    auto maxIt = std::max_element(v.begin(), v.end());

    cout << *minIt << ' ' << *maxIt;
}