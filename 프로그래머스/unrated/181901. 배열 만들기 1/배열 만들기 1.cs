using System;
using System.Linq;

public class Solution {
    public int[] solution(int n, int k) {
        return Enumerable.Range(1, n).Where(w => w % k == 0).ToArray();
    }
}