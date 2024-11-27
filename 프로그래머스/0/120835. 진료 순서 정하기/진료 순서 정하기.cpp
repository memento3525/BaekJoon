#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> emergency) {
    vector<int> answer = vector<int>(emergency.size(), 1);
    
    for (int i = 0; i < emergency.size(); ++i)
    {
        for (int k : emergency)
        {
            if (emergency[i] < k)
                answer[i]++;
        }
    }
    
    return answer;
}