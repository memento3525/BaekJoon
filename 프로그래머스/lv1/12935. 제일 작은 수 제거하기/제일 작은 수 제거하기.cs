using System;
using System.Linq;

public class Solution {
    public int[] solution(int[] arr) {
        
        if(arr == null || arr.Length <= 1)
            return new int[]{ -1 };
        
        int min = arr.Min();
        int index = Array.IndexOf(arr, min);
        int length = arr.Length;
        
        int[] answer = new int[length - 1];
        
        Array.Copy(arr, 0, answer, 0, index);
        Array.Copy(arr, index + 1, answer, index, length - index - 1);

        return answer;
    }
}