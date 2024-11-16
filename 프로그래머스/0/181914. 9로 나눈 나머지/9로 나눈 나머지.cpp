#include <string>
#include <vector>

using namespace std;

int solution(string number) {
    
    int sum = 0;
    int charZeroIndex = '0';
    for (char c : number)
    {
        sum += static_cast<int>(c) - charZeroIndex;
    }
    
    return sum % 9;
}