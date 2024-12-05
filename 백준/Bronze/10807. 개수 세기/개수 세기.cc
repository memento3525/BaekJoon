#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    vector<int> myVector;
    for (int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;

        myVector.push_back(temp);
    }

    int v;
    cin >> v;

    int count = std::count(myVector.begin(), myVector.end(), v);
    cout << count;
}
