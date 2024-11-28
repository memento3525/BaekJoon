#include <string>
#include <vector>

using namespace std;

int solution(int hp) {
    int answer = 0;
    int arr[3] = { 5, 3, 1 }; 
    
    for (const int& atk : arr)
    {
        answer += hp / atk;
        hp %= atk;
    }
    
    return answer;
}