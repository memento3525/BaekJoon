#include <string>
#include <vector>
#include <map>
#include <numeric>

using namespace std;

int solution(vector<string> strArr) {
    
    map<int, int> _map;
    
    for (const string& str : strArr)
    {
        _map[str.size()]++;
    }
    
    int answer = 0;
    
    for (std::pair<const int, int> elem : _map)
    {
        if (answer < elem.second)
            answer = elem.second;
    }
    
    return answer;
}