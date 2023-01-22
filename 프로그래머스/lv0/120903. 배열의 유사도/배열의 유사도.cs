using System;

public class Solution {
    public int solution(string[] s1, string[] s2) {
        
        int count = 0;
        foreach(var item1 in s1)
            foreach(var item2 in s2)
                if(item1 == item2) count++;
        
        return count;
    }
}