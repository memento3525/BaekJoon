using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int[] solution(int[] arr) 
    {
        List<int> answer = new List<int>();
        foreach(int n in arr)
            answer.AddRange(Enumerable.Repeat(n, n));
        return answer.ToArray();
    }
}