#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array, int n) {
    
    sort(array.begin(), array.end());
    
    int answer = 0;
    int diff = 1000000;
    
    for (int i : array)
    {
        int newDiff = abs(n - i);
        if (newDiff < diff)
        {
            answer = i;
            diff = newDiff;
        }
    }
    
    return answer;
}