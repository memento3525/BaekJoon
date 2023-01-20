using System;
using System.Linq;

public class Solution {
    public int solution(int[] a, int[] b) {
        return Enumerable.Range(0, a.Length).Select((i) => a[i] * b[i]).Sum();
    }
}