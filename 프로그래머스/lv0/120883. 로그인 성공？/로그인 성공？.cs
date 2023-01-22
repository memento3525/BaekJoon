using System;
using System.Linq;

public class Solution {
    public string solution(string[] id_pw, string[,] db) {
        
        string id = id_pw[0];
        string pw = id_pw[1];
        
        for(int x = 0; x < db.GetLength(0); x++)
        {        
            if(id == db[x, 0])
            {
                if(pw == db[x, 1])
                    return "login";
                else
                    return "wrong pw";
            }
        }
        
        return "fail";
    }
}