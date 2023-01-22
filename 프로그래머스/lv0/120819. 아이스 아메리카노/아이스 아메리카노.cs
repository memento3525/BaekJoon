using System;

public class Solution {
    public int[] solution(int money) {
        int price = 5500;
        int coffeCount = money / price;
        int remainMoney = money % price;
        
        return new int[2] {coffeCount, remainMoney};
    }
}