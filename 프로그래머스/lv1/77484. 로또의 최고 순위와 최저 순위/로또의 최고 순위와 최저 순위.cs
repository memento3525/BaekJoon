using System;
using System.Linq;

public class Solution {
    public int[] solution(int[] lottos, int[] win_nums) {
        
        int zeroCount = lottos.Where(e => e == 0).Count();
        int matchCount = lottos.Where(e => win_nums.Contains(e)).Count();
        
        int minRank = matchCount >= 2 ? 7 - matchCount : 6;
        int maxRank = minRank - zeroCount < 1 ? 1 : minRank - zeroCount;
        
        return new int[2]{ maxRank, minRank };
    }
}