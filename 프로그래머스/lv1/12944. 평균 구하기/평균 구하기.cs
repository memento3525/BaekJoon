public class Solution {
    public double solution(int[] arr) {
        
        int sum = 0;
        
        foreach(int num in arr)
            sum += num;
        
        return sum / (double)arr.Length;
    }
}