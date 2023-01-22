using System;
using System.Linq;

public class Solution {
    public int solution(int n) {
        return Enumerable.Range(1, n).Where(k => n % k == 0).Count();
    }
}