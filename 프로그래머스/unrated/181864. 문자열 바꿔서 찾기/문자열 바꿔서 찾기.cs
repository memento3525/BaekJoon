using System;

public class Solution {
    public int solution(string myString, string pat) 
    {
        myString = myString.Replace("A", "b")
                           .Replace("B", "a");
        
        return myString.Contains(pat.ToLower()) ? 1 : 0;
    }
}