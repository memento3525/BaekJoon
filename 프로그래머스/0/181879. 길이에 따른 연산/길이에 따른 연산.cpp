#include <string>
#include <vector>
#include <numeric>
//#include <algorithm>

using namespace std;

int solution(vector<int> num_list) {
    
    if (num_list.size() >= 11)
    {
        return std::accumulate(num_list.begin(), num_list.end(), 0);        
    }
    else
    {
        return std::accumulate(num_list.begin(), num_list.end(), 1, 
                               [](int a, int b){ return a * b; });        
    }
}