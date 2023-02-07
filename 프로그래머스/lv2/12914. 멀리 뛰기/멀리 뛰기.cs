public class Solution {
    public long solution(int n) {
        
        if(n == 1) return 1;
        
        long[] k = new long[n];
        k[0] = 1;
        k[1] = 2;
        
        for(int i = 2; i < n; i++)
            k[i] = (k[i - 1] + k[i - 2]) % 1234567;
        
        return k[n - 1];
    }
}