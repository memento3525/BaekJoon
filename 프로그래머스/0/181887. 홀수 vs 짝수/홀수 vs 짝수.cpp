#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    
    int even = 0;
    int odd = 0;
    
    for (int i = 0; i < num_list.size(); i += 2)
        odd += num_list[i];
        
    for (int i = 1; i < num_list.size(); i += 2)
        even += num_list[i];
    
    return even > odd ? even : odd;
}