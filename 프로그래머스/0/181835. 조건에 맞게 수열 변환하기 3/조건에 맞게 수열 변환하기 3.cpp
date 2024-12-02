#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    
    if (k & 1)
    {
        transform(arr.begin(), arr.end(), arr.begin(), [&](int a){ return a * k; });
    }
    else
    {
        transform(arr.begin(), arr.end(), arr.begin(), [&](int a){ return a + k; });
    }
    
    return arr;
}