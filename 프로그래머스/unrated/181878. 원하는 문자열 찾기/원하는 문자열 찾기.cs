using System;

public class Solution {
    public int solution(string myString, string pat) 
    {
        string str = myString.ToLower();
        return str.Contains(pat.ToLower()) ? 1 : 0;
    }
}