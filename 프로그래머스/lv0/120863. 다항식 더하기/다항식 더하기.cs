using System;
using System.Linq;
using System.Collections.Generic;

public class Solution {
    public string solution(string polynomial) {
        string[] splitedStrArray = polynomial.Split(new char[2]{' ', '+'}, StringSplitOptions.RemoveEmptyEntries);
        
        // 1차 항
        int polySum = splitedStrArray.Where(n => n.Contains("x"))
                                      .Select(n => 
                                      {
                                          string numStr = n.Replace("x", "");
                                          return string.IsNullOrEmpty(numStr) ? 1 : int.Parse(numStr);
                                      }).Sum();
        
        // 상수 항
        int constSum = splitedStrArray.Where(n => !n.Contains("x"))
                                      .Select(n => int.Parse(n)).Sum();


        if(polySum > 0)
        {
            string polyResult = $"{polySum == 1 ? "" : polySum.ToString()}x";
            return constSum > 0 ? $"{polyResult} + {constSum}" : polyResult;
        }
        else
        {
            return $"{constSum}";
        }
    }
}