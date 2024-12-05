#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> s1, vector<string> s2) {
    int answer = 0;
    
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    
    auto it1 = s1.begin();
    auto it2 = s2.begin();
    
    while (it1 != s1.end() && it2 != s2.end())
    {
        if (*it1 == *it2)
        {
            ++answer;
            ++it1;
            ++it2;
        }
        else if (*it1 > *it2)
        {
            ++it2;
        }
        else // if (*it1 < *it2)
        {
            ++it1;
        }
    }
    
    return answer;
}