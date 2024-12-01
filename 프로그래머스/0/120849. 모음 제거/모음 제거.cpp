#include <string>
#include <vector>
#include <set>
using namespace std;

string solution(string my_string) {
    
    string answer = "";
    set<char> mySet = { 'a', 'e', 'i', 'o', 'u' };
    
    for (char c : my_string)
    {
        if (mySet.find(c) == mySet.end())
            answer += c;
    }
    
    return answer;
}