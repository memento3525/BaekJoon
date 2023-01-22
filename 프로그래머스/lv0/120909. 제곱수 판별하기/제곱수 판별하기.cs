using System;

public class Solution {
    public int solution(int n) {
        
        double sqrt = Math.Sqrt(n);
        bool isPoint = sqrt % 1f > float.Epsilon;
        
        return isPoint ? 2 : 1;
    }
}