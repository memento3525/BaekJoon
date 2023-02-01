using System;
using System.Linq;
using System.Collections.Generic;

public class Solution {
    public int[] solution(string s) {
        
        int repeat = 0;
        int count = 0;
        while(s != "1")
        {
            count += ConvertBinary(ref s);
            repeat++;
        }
        return new int[2]{ repeat, count };
    }
    
    private int ConvertBinary(ref string str)
    {
        int count = 0;
        int size = str.Length;
        for(int i = 0; i < size; i++)
        {
            if(str[i] == '0')
                count++;
        }
        
        string convertedStr = string.Concat(Enumerable.Repeat("1", size - count));
        int length = convertedStr.Length;
        str = Convert.ToString(length, 2);;
        
        return count;
    }
}