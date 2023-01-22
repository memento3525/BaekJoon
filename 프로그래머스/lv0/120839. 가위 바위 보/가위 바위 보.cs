using System;
using System.Text;

public class Solution {
    public string solution(string rsp) {
        
        StringBuilder sb = new StringBuilder(rsp.Length);
        
        char[] charArray = rsp.ToCharArray();
        foreach(char item in charArray)
        {
            char currnt = GetWinStr(item);
            sb.Append(currnt);
        }
        
        return sb.ToString();
    }
    
    public char GetWinStr(char n)
    {
        switch(n)
        {
            case '2': return '0';
            case '0': return '5';
            case '5': return '2';
            default : return default(char);
        }
    }
}