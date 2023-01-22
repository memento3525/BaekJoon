using System;
using System.Text.RegularExpressions;
using System.Linq;

public class Solution {
    public int solution(string my_string) {
        int answer = 0;
        
        string[] intStrArray = Regex.Split(my_string, "[a-zA-Z]");
        answer = intStrArray.Where(n => !string.IsNullOrEmpty(n))
                            .Sum(n => int.Parse(n));
        
        return answer;
    }
}