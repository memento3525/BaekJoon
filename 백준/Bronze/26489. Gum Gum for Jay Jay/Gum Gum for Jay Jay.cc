#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count = 0;

    string temp;
    while (cin >> temp)
    {
        ++count;
    }

    cout << count / 5;
}