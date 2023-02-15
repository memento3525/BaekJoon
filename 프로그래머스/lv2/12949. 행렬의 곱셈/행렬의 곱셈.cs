using System;

public class Solution {
    public int[,] solution(int[,] arr1, int[,] arr2) {
        
        int[,] answer = new int[arr1.GetLength(0), arr2.GetLength(1)];
        
        for(int a = 0; a < arr1.GetLength(0); a++)
        {
            for(int b = 0; b < arr2.GetLength(1); b++)
            {
                for(int c = 0; c < arr2.GetLength(0); c++)
                {
                    answer[a, b] += arr1[a, c] * arr2[c, b];
                }
            }
        }
        
        return answer;
    }
}