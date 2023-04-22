using System;
using System.Linq;

public class Solution {
    public int solution(string num_str) {
        return num_str.Select(s => s - '0').Sum();
    }
}