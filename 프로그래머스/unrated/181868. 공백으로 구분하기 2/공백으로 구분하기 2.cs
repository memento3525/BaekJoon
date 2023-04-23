using System;
using System.Linq;

public class Solution {
    public string[] solution(string my_string) {
        return my_string.Split().Where(w => !string.IsNullOrWhiteSpace(w)).ToArray();
    }
}