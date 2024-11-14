#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    
    for (const vector<int> v : queries)
    {
        int temp = arr[v[0]];
        arr[v[0]] = arr[v[1]];
        arr[v[1]] = temp;
    }
    
    return arr;
}