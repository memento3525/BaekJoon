#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<int> array) {
    
    map<int, int, std::greater<int>> map;
    
    for (int i : array)
        map[i]++;
    
    vector<std::pair<int, int>> v(map.begin(), map.end());
    
    std::sort(v.begin(), v.end(), [](const auto& a, const auto& b)
              { 
                  return a.second > b.second; 
              });
    
    const auto& max = (v.begin());
    const auto& next = (++v.begin());
    
    return (max->second == next->second) ? -1 : max->first;
}