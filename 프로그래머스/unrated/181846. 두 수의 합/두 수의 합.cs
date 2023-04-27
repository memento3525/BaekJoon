using System;
using System.Text;

public class Solution {
    public string solution(string a, string b) 
    {
        string shortedStr = a.Length > b.Length ? b : a;
        string longerStr = a.Length > b.Length ? a : b;
        
        var sb = new StringBuilder();
        int over = 0;
        int i = 0;
        for(; i < shortedStr.Length; ++i)
        {
            int numA = shortedStr[shortedStr.Length - 1 - i] - '0';
            int numB = longerStr[longerStr.Length - 1 - i] - '0';
            
            int sum = numA + numB + over;
            over = sum / 10;
            
            sb.Insert(0, (sum % 10).ToString());
        }
        
        for(; i < longerStr.Length; ++i)
        {
            int numB = longerStr[longerStr.Length - 1 - i] - '0';
            int sum = numB + over;
            over = sum / 10;
            
            sb.Insert(0, (sum % 10).ToString());
        }
        
        if(over > 0)
            sb.Insert(0, over.ToString());
        
        return sb.ToString();
    }
}