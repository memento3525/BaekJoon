#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    
    stringstream ss;
    int x, y, z;
    char op1, op2;
    for (const string& line : quiz)
    {
        ss.str(line);
        
        ss >> x >> op1 >> y >> op2 >> z;
        if (op1 == '+')
        {
            answer.emplace_back((x + y == z) ? "O" : "X");
        }
        else // -
        {
            answer.emplace_back((x - y == z) ? "O" : "X");
        }
        
        ss.clear();
    }
    
    return answer;
}