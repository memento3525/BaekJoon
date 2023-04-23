using System;
using System.Linq;

public class Solution {
    public int[] solution(string myString) {
        string[] splited = myString.Split('x');
        return splited.Select(w => w.Length).ToArray();
    }
}