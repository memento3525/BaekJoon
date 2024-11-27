#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<bool> flag) {
    vector<int> answer;
    
    for (int i = 0; i < arr.size(); ++i)
    {
        int n = arr[i];
        if (flag[i])
        {
            answer.insert(answer.end(), n * 2, n);
        }
        else
        {
            answer.erase(answer.end() - n, answer.end());
        }
    }
    
    return answer;
}