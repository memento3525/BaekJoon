#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
void Combi(vector<int> v, int start);

const int n = 9;
const int m = 7;
int arr[n];
bool finded = false;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
        
    vector<int> v;
    Combi(v, -1);

    return 0;
}

void Combi(vector<int> v, int start)
{
    if (finded) return;
    
    if (v.size() == m)
    {
        int sum = 0;
        for (int i = 0; i < m; ++i)
            sum += arr[v[i]];

        if (sum == 100)
        {
            vector<int> result;
            for (const int& i : v)
                result.push_back(arr[i]);

            sort(result.begin(), result.end());

            for (const int& i : result)
                cout << i << "\n";

            finded = true;
            return;
        }

        return;
    }

    for (int i = start + 1; i < n; ++i)
    {
        v.push_back(i);
        Combi(v, i);
        v.pop_back();
    }
}