#include <iostream>
#include <set>

using namespace std;

int main(void)
{
    set<int> mySet;
    
    int n = 0;
    while (cin >> n)
        mySet.insert(n % 42);
    
    cout << mySet.size();
}