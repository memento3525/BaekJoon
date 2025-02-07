#include <iostream>
using namespace std;

double r[5]{ 3 * 3, 6 * 6, 9 * 9, 12 * 12, 15 * 15 };
int score[5]{ 100, 80, 60, 40, 20 };

int GetScore(double x, double y)
{
    double dd = x * x + y * y;

    for (int i = 0; i < 5; ++i)
    {
        double cut = r[i];
        if (dd <= cut)
            return score[i];
    }

    return 0;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    double x, y;
    while (t--)
    {
        int a = 0;
        int b = 0;

        for (int i = 0; i < 3; ++i)
        {
            cin >> x >> y;
            a += GetScore(x, y);
        }

        for (int i = 0; i < 3; ++i)
        {
            cin >> x >> y;
            b += GetScore(x, y);
        }

        cout << "SCORE: " << a << " to " << b << ", ";

        if (a == b)
            cout << "TIE." << '\n';
        else if (a > b)
            cout << "PLAYER 1 WINS." << '\n';
        else if (a < b)
            cout << "PLAYER 2 WINS." << '\n';
    }
}