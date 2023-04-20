using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public string[] solution(string[] str_list) 
    {
        var list = new List<string>();
        
        bool isFirst = false;
        foreach(var c in str_list)
        {
            if(!isFirst)
            {
                if(c == "l")
                    return list.ToArray();
                else if(c == "r")
                {
                    list.Clear();
                    isFirst = true;
                    continue;
                }
            }
            
            list.Add(c);
        }
        
        return isFirst ? list.ToArray() : new string[]{};
    }
}