#include <iostream>
#include <vector>
using namespace std;

int t;
string s;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (cin >> s)
    {
        if (s == "0") break;

        ++t;

        bool isLast = false;
        string curStr = s;
        while (!isLast)
        {
            if (curStr == "22" || curStr.size() & 1)
                break;

            // 짝수항이 연속해서 나오는 경우는 잘못된 문자다.
            char prevChar = ' ';
            for (int i = 1; i < curStr.size(); i += 2)
            {
                if (prevChar == curStr[i])
                    break;

                prevChar = curStr[i];
            }

            string makeStr = "";
            int prev = ' ';
            for (int i = 0; i < curStr.size(); i += 2)
            {
                int cnt = curStr[i] - '0';
                char c = curStr[i + 1];

                if (prev == c)
                {
                    curStr = makeStr;
                    isLast = true;
                    break;
                }

                prev = c;
                makeStr += string(cnt, c);
            }

            curStr = makeStr;
        }

        cout << "Test " << t << ": " << curStr << '\n';
    }
}