public class Solution {
    public int solution(int n) {
        
        if(n == 0) return 0;
        if(n == 1) return 1;
        
        int n1 = 0;
        int n2 = 1;
        for(int i = 2; i < n + 1; i++)
        {
            int temp2 = n2;
            
            n2 = (n1 + n2) % 1234567; // long으로도 넘어서 나눠야함.
            n1 = temp2;
        }
        
        return n2;
    }
}