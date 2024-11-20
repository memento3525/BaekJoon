#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    
    auto it = std::find(arr.begin(), arr.end(), 2);
    if (it == arr.end())
    {
        return vector<int>{ -1 };
    }
    
    auto r_it = std::find(arr.rbegin(), arr.rend(), 2);
    auto r_baseit = r_it.base();
    
    return vector<int>(it, r_baseit);
}