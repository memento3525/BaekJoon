using System;
using System.Collections.Generic;
using System.Text;

public class Solution {
    public string solution(string number, int k) 
    {
        int size = number.Length - k;
        
        // 스택에 담으면서 자신보다 Top에 위치한 작은 숫자들을 제거하고 Top으로 들어간다. 
        var stack = new Stack<char>();
        int count = k;
        for(int i = 0; i < number.Length; i++)
        {
            char c = number[i];
            while(count > 0 && stack.Count > 0 && stack.Peek() < c)
            {
                stack.Pop();
                count--;
            }
            
            stack.Push(c);
        }
        
        // 오른쪽 숫자가 제일 작은 경우 size보다 더 많이 pop크기 때문에 제거한다.
        while(stack.Count > size)
            stack.Pop();
        
        // stack -> array -> string
        var array = new char[size];
        for(int i = 0; i < size; i++)
            array[i] = stack.Pop();
        
        Array.Reverse(array);
        return new string(array);
    }
}