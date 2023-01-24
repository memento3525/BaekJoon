using System;
using System.Linq;
using System.Text;

public class Solution {
    public string solution(int[] food) {
        
        var sb = new StringBuilder();
        for(int i = 0; i < food.Length; i++)
        {
            if(food[i] < 2)
                continue;
            
            int foodNum = food[i] / 2;
            
            for(int k = 0; k < foodNum; k++)
                sb.Append(i.ToString());
        }
        
        string str = sb.ToString();
        sb.Append("0");
        for (int i = str.Length - 1; i >= 0; i--) 
            sb.Append(str[i]);
        
        return sb.ToString();
    }
}