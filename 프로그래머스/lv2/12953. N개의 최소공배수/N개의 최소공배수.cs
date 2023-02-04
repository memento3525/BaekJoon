using System.Linq;

public class Solution {
    public int solution(int[] arr) {
        return arr.Aggregate((a, next) => LCM(a, next));
    }
    
    private int GCD(int a, int b)
    {
        int c;
        while(b != 0)
        {
            c = a % b;
            a = b;
            b = c;
        }
        return a;
    }
    
    private int LCM(int a, int b) 
        => (a * b) / GCD(a, b);
}