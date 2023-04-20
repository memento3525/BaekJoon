using System;
using System.Linq;

public class Solution {
    public int solution(string[] order) 
    {
        int cafelatte = order.Count(c => c.Contains("cafelatte"));
        int americano = order.Length - cafelatte;
        
        return cafelatte * 5000 + americano * 4500;
    }
}