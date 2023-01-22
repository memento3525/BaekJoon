using System;

public class Solution {
    public int solution(int num) {
        
        if(num == 1) 
            return 0;
        
        int repeat = 0;
        long n = (long)num;
        
        while(n != 1 && repeat < 500)
        {
            if(n % 2 == 0)
                n /= 2;
            else
                n = (n * 3) + 1;
            
            repeat++;
        }
        
        Console.WriteLine(repeat);
        if(repeat >= 500 || n != 1)
            return -1;
        else
            return repeat;
    }
}