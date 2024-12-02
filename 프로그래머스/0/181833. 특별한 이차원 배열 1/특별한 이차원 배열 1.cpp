#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
    
    vector<vector<int>> answer;
    
    for (int i = 0; i < n; ++i)
    {
        vector<int> v;
        
        for (int k = 0; k < n; ++k)
            v.push_back(i == k);
        
        answer.push_back(v);
    }
    
    return answer;
}