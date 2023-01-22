using System;
using System.Linq;

public class Solution {
    public int solution(int[] sides) {
        
        int max = sides.Sum();
        return Enumerable.Range(1, max)
                           .Count(n => n < max 
                                  && n + sides[0] > sides[1] 
                                  && n + sides[1] > sides[0]);
    }
}