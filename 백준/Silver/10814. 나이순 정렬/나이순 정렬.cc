#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int age;
    string name;

    vector<string> v(201);
    for (int i = 0; i < n; ++i)
    {
        cin >> age;
        cin >> name;
        
        if (v[age].empty())
            v[age] = to_string(age) + " " + name;
        else
            v[age] += '\n' + to_string(age) + " " + name;
    }

    for (const string& str : v)
    {
        if (str.empty()) continue;
        cout << str << '\n';
    }
}