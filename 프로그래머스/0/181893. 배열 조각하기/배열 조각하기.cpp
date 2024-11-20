#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> query) {
    
    for (int i = 0; i < query.size(); ++i)
    {
        int index = query[i];
        if (i % 2 == 0)
        {
            arr = vector<int>(arr.begin(), arr.begin() + index + 1);
        }
        else
        {
            arr = vector<int>(arr.begin() + index, arr.end());
        }
    }
    
    return arr;
}