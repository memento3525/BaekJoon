using System;

public class Solution {
    public long solution(int k, int d) 
    {
        long answer = 0;
        long dd = (long)d * d;
        long kk = (long)k * k;
        
        for(long x = 0; x <= d; x += k)
        {
            long xx = (long)x * x;
            long y = (long)Math.Sqrt((dd - xx) / kk);
            answer += (y + 1); // 0이 포함되야함
        }
        return answer;
    }
}