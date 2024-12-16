#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unordered_map<int, string> mapI;
    unordered_map<string, int> mapS;

    int n, k;
    cin >> n >> k;

    string temp;
    for (int i = 1; i <= n; ++i)
    {
        cin >> temp;
        mapI[i] = temp;
        mapS[temp] = i;
    }

    for (int i = 0; i < k; ++i)
    {
        cin >> temp;

        if (isdigit(temp[0]))
        {
            int number = stoi(temp);
            cout << mapI[number] << '\n';
        }
        else
        {
            cout << mapS[temp] << '\n';
        }
    }
}