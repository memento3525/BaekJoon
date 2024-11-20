#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> num_list) {
    
    auto it = std::find_if(num_list.begin(), num_list.end(), 
                        [](int num)
                        {
                            return num < 0;
                        });
    
    if (it == num_list.end())
        return -1;
    
    return std::distance(num_list.begin(), it);
}