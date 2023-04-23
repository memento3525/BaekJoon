using System;
using System.Linq;

public class Solution {
    public string[] solution(string[] strArr) {
        return strArr.Where(w => !w.Contains("ad")).ToArray();
    }
}