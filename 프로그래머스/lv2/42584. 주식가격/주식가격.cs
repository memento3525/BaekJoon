using System;
using System.Collections.Generic;

public class Solution {
    public int[] solution(int[] prices) {
        
        int[] answer = new int[prices.Length];
        
        var stack = new Stack<(int day, int price)>();
        for(int i = 0; i < prices.Length; i++)
        {
            int cur = prices[i];
            
            while(stack.Count > 0 && stack.Peek().Item2 > cur) // 가격이 하락했다면 스택 최상단이 같거나 클 때까지
            {
                (int day, int price) top = stack.Pop(); // pop한다
                answer[top.day] = i - top.day;
            }

            stack.Push((i, cur));
        }
        
        // 마지막에 남은 것 처리
        int lastDay = prices.Length - 1;
        while(stack.Count > 0)
        {
            (int day, int price) top = stack.Pop();
            answer[top.day] = lastDay - top.day;
        }
        
        return answer;
    }
}