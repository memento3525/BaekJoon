using System;

public class Solution {
    public string solution(int age) {
        char[] charArray = age.ToString().ToCharArray();
        
        for(int i = 0; i < charArray.Length; i++)
        {
            int newChar = (int)char.GetNumericValue(charArray[i]) + 'a';
            charArray[i] = (char)newChar;
        }
        
        return string.Concat(charArray);
    }
}