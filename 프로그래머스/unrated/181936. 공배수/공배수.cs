using System;

public class Solution {
    public int solution(int number, int n, int m) {
        if(number % n != 0) return 0;
        if(number % m != 0) return 0;
        return 1;
    }
}