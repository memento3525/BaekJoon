#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int result = 0;
    string str;
    vector<char> v;
    for (int i = 0; i < n; ++i)
    {
        v.clear();
        cin >> str;

        for (const char& c : str)
        {
            if (!v.empty() && v.back() == c)
            {
                v.pop_back();
                continue;
            }

            v.emplace_back(c);
        }

        if (v.size() == 0)
            ++result;
    }

    cout << result;
}