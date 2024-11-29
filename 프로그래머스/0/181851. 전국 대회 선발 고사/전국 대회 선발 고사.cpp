#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> rank, vector<bool> attendance) {
    
    vector<std::pair<int, int>> vec;
    
    for (int i = 0; i < rank.size(); ++i)
    {
        if (attendance[i])
            vec.push_back(std::make_pair(rank[i], i));
    }
    
    std::sort(vec.begin(), vec.end());
    
    return 10000 * vec[0].second + 100 * vec[1].second + vec[2].second;
}