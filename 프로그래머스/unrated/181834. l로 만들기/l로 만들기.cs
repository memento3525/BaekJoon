using System;
using System.Linq;

public class Solution {
    public string solution(string myString){
        return new string(myString.Select(s => s - 'l' > 0 ? s : 'l').ToArray());
    }
}