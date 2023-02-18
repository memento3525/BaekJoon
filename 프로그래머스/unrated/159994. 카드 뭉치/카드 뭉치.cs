using System;
using System.Collections.Generic;

public class Solution {
    public string solution(string[] cards1, string[] cards2, string[] goal) {
        
        Array.Reverse(cards1);
        Array.Reverse(cards2);
        var stack1 = new Stack<string>(cards1);
        var stack2 = new Stack<string>(cards2);
        
        for(int i = 0; i < goal.Length; i++)
        {
            if(stack1.Count > 0 && goal[i] == stack1.Peek())
                stack1.Pop();
            else if(stack2.Count > 0 && goal[i] == stack2.Peek())
                stack2.Pop();
            else
                return "No";
        }
        
        return "Yes";
    }
}