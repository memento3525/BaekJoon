using System;

public class Solution {
    public string solution(string my_string, int num1, int num2) {
        
        char[] charArray = my_string.ToCharArray();
        
        char tempChar = charArray[num1];
        charArray[num1] = charArray[num2];
        charArray[num2] = tempChar;
        
        return string.Concat(charArray);
    }
}