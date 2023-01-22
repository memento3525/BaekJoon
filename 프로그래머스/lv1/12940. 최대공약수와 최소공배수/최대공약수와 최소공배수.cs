public class Solution {
    public int[] solution(int n, int m) {
        int gcd = GCD(n, m);
        int lcm = n * m / gcd;
        return new int[2] {gcd, lcm};
    }
    
    private int GCD(int a, int b)
    {
        if(b == 0) return a;
        return GCD(b, a % b);
    }
}