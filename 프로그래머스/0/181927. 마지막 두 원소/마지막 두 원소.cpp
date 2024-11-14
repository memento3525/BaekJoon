#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer = vector<int>(num_list);
    
    int last = num_list[num_list.size() - 1];
    int preLast = num_list[num_list.size() - 2];
    
    int newItem = last > preLast ? last - preLast : last * 2;
    answer.push_back(newItem);
        
    return answer;
}