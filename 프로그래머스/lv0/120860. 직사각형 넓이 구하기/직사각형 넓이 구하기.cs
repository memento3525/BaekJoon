using System;
using System.Linq;

public class Solution {
    public int solution(int[,] dots) {
        
        int[] xArray  = Enumerable.Range(0, 4).Select(n => dots[n, 0]).ToArray();
        int[] yArray  = Enumerable.Range(0, 4).Select(n => dots[n, 1]).ToArray();
        
        int xLength = xArray.Max() - xArray.Min();
        int yLength = yArray.Max() - yArray.Min();
        
        return xLength * yLength;
    }
}