using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

public class Solution {
    public string[] solution(string my_string) 
    {
        var sb = new StringBuilder();
        var list = new List<string>();
        for(int i = my_string.Length - 1; i >= 0; --i)
        {
            sb.Insert(0, my_string[i]);
            list.Add(sb.ToString());
        }
        return list.OrderBy(o => o).ToArray();
    }
}