using System;
using System.Linq;
using System.Text;

public class Solution {
    public string solution(string s) {
        
        char[] charArray = s.ToCharArray()
                            .GroupBy(n => n)
                            .Where(n => n.Count() == 1)
                            .Select(n => n.Key)
                            .OrderBy(n => n).ToArray();
        
        return new string(charArray);
    }
}