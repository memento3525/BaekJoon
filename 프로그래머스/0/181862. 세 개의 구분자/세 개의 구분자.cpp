#include <string>
#include <vector>

using namespace std;

vector<string> solution(string myStr) {
    
    vector<string> answer;
    
    int length = 0;
    for (int i = 0; i <= myStr.size(); ++i)
    {
        if (i == myStr.size() || myStr[i] == 'a' || myStr[i] == 'b' || myStr[i] == 'c')
        {
            if (length > 0)
            {
                string str = myStr.substr(i - length, length);
                answer.push_back(str);
                length = 0;
            }
        }
        else
        {
            length++;
        }
    }
    
    if (answer.empty())
        answer.push_back("EMPTY");
    
    return answer;
}