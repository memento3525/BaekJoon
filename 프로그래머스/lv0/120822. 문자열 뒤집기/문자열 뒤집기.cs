using System;

public class Solution {
    public string solution(string my_string) {
        char[] charArray = my_string.ToCharArray();
        Array.Reverse(charArray);
        return new string(charArray);
    }
}