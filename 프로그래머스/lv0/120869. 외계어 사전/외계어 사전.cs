using System;
using System.Linq;

public class Solution {
    public int solution(string[] spell, string[] dic) {
        
        bool reuslt = dic.Where(n => n.Length == spell.Length)
                      .Any(n => 
                           {
                               bool isExist = true;
                               foreach(string item in spell)
                               {
                                   if(!n.Contains(item))
                                   {
                                       isExist = false;
                                       break;
                                   }
                               }
                               return isExist;
                           });

        return reuslt ? 1 : 2;
    }
}