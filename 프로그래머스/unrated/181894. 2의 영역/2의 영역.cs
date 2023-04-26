using System;

public class Solution {
    public int[] solution(int[] arr) 
    {
        int start = Array.IndexOf(arr, 2);
        if(start == -1) return new int[1]{ -1 };
        
        int end = Array.LastIndexOf(arr, 2);
        
        int[] answer = new int[end - start + 1];
        Array.Copy(arr, start, answer, 0, answer.Length);
        return answer;
    }
}