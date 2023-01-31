using System;
using System.Linq;

class Solution 
{
    public int solution(int n) 
    {
        string binaryStr = Convert.ToString(n, 2);
        int oneCount = binaryStr.Count(c => c == '1');
        
        int answer = n + 1;
        while(true)
        {
            int count = Convert.ToString(answer, 2).Count(c => c == '1');
            if(count == oneCount)
                return answer;
            
            answer++;
        }
        
        return answer;
     }
}