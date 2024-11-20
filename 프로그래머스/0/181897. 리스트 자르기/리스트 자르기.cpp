#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> slicer, vector<int> num_list) {
    vector<int> answer;

    int start = (n == 1) ? 0 : slicer[0];
    int end = (n == 2) ? num_list.size() - 1 : slicer[1];
    int interval = (n == 4) ? slicer[2] : 1;
    
    for (int i = start; i <= end; i += interval)
    {
        answer.push_back(num_list[i]);
    }
    
    return answer;
}