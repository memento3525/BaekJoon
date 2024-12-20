#include <iostream>
#include <string>
using namespace std;

void PrintNum(int n)
{
    int m = n / 60;
    int s = n % 60;

    if (m < 10) cout << '0';

    cout << m << ":";

    if (s < 10) cout << '0';
    cout << s;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int score[2]{ 0, 0 };
    int winTimeSpan[2]{};

    int goalTeam = -1;
    string timeStr;

    int prevTime = 0;
    for (int i = 0; i <= n; ++i)
    {
        int curTime;

        if (i != n)
        {
            cin >> goalTeam >> timeStr;

            string min = string(timeStr.begin(), timeStr.begin() + 2);
            int m = stoi(min);

            string second = string(timeStr.begin() + 3, timeStr.end());
            int s = stoi(second);

            curTime = m * 60 + s;
        }
        else
        {
            goalTeam = -1;
            curTime = 48 * 60;
        }

        if (score[0] > score[1])
        {
            winTimeSpan[0] += (curTime - prevTime);
        }
        else if (score[0] < score[1])
        {
            winTimeSpan[1] += (curTime - prevTime);
        }

        if (goalTeam != - 1)
            ++score[goalTeam - 1];
        
        prevTime = curTime;
    }

    PrintNum(winTimeSpan[0]);
    cout << '\n';
    PrintNum(winTimeSpan[1]);
}