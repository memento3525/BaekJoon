using System;
using System.Linq;

public class Solution {
    public int solution(int[] numbers) {
        return Enumerable.Range(1, 9).Where(e => !numbers.Contains(e)).Sum();
    }
}