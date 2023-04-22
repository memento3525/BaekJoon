using System;

public class Solution {
    public int solution(string binomial) 
    {
        string[] splited = binomial.Split();
        
        int a = Int32.Parse(splited[0]);
        string op = splited[1];
        int b = Int32.Parse(splited[2]);
        
        if(op == "+")
            return a + b;
        else if(op == "-")
            return a - b;
        else // op == *
            return a * b;
    }
}