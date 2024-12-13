#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int first[26]{};

    string temp;
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        ++first[temp[0] - 'a'];
    }

    bool any = false;
    for (int i = 0; i < 26; ++i)
    {
        if (first[i] >= 5)
        {
            any = true;
            cout << (char)(i + 'a');
        }
    }

    if (!any)
        cout << "PREDAJA";
}