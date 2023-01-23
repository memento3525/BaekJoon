using System;
using System.Linq;

public class Solution {
    public int solution(int[,] sizes) {
        
        int maxOfMax = Enumerable.Range(0, sizes.GetLength(0))
                           .Select(i => (int)Math.Max(sizes[i, 0], sizes[i, 1]))
                           .Max();
        
        int maxOfMin = Enumerable.Range(0, sizes.GetLength(0))
                           .Select(i => (int)Math.Min(sizes[i, 0], sizes[i, 1]))
                           .Max();
            
        return maxOfMax * maxOfMin;
    }
}