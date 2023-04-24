using System;
using System.Linq;

public class Solution {
    public string solution(int q, int r, string code) {
        return new string(code.Where((w, index) => index % q == r).ToArray());
    }
}