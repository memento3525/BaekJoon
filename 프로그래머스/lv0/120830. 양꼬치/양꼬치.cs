using System;

public class Solution {
    public int solution(int n, int k) {
        
        int lamb = 12000 * n;
        int service = (n / 10);
        int drink = 2000 * (k - service);
        
        return lamb + drink;
    }
}