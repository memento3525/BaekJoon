using System.Collections.Generic;
using System.Linq;

public class Solution {
    public bool solution(int x) {
        
        List<int> list = new List<int>();
        
        int remainder = x;
        while(remainder > 0)
        {
            list.Add(remainder % 10);
            remainder /= 10;
        }
        
        return x % list.Sum() == 0;
    }
}