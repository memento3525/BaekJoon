using System;

public class Solution {
    public int[] solution(int denum1, int num1, int denum2, int num2) {

        int parent = num1 * num2;
        int child = denum1 * num2 + denum2 * num1;

        while(true)
        {
            int gcd = parent > child ? GCD(parent, child) : GCD(child, parent);
            if(gcd > 1)
            {
                child /= gcd;
                parent /= gcd;
            }
            else
            {
                break;
            }
        }

        return new int[2] {child, parent};
    }

    public int GCD(int a, int b)
    {
        int r = 0;
        while(b != 0)
        {
            r = a % b;
            a = b;
            b = r;
        }

        return a;
    }
}