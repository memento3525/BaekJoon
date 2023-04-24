using System;
using System.Text;

public class Solution {
    public string solution(string code) 
    {
        var sb = new StringBuilder();

        bool mode = false;
        for(int i = 0; i < code.Length; ++i)
        {
            if(code[i] == '1')
                mode = !mode;
            else if((mode && i % 2 == 1) || (!mode && i % 2 == 0))
                sb.Append(code[i]);
        }
        
        return sb.ToString() == string.Empty ? "EMPTY" : sb.ToString();
    }
}