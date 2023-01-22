using System;

public class Solution {
    public long solution(long n) {
        long sqrt = (long)Math.Sqrt(n);
        if(n == sqrt * sqrt)
            return (long)Math.Pow(sqrt + 1, 2);
        else
            return -1;
    }
}