using System;

public class Solution {
    public int solution(int n) {
        
        int k = 1;
        while(true)
        {
            if(Fac(k) > n)
                return k - 1;
            
            k++;
        }
        
        return 1;
    }
    
    public int Fac(int num)
    {
        if(num == 1 || num == 0) return 1;
        return num * Fac(num - 1);
    }
}