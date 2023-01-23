using System;

public class Solution {
    public int solution(string s) {
        
        var strArray = new string[10]{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        
        for(int i = 0; i < strArray.Length; i++)
            s = s.Replace(strArray[i], i.ToString());
        
        return Convert.ToInt32(s);
    }
}