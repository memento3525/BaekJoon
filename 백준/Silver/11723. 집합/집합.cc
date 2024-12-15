#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    string method;
    int num;

    bool s[21]{};

    for (int i = 0; i < n; ++i)
    {
        cin >> method;

        if (method == "add")
        {
            cin >> num;
            s[num] = true;
        }
        else if (method == "remove")
        {
            cin >> num;
            s[num] = false;
        }
        else if (method == "check")
        {
            cin >> num;
            cout << (s[num] ? 1 : 0) << '\n';
        }
        else if (method == "toggle")
        {
            cin >> num;
            s[num] = !s[num];
        }
        else if (method == "all")
        {
            for (int i = 1; i <= 20; ++i)
                s[i] = true;
        }
        else if (method == "empty")
        {
            for (int i = 1; i <= 20; ++i)
                s[i] = false;
        }
    }
}