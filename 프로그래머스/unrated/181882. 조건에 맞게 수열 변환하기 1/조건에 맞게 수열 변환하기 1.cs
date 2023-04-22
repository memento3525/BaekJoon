using System;
using System.Linq;

public class Solution {
    public int[] solution(int[] arr) {
        return arr.Select(s => {
                          if(s >= 50 && s % 2 == 0)
                            return s / 2;
                          else if(s < 50 && s % 2 == 1)
                              return s * 2;
                          else
                              return s;
                          }).ToArray();
    }
}