using System;
using System.Linq;
using System.Collections;
using System.Text;

public class Solution {
    
    readonly string[] morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
    public string solution(string letter) {
        
        string answer = "";
        
        string[] splitedStrArray = letter.Split(' ');
        var temp = splitedStrArray.Where(n => true).Select(n => Array.IndexOf(morse, n) + 97)
                                       .Select(n => Convert.ToChar(n));
        
        StringBuilder sb = new StringBuilder();
        foreach(char item in temp)
            sb.Append(item);
        
        return sb.ToString();
    }
}