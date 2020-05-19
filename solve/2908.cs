//2908

using System;

class Program
{
	public static void Main(string[] args)
	{
		var input = Console.ReadLine();
		var spl = input.Split(' ');
		
		var f_ch = spl[0].ToCharArray();
		var b_ch = spl[1].ToCharArray();
		Array.Reverse(f_ch);
		Array.Reverse(b_ch);
		
		var f_int = int.Parse(new string(f_ch));
		var b_int = int.Parse(new string(b_ch));
		
		if (f_int > b_int)
			Console.Write(f_int);
		else
			Console.Write(b_int);
	}
}