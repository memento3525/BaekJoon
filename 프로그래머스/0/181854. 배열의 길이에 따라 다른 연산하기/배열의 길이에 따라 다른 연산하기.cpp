#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int n) {
    
    int i = arr.size() & 1 ? 0 : 1;
    for (; i < arr.size(); i+=2)
    {
        arr[i] += n;
    }
    
    return arr;
}