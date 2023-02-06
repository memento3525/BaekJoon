using System;

class Solution
{
    public int solution(int n)
    {
        int usedPower = 0;
        
        while(n > 1)
        {
            if(n % 2 != 0)
                usedPower++; // 점프가 필요함
            
            n = n / 2;
        }
        
        return usedPower + 1; // 최초는 어차피 점프함
    }
}