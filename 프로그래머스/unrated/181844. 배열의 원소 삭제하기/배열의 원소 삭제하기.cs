using System;
using System.Linq;

public class Solution {
    public int[] solution(int[] arr, int[] delete_list) {
        return arr.Where(w => !delete_list.Contains(w)).ToArray();
    }
}