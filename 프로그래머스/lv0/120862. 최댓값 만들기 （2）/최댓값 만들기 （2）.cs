using System;
using System.Linq;

public class Solution {
    public int solution(int[] numbers) {
        
        int positiveMax = numbers.OrderByDescending(n => n).Take(2).Aggregate((n, k) => n * k);
        int negativeMax = numbers.OrderBy(n => n).Take(2).Aggregate((n, k) => n * k);
        
        return (int)Math.Max(positiveMax, negativeMax);
    }
}