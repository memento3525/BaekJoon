#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_string) {
    
    vector<string> answer;
    int lastPos = 0;
    for (int i = 0; i <= my_string.size(); ++i)
    {
        if (i == my_string.size() || my_string[i] == ' ')
        {
            string newStr = string(my_string.begin() + lastPos, my_string.begin() + i);
            answer.push_back(newStr);
            lastPos = i + 1;
        }
    }
    
    return answer;
}