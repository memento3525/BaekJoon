using System;

public class Solution {
    public int solution(string my_string, string is_suffix) {
        int index = my_string.LastIndexOf(is_suffix);
        if(index == -1) return 0;
        return index == my_string.Length - is_suffix.Length ? 1 : 0;
    }
}