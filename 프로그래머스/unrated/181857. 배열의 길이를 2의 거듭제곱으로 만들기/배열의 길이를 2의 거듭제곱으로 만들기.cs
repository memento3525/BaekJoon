using System;

public class Solution {
    public int[] solution(int[] arr) 
    {
        int size = 1;
        while(size < arr.Length)
            size *= 2;
        
        int[] answer = new int[size];
        Array.Copy(arr, 0, answer, 0, arr.Length);
        return answer;
    }
}