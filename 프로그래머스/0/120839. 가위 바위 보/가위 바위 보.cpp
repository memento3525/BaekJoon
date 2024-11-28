#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string rsp) {
    string answer = "";
    
    map<char, char> map = { {'2', '0'}, {'0', '5'}, {'5', '2'} };
    
    for (const char& c : rsp)
    {
        answer += map[c];
    }
    
    return answer;
}