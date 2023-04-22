using System;

public class Example
{
    public static void Main()
    {
        Console.Clear();
        String[] s = Console.ReadLine().Split(' ');

        int num = Int32.Parse(s[0]);
        string word = num % 2 == 0 ? "even" : "odd";
        Console.WriteLine($"{num} is {word}");
    }
}