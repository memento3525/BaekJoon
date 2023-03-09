using System;
using System.Linq;
using System.Text;

public class Solution {
    public string solution(int[] numbers) 
    {
        var enumer = numbers.Select(s => s.ToString())
                            .OrderByDescending(o => $"{o}{o}{o}");
        
        bool isZero = true;
        var sb = new StringBuilder();
        foreach(string str in enumer)
        {
            if(isZero && str == "0")
                continue;
            
            isZero = false;
            sb.Append(str);
        }
        
        return isZero ? "0" : sb.ToString();
    }
}