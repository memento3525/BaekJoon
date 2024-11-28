#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) {
    
    int size = arr.size();
    int pot = 1;    
    while (size > pot)
    {
        pot *= 2;
    }
    
    if (pot != size)
        arr.insert(arr.end(), pot - size, 0);
    
    return arr;
}