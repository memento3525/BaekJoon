#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    vector<int> v(3);
    cin >> v[0] >> v[1] >> v[2];
    if (v[0] == 60 && v[1] == 60 && v[2] == 60)
    {
        cout << "Equilateral";
        return 0;
    }
    
    sort(v.begin(), v.end());

    if (v[0] + v[1] + v[2] != 180)
    {
        cout << "Error";
    }
    else if (v[0] == v[1] || v[1] == v[2])
    {
        cout << "Isosceles";
    }
    else
    {
        cout << "Scalene";
    }
}