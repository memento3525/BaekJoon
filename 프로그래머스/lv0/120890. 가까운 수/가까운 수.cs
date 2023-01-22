using System;
using System.Linq;

public class Solution {
    public int solution(int[] array, int n) {
        return array.OrderBy(k => Math.Abs(k - n))
                    .ThenBy(k => k)
                    .First();
    }
}