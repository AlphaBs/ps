//1193

using System;

class Program
{
	public static void Main(string[] args)
	{
		int input = int.Parse(Console.ReadLine());
		
		int num = 1;
		
		for (int i = 1; i > 0; i++)
		{
			for (int j = 1; j < i; j++)
			{
				int a, b;
				if (i % 2 == 0)
				{
					a = i - j;
					b = j;
				}
				else
				{
					a = j;
					b = i - j;
				}
				
				if (input == num)
				{
					Console.Write("{0}/{1}", a, b);
					return;
				}
				
				num++;
			}
		}
	}
}