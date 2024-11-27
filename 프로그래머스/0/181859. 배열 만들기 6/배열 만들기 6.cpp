#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> stk;
    
    for (int i = 0; i < arr.size(); ++i)
    {
        if (!stk.empty() && stk.back() == arr[i])
        {
            stk.erase(stk.end() - 1, stk.end());
        }
        else
        {
            stk.push_back(arr[i]);
        }
    }
    
    return stk.empty() ? vector<int>{ -1 } : stk;
}