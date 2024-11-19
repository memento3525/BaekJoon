#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string, vector<int> indices) {
    
    std::sort(indices.begin(), indices.end());
    
    string answer = "";
    
    int index = 0;
    for (int i = 0; i < my_string.size(); ++i)
    {
        if (index < indices.size())
        {
            if (indices[index] == i)
            {
                ++index;
                continue;
            }
        }
        
        answer += my_string[i];
    }
    
    return answer;
}