#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> delete_list) {
    
    vector<int> answer;
    set<int> mySet = set<int>(delete_list.begin(), delete_list.end());
    for (int num : arr)
    {
        if (mySet.find(num) == mySet.end())
            answer.push_back(num);
    }
    
    return answer;
}