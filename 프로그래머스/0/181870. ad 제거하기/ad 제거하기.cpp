#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strArr) {
    vector<string> answer;
    
    for (const string& str : strArr)
    {
        size_t pos = str.find("ad");
        if (pos == std::string::npos)
            answer.push_back(str);
    }
    
    return answer;
}