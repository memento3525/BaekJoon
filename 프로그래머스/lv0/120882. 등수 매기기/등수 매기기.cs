using System;
using System.Linq;

public class Solution {
    public int[] solution(int[,] score) {
        
        int personSize = score.GetLength(0);
        
        int[] sum = new int[personSize];
        
        for(int i = 0; i < personSize; i++)
            sum[i] = score[i, 0] + score[i, 1];
                
        return sum.Select(k => sum.Count(n => n > k) + 1)
                  .ToArray();
    }
    
    /* 
        int[] answer = new int[personSize];
        for(int i = 0; i < personSize; i++)
            answer[i] = sum.Count(n => n > sum[i]) + 1;
        return answer;
    */
}