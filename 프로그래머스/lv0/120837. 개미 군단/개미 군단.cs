using System;

public class Solution {
    public int solution(int hp) {
        
        int[] ATKs = new int[]{5, 3};
        
        int remainHp = hp;
        int antCount = 0;
        
        foreach(int atk in ATKs)
        {
            antCount += remainHp / atk; 
            remainHp %= atk; 
        }
        
        antCount += remainHp;
        
        return antCount;
    }
}