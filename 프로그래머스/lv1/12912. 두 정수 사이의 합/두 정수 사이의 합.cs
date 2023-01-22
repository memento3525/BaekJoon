using System.Linq;

public class Solution {
    public long solution(int a, int b) {
        
        if(a == b)
            return a;
        
        int min = a > b ? b : a;
        int max = a > b ? a : b;
        
        long answer = 0;
        foreach(long num in Enumerable.Range(min, max - min + 1))
            answer += num;
        
        return answer;
    }
}