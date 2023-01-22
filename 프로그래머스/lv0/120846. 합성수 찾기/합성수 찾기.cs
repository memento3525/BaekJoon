using System;
using System.Linq;

public class Solution {
    public int solution(int n) {
        int answer = 0;
        
        answer = Enumerable.Range(1, n).Where(k => IsCompound(k)).Count();
        
        return answer;
    }
    
    public bool IsCompound(int num)
    {
        int count = 0;
        for(int i = 1; i <= num; i++)
        {
            if(num % i == 0)
            {
                count++;
                if(count >= 3)
                    return true;
            }
        }
        return false;
    }
}