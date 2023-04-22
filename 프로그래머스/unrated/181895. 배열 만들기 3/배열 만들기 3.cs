using System;

public class Solution {
    public int[] solution(int[] arr, int[,] intervals) 
    {
        int size1 = intervals[0, 1] - intervals[0, 0] + 1;
        int size2 = intervals[1, 1] - intervals[1, 0] + 1;
        
        int[] answer = new int[size1 + size2];
        Array.Copy(arr, intervals[0, 0], answer, 0, size1);
        Array.Copy(arr, intervals[1, 0], answer, size1, size2);
        
        return answer;
    }
}