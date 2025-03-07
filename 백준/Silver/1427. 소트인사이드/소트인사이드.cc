#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    string s;
    cin >> s;

    vector<char> v;
    for (const char& c : s)
        v.push_back(c);

    sort(v.begin(), v.end(), greater<char>());

    for (const char& c : v)
        cout << c;
}