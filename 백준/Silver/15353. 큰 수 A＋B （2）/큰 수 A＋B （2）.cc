#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a, b;
    cin >> a >> b;

    if (a.size() < b.size())
        swap(a, b);

    string ret;

    auto itA = a.rbegin();
    auto itB = b.rbegin();

    int next = 0;
    while (itB != b.rend())
    {
        int numA = (*itA - '0');
        int numB = (*itB - '0');

        int sum = numA + numB + next;

        if (sum > 9)
            next = 1;
        else
            next = 0;

        ret += ((sum % 10) + '0');

        ++itA;
        ++itB;
    }

    while (itA != a.rend())
    {
        int numA = (*itA - '0');
        int sum = numA + next;

        if (sum > 9)
            next = 1;
        else
            next = 0;

        ret += ((sum % 10) + '0');
        ++itA;
    }

    if (next > 0)
        ret += (next + '0');

    cout << string(ret.rbegin(), ret.rend());
}