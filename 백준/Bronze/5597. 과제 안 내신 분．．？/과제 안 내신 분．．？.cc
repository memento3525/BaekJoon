#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    int nums[31]{};
    int n;
    while (cin >> n)
        nums[n]++;
    
    for(int i = 1; i < 31; ++i)
    {
        if (nums[i] == 0)
            cout << i << '\n';
    }
}
