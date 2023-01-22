using System;
using System.Linq;
using System.Collections.Generic;

public class Solution {
    public int solution(string s) {
        
        string[] splitedStr = s.Split(" ");
        Stack<string> stack = new Stack<string>();
        
        foreach(string str in splitedStr)
        {
            if(str == "Z")
                stack.Pop();
            else
                stack.Push(str);                
        }
        
        return stack.Select(n => int.Parse(n)).Sum();
    }
}