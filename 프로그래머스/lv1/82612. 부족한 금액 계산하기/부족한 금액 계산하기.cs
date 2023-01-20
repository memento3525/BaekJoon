using System;

class Solution
{
    public long solution(int price, int money, int count)
    {
        int allRepeatCount = count * (count + 1) / 2;
        long allPrice = price * (long)allRepeatCount;
        long lackMoney = allPrice - money;
        
        return lackMoney > 0 ? lackMoney : 0;
    }
}