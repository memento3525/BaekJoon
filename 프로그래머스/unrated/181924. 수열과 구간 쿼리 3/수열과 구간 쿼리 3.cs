using System;

public class Solution {
    public int[] solution(int[] arr, int[,] queries) 
    {
        for(int y = 0; y < queries.GetLength(0); ++y)
        {
            int i = queries[y, 0];
            int j = queries[y, 1];
            
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        return arr;
    }
}