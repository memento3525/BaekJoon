using System;
using System.Linq;

public class Solution {
    public string solution(string my_string, int s, int e) {
        return new string(my_string.Select((c, index) => 
                            {
                                if(s <= index && index <= e)
                                    return my_string[s + e - index];
                                else
                                    return c;
                            }).ToArray());
    }
}