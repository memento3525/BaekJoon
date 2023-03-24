using System;

public class Solution {
    public long solution(int w, int h) 
    {
        long answer = 0;
        int gcd = GCD(w, h);
        int width = w / gcd;
        int height = h / gcd;
        double slope = height / (double)width;
        
        for(int x = 0; x < width; ++x)
        {
            int curY = (int)Math.Floor(slope * x);
            int nextY = (int)Math.Ceiling(slope * (x + 1));
            
            answer += (h - (nextY - curY));
        }
        return answer * gcd;
    }
    
    // 공약수가 존재한다면 도형이 합동이다.
    private int GCD(int a, int b)
    {
        if(b == 0) return a;
        return GCD(b, a % b);
    }
}