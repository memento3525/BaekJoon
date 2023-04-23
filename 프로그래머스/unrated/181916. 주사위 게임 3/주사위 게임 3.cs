using System;
using System.Linq;

public class Solution {
    public int solution(int a, int b, int c, int d) 
    {
        var list = new int[4]{ a, b, c, d};
        
        var arr = list.GroupBy(g => g)
                      .OrderByDescending(g => g.Count())
                      .Select(s => (s.Key, s.Count()))
                      .ToArray();
        
        if(arr[0].Item2 == 4) // 4
        {
            return 1111 * arr[0].Item1;
        }
        else if(arr[0].Item2 == 3) // 3, 1
        {
            return (int)Math.Pow(10 * arr[0].Item1 + arr[1].Item1, 2);
        }
        else if(arr[0].Item2 == 2)
        {
            if(arr[1].Item2 == 2) // 2, 2
            {
                return (arr[0].Item1 + arr[1].Item1) * Math.Abs(arr[0].Item1 - arr[1].Item1);
            }
            else // 2, 1, 1
            {
                return arr[1].Item1 * arr[2].Item1;
            }
        }
        else // 1, 1, 1, 1
        {
            return list.Min();
        }
        
        int answer = 0;
        return answer;
    }
}