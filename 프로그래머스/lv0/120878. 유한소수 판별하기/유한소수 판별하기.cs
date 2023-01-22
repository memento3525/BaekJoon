using System;

public class Solution {
    public int solution(int a, int b) {
        
        int child = a;
        int parent = b;
        
        while(true)
        {
            int gdc = GCD(child, parent);
            if(gdc > 1)
            {
                child /= gdc;
                parent /= gdc;
            }
            else
            {
                break;
            }
        }
        
        return IsTwoOrFive(parent) ? 1 : 2;
    }
    
    private int GCD(int a, int b)
    {
        if(b == 0) return a;
        else return GCD(b, a % b); 
    }
    
    private bool IsTwoOrFive(int num)
    {
        while(num % 2 == 0)
            num /= 2;
        
        while(num % 5 == 0)
            num /= 5;
        
        return num == 1;
    }
}