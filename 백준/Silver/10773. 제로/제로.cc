#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int temp;
    vector<int> v;
    for(int i = 0; i < n; ++i)
    {
        cin >> temp;
        if (temp == 0)
        {
            v.pop_back();
        }
        else
        {
            v.emplace_back(temp);
        }
    }

    int result = accumulate(v.begin(), v.end(), 0);
    cout << result;
}