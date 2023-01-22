using System;
using System.Linq;

public class Solution {
    public int[] solution(int[] numlist, int n) {
        
        return numlist.OrderBy(k => Math.Abs(k - n))
                      .ThenByDescending(k => k)
                      .ToArray();
    }
}