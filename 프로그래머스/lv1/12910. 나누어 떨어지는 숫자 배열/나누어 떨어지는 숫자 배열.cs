using System.Linq;

public class Solution {
    public int[] solution(int[] arr, int divisor) {
        var enumer = arr.Where(e => e % divisor == 0);
        if(enumer.Count() > 0)
            return enumer.OrderBy(e => e).ToArray();
        else
            return new int[]{ -1 };
    }
}