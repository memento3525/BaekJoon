using System;

public class Example
{
    public static void Main()
    {
        Console.Clear();
        String[] s = Console.ReadLine().Split(' ');

        Console.WriteLine($"a = {Int32.Parse(s[0])}");
        Console.WriteLine($"b = {Int32.Parse(s[1])}");
    }
}