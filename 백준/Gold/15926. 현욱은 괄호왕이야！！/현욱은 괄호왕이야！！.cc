#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    string s;
    cin >> n >> s;

    vector<int> valid(n);
    vector<int> stack;

    int index = 0;
    for (char c : s)
    {
        if (c == '(')
        {
            stack.push_back(index);
        }
        else if (stack.size())
        {
            valid[index] = 1;
            valid[stack.back()] = 1;
            stack.pop_back();
        }

        ++index;
    }

    int max = 0;
    int cur = 0;
    for (int i : valid)
    {
        if (i == 1)
        {
            ++cur;
        }
        else
        {
            if (cur > max)
                max = cur;
            cur = 0;
        }
    }

    if (cur > max)
        max = cur;

    cout << max;
}