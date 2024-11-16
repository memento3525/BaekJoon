#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <numeric>

using namespace std;

int solution(int a, int b, int c, int d) {
    
    map<int, int> _map;
    _map[a] = 1;
    _map[b] = _map[b] + 1;
    _map[c] = _map[c] + 1;
    _map[d] = _map[d] + 1;

    int size = _map.size();
    if (size == 1)
    {
        return 1111 * a;
    }
    else if (size == 3) // 2개 1개 1개
    {
        int mult = 1;
        for (const auto& item : _map)
        {
            if (item.second == 1)
                mult *= item.first;
        }
        
        return mult; 
    }
    else if (size == 2) // 2개 2개 / 3개 1개
    {
        auto it1 = _map.begin();
        auto it2 = ++_map.begin();
        
        if (it1->second == 2) // 2개 2개
        {
            return (it1->first + it2->first) * abs(it1->first - it2->first);
        }
        else // 3개 1개
        {
            if (it1->second > it2->second)
            {
                return pow(10 * it1->first + it2->first, 2);
            }
            else
            {
                return pow(10 * it2->first + it1->first, 2);
            }
        }
    }
    else
    {
        return min(a, min(b, min(c, d)));
    }
}