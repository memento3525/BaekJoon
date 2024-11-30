#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string a, string b) {
    
    auto itA = a.rbegin();
    auto itB = b.rbegin();
    
    string answer = "";
    int remained = 0;
    while (itA != a.rend() || itB != b.rend())
    {
        int sum = remained;
        
        if (itA != a.rend())
        {
            sum += *itA - '0';
            itA++;
        }
        
        if (itB != b.rend())
        {
            sum += *itB - '0';
            itB++;
        }
        
        remained = sum / 10;
        answer = std::to_string(sum % 10) + answer;
    }
    
    if (remained != 0)
        answer = "1" + answer;
    
    return answer;
}