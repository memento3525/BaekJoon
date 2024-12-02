#include <string>
#include <vector>
#include <set>

using namespace std;

string solution(string my_string) {
    
    string result;
    set<char> mySet;
    
    for (char c : my_string)
    {
        if (mySet.find(c) == mySet.end())
        {
            result += c;
            mySet.insert(c);
        }
    }
    
    return result;
}