using System;
using System.Collections.Generic;

public class Solution {
    public int solution(int n) {
         
        IEnumerator<int> enumerator = GetXNumEnumerator();
        for(int i = 0; i < n; i++)
            enumerator.MoveNext();
        
        return enumerator.Current;
    }
    
    public IEnumerator<int> GetXNumEnumerator()
    {
        int result = 0;
        while(true)
        {
            result++;
            if(result % 3 == 0) continue;
            if(result.ToString().Contains("3")) continue;
            
            yield return result;
        }
    }
}