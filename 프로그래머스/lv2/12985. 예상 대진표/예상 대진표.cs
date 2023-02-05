using System;

class Solution
{
    public int solution(int n, int a, int b)
    {
        if(a > b)
            (a, b) = (b, a);
        
        int round = 1;
        while(!(a % 2 == 1 && (b - a) == 1)) // 작은 쪽이 홀수면서 차이가 1일때까지.
        {
            a = (a + 1) / 2;
            b = (b + 1) / 2;
            round++;
        }

        return round;
    }
}