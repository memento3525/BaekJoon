#include <iostream>
using namespace std;

int main(void)
{
    int a, b, c;
    cin >> a >> b >> c;

    int mult = a * b * c;
    
    int nums[10]{};
    while (mult != 0)
    {
        nums[mult % 10]++;
        mult /= 10;
    }

    for (int i : nums)
        cout << i << '\n';
}