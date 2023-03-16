using System;
using System.Collections.Generic;

public class Solution {
    public int[] solution(int[] numbers) 
    {
        // 스택에 넣으면서 top보다 큰 수가 온 경우 pop을 반복하고, 현재 숫자를 pop된 index에 넣어준다.
        int[] answer = new int[numbers.Length];
        var stack = new Stack<Item>();
        for(int i = 0; i < numbers.Length; ++i)
        {
            while(stack.Count > 0 && numbers[i] > stack.Peek().value)
            {
                Item top = stack.Pop();
                answer[top.index] = numbers[i];
            }
            
            stack.Push(new Item(i, numbers[i]));
        }
        
        // 남은 item들은 자신보다 큰 수가 뒤에 오지 않는다.
        while(stack.Count > 0)
        {
            Item top = stack.Pop();
            answer[top.index] = - 1;
        }
        
        return answer;
    }
    
    public class Item
    {
        public int index;
        public int value;
        
        public Item(int index, int value)
        {
            this.index = index;
            this.value = value;
        }
    }
}