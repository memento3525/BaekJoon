#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string s) {
    
    map<char, int> _map;
    
    for (char c : s)
        ++_map[c];
    
    string answer = "";
    for (const auto& pair : _map)
    {
        if (pair.second == 1)
            answer += pair.first;
    }
    
    return answer;
}