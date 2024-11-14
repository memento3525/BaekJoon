#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    
    for (const vector<int> v : queries)
    {
        int s = v[0];
        int e = v[1];
        int k = v[2];
        
        int curMin = numeric_limits<int>::max();
        for (int i = s; i <= e; ++i)
        {
            int cur = arr[i];
            if (cur > k && cur < curMin)
            {
                curMin = cur;
            }
        }
        
        int newValue = curMin != numeric_limits<int>::max() ? curMin : -1;
        answer.push_back(newValue);
    }
    
    return answer;
}