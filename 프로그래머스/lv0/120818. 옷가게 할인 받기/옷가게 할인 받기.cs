using System;

public class Solution {
    public int solution(int price) {
        
        float discountedPrice = price;
        
        if(price >= 500000)
        {
            discountedPrice *= 0.8f;
        }
        else if(price >= 300000)
        {
            discountedPrice *= 0.9f;
        }
        else if(price >= 100000)
        {
            discountedPrice *= 0.95f;
        }
        
        return (int)Math.Floor(discountedPrice);
    }
}