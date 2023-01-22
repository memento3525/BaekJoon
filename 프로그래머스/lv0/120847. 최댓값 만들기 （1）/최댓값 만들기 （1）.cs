using System;
using System.Linq;

public class Solution {
    public int solution(int[] numbers) {
        
        int[] orderedNums = numbers.OrderByDescending(n => n).Take(2).ToArray();
        int answer = orderedNums[0] * orderedNums[1];
        
        return answer;
    }
}