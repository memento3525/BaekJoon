#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    vector<vector<int>> answer;
    
    for (auto it = num_list.begin(); it < num_list.end();)
    {
        answer.push_back(vector<int>(it, it + n));
        it += n;
    }
    
    return answer;
}