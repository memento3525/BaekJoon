using System;

public class Solution
{
    static void Main()
    {
        string s = Console.ReadLine();
        string[] strArray = s.Split();

        int a = Convert.ToInt32(strArray[0]);
        int b = Convert.ToInt32(strArray[1]);

        Console.WriteLine(a + b);
    }
}