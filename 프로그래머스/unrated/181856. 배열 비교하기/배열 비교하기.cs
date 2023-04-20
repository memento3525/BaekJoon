using System;
using System.Linq;

public class Solution {
    public int solution(int[] arr1, int[] arr2) 
    {
        int a = 0;
        int b = 0;
        
        if(arr1.Length != arr2.Length)
        {
            a = arr1.Length;
            b = arr2.Length;
        }
        else
        {
            a = arr1.Sum();
            b = arr2.Sum();
        }
        
        if(a < b) return -1;
        if(a > b) return 1;
        return 0;
    }
}