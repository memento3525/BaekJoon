using System;
using System.Linq;

public class Solution {
    public int[] solution(int[] arr, int[,] queries) 
    {
        int[] answer = new int[queries.GetLength(0)];
        for(int i = 0; i < queries.GetLength(0); ++i)
        {
            int s = queries[i, 0];
            int e = queries[i, 1];
            int k = queries[i, 2];
            
            int num = arr.Skip(s)
                       .Take(e - s + 1)
                       .Where(w => w > k)
                       .DefaultIfEmpty(-1)
                       .OrderBy(o => o)
                       .First();
            
            answer[i] = num;
        }
        
        return answer;
    }
}