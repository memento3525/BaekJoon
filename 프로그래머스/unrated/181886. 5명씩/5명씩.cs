using System;

public class Solution {
    public string[] solution(string[] names) 
    {
        string[] answer = new string[(names.Length - 1) / 5 + 1];
        
        int index = 0;
        for(int i = 0; i < names.Length; i += 5)
        {
            answer[index] = names[i];
            ++index;
        }
        
        return answer;
    }
}