using System;

public class Solution {
    public int[] solution(string my_string)
    {
        int[] answer = new int[52];
        
        foreach(char c in my_string)
        {
            if(Char.IsUpper(c))
                answer[c - 'A']++;
            else
                answer[26 + c - 'a']++;
        }
        
        return answer;
    }
}