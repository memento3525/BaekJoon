using System;
using System.Linq;

public class Solution {
    public int solution(int order) {
        return order.ToString()
                    .Count(n => 
                           {
                               int num = (int)char.GetNumericValue(n);
                               return num != 0 && num % 3 == 0;
                           });
    }
}