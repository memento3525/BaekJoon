using System;

public class Solution {
    public int[,] solution(int[,] arr1, int[,] arr2) {
        
        int[,] answer = new int[arr1.GetLength(0), arr2.GetLength(1)];
        
        for(int a = 0; a < arr1.GetLength(0); a++)
        {
            for(int b = 0; b < arr1.GetLength(1); b++)
            {
                for(int c = 0; c < arr2.GetLength(1); c++)
                {
                    answer[a, c] += arr1[a, b] * arr2[b, c];
                }
            }
        }
        
        return answer;
    }
}