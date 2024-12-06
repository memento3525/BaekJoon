#include <string>
#include <vector>

using namespace std;

int solution(int num, int k) {
    
    string str = to_string(num);
    for (int i = 0; i < str.size(); ++i)
    {
        int n = str[i] - '0';
        if (n == k)
            return i + 1;
    }
    
    return -1;
}