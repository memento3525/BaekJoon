using System;

public class Solution {
    public int solution(int slice, int n) {
        
        int remainder = n % slice;
        int answer = n / slice;
        
        if(remainder > 0)
            answer++;
        
        return answer;
    }
}