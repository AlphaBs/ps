//2292

using System;

class Program
{
	public static void Main(string[] args)
	{
		var input = int.Parse(Console.ReadLine());
		
		if (input == 1)
		{
			Console.Write(1);
			return;
		}
		
		int f = 2;
		int b = 7;
		int p = 5;
		
		int i = 2;
		while(true)
		{
			//Console.WriteLine("{0}, {1}, {2}", f, b, p);
			
			if (f <= input && input <= b)
			{
				Console.Write(i);
				return;
			}
			
			p += 6;
			f = b + 1;
			b = f + p;
	
			i++;
		}
	}
}