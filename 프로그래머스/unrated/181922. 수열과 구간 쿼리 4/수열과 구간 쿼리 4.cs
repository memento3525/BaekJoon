using System;

public class Solution {
    public int[] solution(int[] arr, int[,] queries) 
    {
        for(int y = 0; y < queries.GetLength(0); ++y)
        {
            int s = queries[y, 0];
            int e = queries[y, 1];
            int k = queries[y, 2];
            
            for(int i = s; i <= e; ++i)
            {
                if(i % k == 0)
                    ++arr[i];
            }
        }
        return arr;
    }
}