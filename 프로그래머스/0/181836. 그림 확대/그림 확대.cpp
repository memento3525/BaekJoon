#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> picture, int k) {
    vector<string> answer;
    
    for (const string& picStr : picture)
    {
        string str;
        
        for (const char& c : picStr)
        {
            for (int x = 0; x < k; ++x)
                str += c;            
        }
        
        for (int y = 0; y < k; ++y)
            answer.push_back(str);
    }

    return answer;
}