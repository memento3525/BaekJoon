using System;

public class Solution {
    public int solution(int[,] arr) 
    {
        for(int y = 0; y < arr.GetLength(0); ++y)
        {
            for(int x = 0; x < arr.GetLength(1); ++x)
            {
                if(arr[y, x] != arr[x, y])
                    return 0;
            }
        }
        
        return 1;
    }
}