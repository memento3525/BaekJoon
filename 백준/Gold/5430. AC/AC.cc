#include <iostream>
#include <sstream>
#include <deque>
#include <algorithm>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;
    string p, str, temp;
    deque<int> v;

    cin >> t;
    for (int y = 0; y < t; ++y)
    {
        cin >> p >> n >> str;

        str = string(str.begin() + 1, str.end() - 1);
        stringstream ss(str);

        v.resize(n);
        for (int x = 0; x < n; ++x)
        {
            getline(ss, temp, ',');
            v[x] = stoi(temp);
        }

        bool isFront = true;
        bool isError = false;
        for (char c : p)
        {
            if (c == 'R')
            {
                isFront = !isFront;
            }
            else if (c == 'D')
            {
                if (v.empty())
                {
                    isError = true;
                    break;
                }

                if (isFront)
                    v.pop_front();
                else
                    v.pop_back();
            }
        }

        if (isError)
        {
            cout << "error" << '\n';
        }
        else
        {
            cout << '[';

            if (v.size() >= 1)
            {
                if (!isFront)
                    reverse(v.begin(), v.end());

                auto it = v.begin();
                while (true)
                {
                    cout << *it;
                    ++it;
                    if (it == v.end()) break;
                    cout << ',';
                }
            }

            cout << ']' << '\n';
        }
    }
}