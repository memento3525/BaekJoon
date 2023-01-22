using System;
using System.Linq;

public class Solution {
    public int[] solution(int[] emergency) {
        int[] sortedArray = emergency.OrderByDescending(n => n).ToArray();
        return emergency.Select(n => Array.IndexOf(sortedArray, n) + 1).ToArray();
    }
}