using System;
using System.Collections.Generic;

public class Solution {
    public int solution(string s) {
        int answer = 0;
        for(int x = 0; x < s.Length; x++)
        {
            string testStr = s.Substring(x, s.Length - x) + s.Substring(0, x);
            if(IsCorrect(testStr))
                answer++;
        }
        
        return answer;
    }
    
    private bool IsCorrect(string s)
    {
        var stack = new Stack<char>();
        stack.Push(' '); // NULL 체크 방지
        
        foreach(char c in s)
        {
            char top = stack.Peek();
            
            if( (c == ')' && top == '(') ||
                (c == ']' && top == '[') ||
                (c == '}' && top == '{') )
            {
                stack.Pop();
                continue;
            }
            
            stack.Push(c);
        }
        
        return stack.Count == 1;
    }
}