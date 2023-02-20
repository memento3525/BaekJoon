using System;
using System.Linq;

public class Solution {
    public int solution(int k, int[] tangerine) {
        
        int inputCount = 0;
        return tangerine
            .GroupBy(g => g)
            .OrderByDescending(o2 => o2.Count())
            .Aggregate(0, (n, next) =>
            {
                if (inputCount >= k)
                    return n;

                inputCount += next.Count();
                return ++n;
            });
    }
}