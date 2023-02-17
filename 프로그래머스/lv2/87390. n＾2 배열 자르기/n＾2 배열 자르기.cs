using System;

public class Solution {
    public long[] solution(int n, long left, long right) {
        
        long[] answer = new long[right - left + 1];
        
        for(long i = 0; i < answer.Length; i++)
        {
            long x = (left + i) % n;
            long y = (left + i) / n;
            
            answer[i] = x > y ? ++x : ++y;
        }
        
        return answer;
    }
}