using System;
using System.Linq;

public class Solution {
    public int[] solution(int n, int[] numlist) {
        return numlist.Where(k => k % n == 0).ToArray();
    }
}