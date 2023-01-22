using System;

public class Solution {
    public int solution(string before, string after) {
        
        if(before.Length != after.Length) return 0;
        
        char[] beforeCharArray = before.ToCharArray();
        Array.Sort(beforeCharArray);
        char[] afterCharArray = after.ToCharArray();
        Array.Sort(afterCharArray);
        
        for(int i = 0; i < beforeCharArray.Length; i++)
        {
            if(beforeCharArray[i] != afterCharArray[i])
                return 0;
        }
        
        return 1;
    }
}