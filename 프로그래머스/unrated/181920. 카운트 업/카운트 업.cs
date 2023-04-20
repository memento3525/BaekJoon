using System;
using System.Linq;

public class Solution {
    public int[] solution(int start, int end) 
    {
        return Enumerable.Range(start, end - start + 1).ToArray();
    }
}