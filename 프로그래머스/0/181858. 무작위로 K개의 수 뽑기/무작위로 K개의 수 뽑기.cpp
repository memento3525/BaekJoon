#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    
    set<int> mySet;
    vector<int> result;
    
    for (int i : arr)
    {
        if (mySet.find(i) == mySet.end())
        {
            mySet.insert(i);
            result.push_back(i);
            
            --k;
            
            if (k == 0)
                break;
        }
    }
    
    while (k > 0)
    {
        result.push_back(-1);
        --k;
    }
    
    return result;
}