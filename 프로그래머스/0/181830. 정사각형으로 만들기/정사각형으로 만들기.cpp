#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr) {
    
    if (arr.size() == arr[0].size())
        return arr;
    
    if (arr.size() > arr[0].size())
    {
        while (arr.size() != arr[0].size())
        {
            for (vector<int>& v : arr)
                v.push_back(0);
        }
    }
    else
    {
        while (arr.size() != arr[0].size())
        {
            vector<int> v(arr[0].size(), 0);
            arr.push_back(v);
        }
    }
    
    return arr;
}