using System;

public class Solution {
    public int[] solution(int[] arr, int n) 
    {
        int i = arr.Length % 2 == 1 ? 0 : 1;
        for(; i < arr.Length; i += 2)
            arr[i] += n;
        return arr;
    }
}