using System;

public class Solution {
    
    private string[] numStrList = new string[10]{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    public long solution(string numbers) {
        
        string convertedStr = numbers;
        for(int i = 0; i < numStrList.Length; i++)
            convertedStr = convertedStr.Replace(numStrList[i], i.ToString());
        
        return long.Parse(convertedStr);
    }
}