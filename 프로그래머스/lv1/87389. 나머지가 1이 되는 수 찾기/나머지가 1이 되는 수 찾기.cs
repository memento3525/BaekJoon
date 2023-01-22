using System;
using System.Linq;

public class Solution {
    public int solution(int n) {
        
        // x = (n - 1) / b
        // n - 1의 가장 작은 1이 아닌 약수를 넣으면 되는 듯?
        
        int targetNum = n - 1;
        return Enumerable.Range(2, targetNum - 1).First(e => targetNum % e == 0);
    }
}