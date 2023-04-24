using System;

public class Solution {
    public int[,] solution(int[,] arr) 
    {
        int max = Math.Max(arr.GetLength(0), arr.GetLength(1));
        int[,] answer = new int[max, max];
        
        for(int y = 0; y < arr.GetLength(0); ++y)
        {
            for(int x = 0; x < arr.GetLength(1); ++x)
                answer[y, x] = arr[y, x];
        }
        
        return answer;
    }
}