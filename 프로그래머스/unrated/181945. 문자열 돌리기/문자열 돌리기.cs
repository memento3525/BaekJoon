using System;

public class Example
{
    public static void Main()
    {
        Console.Clear();
        String s = Console.ReadLine();

        foreach(char c in s)
            Console.WriteLine(c);
    }
}