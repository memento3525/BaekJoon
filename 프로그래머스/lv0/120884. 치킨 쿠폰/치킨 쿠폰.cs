using System;

public class Solution {
    public int solution(int chicken) {
        int answer = 0;
        
        int mainChicken = chicken;
        int remainedChicken = 0;
        
        while(true)
        {
            int bonus = mainChicken / 10;
            remainedChicken = mainChicken % 10;
            
            if(bonus == 0)
                break;
            
            answer += bonus;
            mainChicken = remainedChicken + bonus;
            bonus = 0;
        }
        
        return answer;
    }
}