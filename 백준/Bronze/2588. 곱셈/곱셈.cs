using System;

public class Solution
{
    static void Main()
    {
        string aInput = Console.ReadLine();
        int a = Convert.ToInt32(aInput);

        string bInput = Console.ReadLine();
        int b = Convert.ToInt32(bInput);
        
        Console.WriteLine(a * (b % 10));
        Console.WriteLine(a * ((b / 10) % 10));
        Console.WriteLine(a * ((b / 100) % 10));
        Console.WriteLine(a * b);
    }
}