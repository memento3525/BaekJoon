using System;
using System.Linq;

public class Solution {
    public int solution(string number) {
        return number.Select(s => s - '0').Sum() % 9;
    }
}