using System;
using System.Linq;

public class Solution {
    public int solution(int num, int k) {
        
        var charArray = num.ToString().ToCharArray();
        int answer = Array.IndexOf(charArray, (char)(k + '0'));
        
        if(answer != -1)
            answer ++;
        
        return answer;
    }
}