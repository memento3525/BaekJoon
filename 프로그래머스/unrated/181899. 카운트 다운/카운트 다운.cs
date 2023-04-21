using System;
using System.Linq;

public class Solution {
    public int[] solution(int start, int end) {
        return Enumerable.Range(end, start - end + 1).Reverse().ToArray();
    }
}