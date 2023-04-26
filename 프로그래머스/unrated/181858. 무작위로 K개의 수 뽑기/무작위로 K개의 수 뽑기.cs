using System;
using System.Linq;

public class Solution {
    public int[] solution(int[] arr, int k) 
    {
        int[] distinct = arr.Distinct().Take(k).ToArray();
        int[] answer = Enumerable.Repeat(-1, k).ToArray();
        Array.Copy(distinct, 0, answer, 0, distinct.Length);
        
        return answer;
    }
}