using System;
using System.Linq;

public class Solution {
    public long[] solution(long[] numbers) {
        
        var answer = new long[numbers.Length];
        for(int i = 0; i < numbers.Length; ++i)
            answer[i] = GetF(numbers[i]);
        
        return answer;
    }
    
    private long GetF(long num)
    {
        if(num % 2 == 0)
            return num + 1;
        
        string numStr = Convert.ToString(num, 2);
        int index = -1;
        for(int i = numStr.Length - 1; i >= 0; --i)
        {
            if(numStr[i] == '0')
            {
                index = i;
                break;
            }
        }
        
        if(index == -1)
            return Convert.ToInt64("10" + numStr.Substring(1, numStr.Length - 1), 2);
        else
        {
            var charArray = numStr.ToCharArray();
            charArray[index] = '1';
            charArray[index + 1] = '0';
            string str = new string(charArray);
            return Convert.ToInt64(str, 2);
        }
    }
}