using System;
using System.Linq;

public class Solution {
    public int solution(int[] number) {
        int answer = 0;
        
        bool[] visited = new bool[number.Length];
        Combination(number, visited, 0, number.Length, 3, ref answer);
        
        return answer;
    }
    
    // n개 중 k개를 뽑는 조합 : 빽 트레킹
    void Combination(int[] array, bool[] visited, int start, int n, int k, ref int count)
    {
        if(k == 0) // 완료! 출력함
        {
            int sum = array.Where((e, index) => visited[index]).Sum();
            if(sum == 0) count++;
            
            return;                
        }

        for(int i = start; i < n; i++)
        {
            visited[i] = true;
            // 이제 시작할 숫자(i)는 하나 늘고, 뽑아야할 숫자(k)는 하나 줄었다.
            Combination(array, visited, i + 1, n, k - 1, ref count);
            visited[i] = false;
        }
    }
}