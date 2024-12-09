#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    
    int temp;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        v[i] = temp;
    }

    sort(v.begin(), v.end(), greater<int>());
 
    float sum = 100.0f;
    float max = v[0];
    for (int i = 1; i < n; ++i)
    {
        sum += v[i] / max * 100.0f;
    }

    cout << sum / n;
}