using System;

public class Solution {
    public int solution(int n) {
        
        int remainder = n % 7;
        int answer =  n / 7;
        
        if(remainder > 0)
            answer++;
        
        return answer;
    }
}