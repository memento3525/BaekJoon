using System;
using System.Text.RegularExpressions;

public class Solution {
    public string solution(string myString) {
        
        return Regex.Replace(myString, @"a|e|i|o|u", "");
    }
}