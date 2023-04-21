using System;
using System.Linq;

public class Solution {
    public int[] solution(int[] arr, int k) {
        if(k % 2 == 1)
            return arr.Select(s => s * k).ToArray();
        else 
            return arr.Select(s => s + k).ToArray();
    }
}