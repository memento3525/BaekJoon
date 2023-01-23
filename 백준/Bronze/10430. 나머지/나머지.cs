using System;

public class Solution
{
    static void Main()
    {
        string y = Console.ReadLine();
        string[] splited = y.Split();

        int a = Convert.ToInt32(splited[0]);
        int b = Convert.ToInt32(splited[1]);
        int c = Convert.ToInt32(splited[2]);

        Console.WriteLine((a + b) % c);
        Console.WriteLine(((a % c) + (b % c)) % c);
        Console.WriteLine((a * b) % c);
        Console.WriteLine(((a % c) * (b % c)) % c);
    }
}