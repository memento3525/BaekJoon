#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    int nums[26]{};
    for (const char& c : str)
    {
        ++nums[c - 'a'];
    }

    for (int n : nums)
    {
        cout << n << " ";
    }
}