#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> v(3);
    for (int i = 1; i <= n; ++i)
    {
        cin >> v[0] >> v[1] >> v[2];

        sort(v.begin(), v.end());

        bool isCorrect = (v[0] * v[0] + v[1] * v[1]) == (v[2] * v[2]);
        
        cout << "Scenario #" << i << ":" << '\n';
        cout << (isCorrect ? "yes" : "no") << '\n' << '\n';
    }
}