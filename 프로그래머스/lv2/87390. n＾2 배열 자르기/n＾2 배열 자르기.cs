using System;

public class Solution {
    public int[] solution(int n, long left, long right) {
        
        int[] answer = new int[right - left + 1];
        
        for(long i = 0; i < answer.Length; i++)
        {
            long x = (left + i) % n;
            long y = (left + i) / n;
            
            answer[i] = (int)(x > y ? ++x : ++y);
        }
        
        return answer;
    }
}