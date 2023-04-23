using System;
using System.Linq;

public class Solution {
    public string[] solution(string[] todo_list, bool[] finished) {
        return todo_list.Where((w, index) => !finished[index]).ToArray();
    }
}