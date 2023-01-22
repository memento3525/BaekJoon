using System;
using System.Linq;
using System.Text;

public class Solution {
    public string solution(string cipher, int code) {
        
        
        return string.Concat(cipher.Where((n, i) => (i + 1) % code == 0));
        
        /*
        int length = cipher.Length / code;
        var enumuerables = Enumerable.Range(0, length)
                                     .Select(n => cipher[(n + 1) * code - 1]);
        
        StringBuilder sb = new StringBuilder();
        foreach (var item in enumuerables)
            sb.Append(item);
        
        return sb.ToString();*/
    }
}