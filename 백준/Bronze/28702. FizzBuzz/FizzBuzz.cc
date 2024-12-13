#include <iostream>
#include <string>
using namespace std;

void PrintFizzBuzz(int n)
{
    if (n % 3 == 0)
        cout << "Fizz";

    if (n % 5 == 0)
        cout << "Buzz";
    else
    {
        if (n % 3 != 0)
            cout << n;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int offset = 3;
    string cur;

    for (int i = 0; i < 3; ++i)
    {
        cin >> cur;

        if (isdigit(cur[0]))
        {
            PrintFizzBuzz(std::stoi(cur) + offset);
            break;
        }

        --offset;
    }
}