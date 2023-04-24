using System;
using System.Linq;

public class Solution {
    public int solution(int a, int d, bool[] included) {
        return Enumerable.Range(0, included.Length)
                         .Select(s => a + s * d)
                         .Where((w, index) => included[index])
                         .Sum();
    }
}