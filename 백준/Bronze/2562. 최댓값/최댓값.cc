#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    vector<int> nums;
    for (int i = 0; i < 9; ++i)
    {
        int temp;
        cin >> temp;
        nums.emplace_back(temp);
    }

    auto it = std::max_element(nums.begin(), nums.end());
    cout << *it << '\n' << it - nums.begin() + 1;
}