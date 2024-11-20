#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> intervals) {
    vector<int> answer;
    
    for (int i = 0; i < intervals.size(); ++i)
    {
        auto start = arr.begin() + intervals[i][0];        
        auto end = arr.begin() + intervals[i][1] + 1;        
        
        answer.insert(answer.end(), start, end);
    }
    
    return answer;
}