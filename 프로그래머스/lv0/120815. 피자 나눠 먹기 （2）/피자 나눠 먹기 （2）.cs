using System;

public class Solution {
    public int solution(int n) {
        
        const int piece = 6;
        
        int lcm = LCM(piece, n);
        int answer = lcm / piece;
        
        return answer;
    }
    
    // 최소 공배수
    public int LCM(int a, int b)
    {
        int gcd = GCD(a, b);
        return a * b / gcd;
    }
    
    // 최대 공약수
    public int GCD(int a, int b)
    {
        if(b == 0) return a;
        return GCD(b, a % b);
    }
}