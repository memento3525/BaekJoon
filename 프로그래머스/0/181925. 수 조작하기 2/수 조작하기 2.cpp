#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<int> numLog) {
    string answer = "";
    
    map<int, char> _map = { {+1, 'w'}, {-1, 's'}, {+10, 'd'}, {-10, 'a'} };
    
    int preNum = numLog[0];
    for (int i = 1; i < numLog.size(); ++i)
    {
        int curNum = numLog[i];
        int delta = curNum - preNum;
        preNum = curNum;
        
        if (_map.find(delta) != _map.end())
        {
            char c = _map.at(delta);
            answer.push_back(c);
        }
    }
    
    return answer;
}