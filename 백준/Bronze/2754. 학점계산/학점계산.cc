#include <iostream>
using namespace std;

int main(void)
{
    string str;
    cin >> str;

    if (str[0] == 'F')
    {
        cout << "0.0";
        return 0;
    }

    int score = 0;
    if (str[0] == 'A')
    {
        score = 37;
    }
    else if (str[0] == 'B')
    {
        score = 27;
    }
    else if (str[0] == 'C')
    {
        score = 17;
    }
    else if (str[0] == 'D')
    {
        score = 07;
    }

    if (str[1] == '+')
    {
        score += 6;
    }
    else if (str[1] == '0')// 0
    {
        score += 3;
    }

    cout << score / 10 << '.' << score % 10;
}