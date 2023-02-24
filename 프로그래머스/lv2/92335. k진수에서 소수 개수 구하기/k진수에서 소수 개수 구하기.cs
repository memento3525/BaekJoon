using System;
using System.Collections.Generic;

public class Solution {
    public int solution(int n, int k) {
        
        var stack = new Stack<int>();
        while(n > 0)
        {
            stack.Push(n % k);
            n /= k;
        }
        
        int answer = 0;
        long currentNum = 0;
        while(stack.Count > 0)
        {
            int num = stack.Pop();
            if(num == 0)
            {
                if(currentNum > 0)
                {
                    if(IsPrimer(currentNum))
                        answer++;
                    
                    currentNum = 0;
                }
                
                continue;
            }
            
            currentNum *= 10;
            currentNum += num;            
        }
        
        if(currentNum > 0 && IsPrimer(currentNum))
            answer++;
        
        return answer;
    }
    
    private bool IsPrimer(long num)
    {
        if(num <= 1)
            return false;
        
        int count = 0;
        for(long i = 2; i * i <= num; i++)
        {
            if(num % i == 0)
                return false;
        }
        
        return true;
    }
}