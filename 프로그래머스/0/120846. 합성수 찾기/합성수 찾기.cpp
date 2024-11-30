#include <string>

using namespace std;

int solution(int n) {
    
    int* count = new int[n + 1]();
    for (int i = 2; i <= n; ++i)
    {
        for (int k = i; k <= n; k += i)
            count[k]++;
    }
    
    int answer = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (count[i] >= 2) // 1은 모든수의 약수라 2개만 있으면 됨
            ++answer;
    }
    
    delete[] count;
    return answer;
}