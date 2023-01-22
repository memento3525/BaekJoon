using System.Linq;

public class Solution {
    public int solution(int n) {
        
        if(n == 0 || n == 1)
            return n;
        else
            return Enumerable.Range(1, n)
                         .Where(e => n % e == 0)
                         .Aggregate((e, next) => e + next);
    }
}