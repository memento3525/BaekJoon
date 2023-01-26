using System;
using System.Collections.Generic;

public class Solution {
    public int solution(string[] babbling) {
        int answer = 0;
        
        var dictArray = new string[]{"aya", "ye", "woo", "ma"};
        var doubling = new string[4];
        
        for(int i = 0; i < dictArray.Length; i++)
            doubling[i] = dictArray[i] + dictArray[i];
        
        foreach(string str in babbling)
        {
            string newStr = str;
            
            bool hasDouble = false;
            foreach(string doubleStr in doubling)
                if(newStr.Contains(doubleStr)) 
                    hasDouble = true;
            
            if(hasDouble) 
                continue;
            
            foreach(string dict in dictArray)
                newStr = newStr.Replace(dict, dict.ToUpper());
            
            if(newStr == str.ToUpper())
                answer++;
        }
        
        return answer;
    }
}