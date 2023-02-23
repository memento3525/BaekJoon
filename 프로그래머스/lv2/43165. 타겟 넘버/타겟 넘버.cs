using System;
using System.Collections.Generic;

public class Solution {
    public int solution(int[] numbers, int target) {
        
        var stack = new Stack<(int sum, int index)>();
        stack.Push((0, 0));
        
        int answer = 0;
        while(stack.Count > 0)
        {
            (int sum, int index) = stack.Pop();
            
            if(index == numbers.Length)
            {
                if(sum == target)
                    answer++;
                
                continue;
            }
            
            stack.Push((sum + numbers[index], index + 1));
            stack.Push((sum - numbers[index], index + 1));
        }
        
        return answer;
    }
    
    /*
    재귀 풀이
    private static int DFS(int[] numbers, int target, int sum, int index) 
    {
        if (index == numbers.Length) 
        {
            if (target == sum) 
                return 1;
            
            return 0;
        }

        return DFS(numbers, target, sum + numbers[index], index + 1) 
            + DFS(numbers, target, sum + numbers[index] * -1, index + 1);
    }
    */
}