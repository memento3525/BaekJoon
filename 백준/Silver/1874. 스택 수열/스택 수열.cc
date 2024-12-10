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

    vector<int> v;
    vector<char> result;
    int target = 0;
    int current = 1;
    for (int i = 0; i < n; ++i)
    {
        cin >> target;

        while (v.empty() || v.back() < target)
        {
            v.emplace_back(current);
            result.emplace_back('+');
            ++current;
        }

        if (v.empty() || v.back() != target)
        {
            cout << "NO";
            return 0;
        }

        result.emplace_back('-');
        v.pop_back();
    }

    for (const char& c : result)
        cout << c << '\n';
}