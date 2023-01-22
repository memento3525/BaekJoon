using System;

public class Solution {
    public int solution(int n) {
        
        int length = n.ToString().Length;
        int answer = 0;
        
        int divider = 1;
        for(int i = 0; i < length; i++)
        {
            int preDivider = divider;
            divider *= 10;
            
            int remainder = (n - answer) % divider;   
            int headNumber = remainder / preDivider;
            answer += headNumber;
        }
        
        return answer;
    }
}