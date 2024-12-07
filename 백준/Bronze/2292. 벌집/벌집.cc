#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int i = 0;
    int sum = 1;
    while (true)
    {
        sum += 6 * i;
        
        if (n <= sum)
            break;

        ++i;
    }

    cout << i + 1;
}