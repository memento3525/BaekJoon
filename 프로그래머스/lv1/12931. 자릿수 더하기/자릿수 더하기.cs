using System;

public class Solution {
    public int solution(int n) {
        
        string str = n.ToString();
        char[] charArray = str.ToCharArray();
        
        int answer = 0;
        foreach(var item in charArray)
            answer += int.Parse(item.ToString());
        
        return answer;
    }
}