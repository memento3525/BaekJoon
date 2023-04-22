using System;
using System.Linq;

public class Solution {
    public int[] solution(int[] num_list) {
        return num_list.OrderBy(o => o).Take(5).ToArray();
    }
}