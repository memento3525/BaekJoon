using System;

public class Solution {
    public int solution(string[] babbling) {
        
        string[] dict = new string[]{"aya", "ye", "woo", "ma"};
        
        int answer = 0;
        foreach(string str in babbling)
        {
            string newArray = str;
            
            foreach(string sample in dict)
                newArray = newArray.Replace(sample, sample.ToUpper());
            
            if(newArray == str.ToUpper())
                answer++;
        }
        
        return answer;
    }
}