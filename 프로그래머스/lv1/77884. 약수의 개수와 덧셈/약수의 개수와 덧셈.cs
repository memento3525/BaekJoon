using System.Linq;

public class Solution {
    public int solution(int left, int right) {
        return Enumerable.Range(left, right - left + 1)
                             .Select(e => IsDivisorCountEven(e) ? e : -e )
                             .Sum();
    }
    
    private bool IsDivisorCountEven(int num)
    {
        int divisorCount = Enumerable.Range(1, num).Count(e => num % e == 0);
        return divisorCount % 2 == 0;
    }
}