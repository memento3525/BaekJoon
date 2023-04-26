using System;

public class Solution {
    public string solution(string my_string, int[,] queries) 
    {
        var arr = my_string.ToCharArray();
        for(int y = 0; y < queries.GetLength(0); ++y)
        {
            int s = queries[y, 0];
            int e = queries[y, 1];
            
            Array.Reverse(arr, s, e - s + 1);
        }
        return new string(arr);
    }
}