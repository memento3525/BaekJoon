using System;
using System.Linq;

public class Solution {
    public int solution(int[] arr) 
    {
        int x = 0;
        
        while(true)
        {
            int[] other = new int[arr.Length];
            for(int i = 0; i < arr.Length; ++i)
            {
                int n = arr[i];
                if(n >= 50 && n % 2 == 0)
                    n = n / 2;
                else if(n < 50 && n % 2 == 1)
                    n = n * 2 + 1;

                other[i] = n;            
            }
            
            if(Enumerable.SequenceEqual(arr, other))
                break;
            
            var temp = other;
            other = arr;
            arr = temp;
            ++x;
        }
        
        return x;
    }
}