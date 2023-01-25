using System;
using System.Collections.Generic;

class Solution
{
    public int solution(int[] nums)
    {
        int answer = 0;
        
        for(int a = 0; a < nums.Length; a++)
        {
            for(int b = 0; b < nums.Length; b++)
            {
                if(a <= b) continue;
                for(int c = 0; c < nums.Length; c++)
                {
                    if(b <= c) continue;
                    if(a == c) continue;
                    
                    if(IsPrime(nums[a] + nums[b] + nums[c])) 
                        answer++;
                }
            }
        }
        
        return answer;
    }
    
    private bool IsPrime(int n)
    {
        if(n <= 1) return false;
        for(int i = 2; i * i <= n; i++)
        {
            if(n % i == 0)
                return false;
        }
        return true;
    }
}