using System;

public class Solution {
    public int[,] solution(int[] num_list, int n) {
        
        int length = num_list.Length / n;
        int[,] answer = new int[length, n];

        for(int k = 0; k < length; k++)
        {       
            for(int i = 0; i < n; i++)
                answer[k, i] = num_list[k * n + i];
        }
        
        return answer;
    }
}