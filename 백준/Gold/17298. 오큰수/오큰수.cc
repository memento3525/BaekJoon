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
    vector<int> v(n);
    vector<int> ret(n);
    vector<int> stack; // index

    for (int i = 0; i < n; ++i)
    {
        ret[i] = -1;
        cin >> v[i];

        while (!stack.empty() && (v[stack.back()] < v[i]))
        {
            ret[stack.back()] = v[i];
            stack.pop_back();
        }

        stack.push_back(i);
    }

    for (const int& i : ret)
        cout << i << ' ';
}