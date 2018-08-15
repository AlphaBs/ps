// 1011

using System;

class Program
{
	public static void Main(string[] args)
	{
		int testCount = int.Parse(Console.ReadLine());
		
		for (int t = 0; t < testCount; t++)
		{
			var spl = Console.ReadLine().Split(' ');
			var a = int.Parse(spl[0]);
			var b = int.Parse(spl[1]);
			
			var range = b - a;
			long prex = 1;
			var hol = 1;
			
			for (int i = 1;;i++)
			{
				var ix = (long)Math.Pow(i,2);
				if (ix > range)
				{
					bool isn = (ix + prex - 1) / 2 >= range;
					int result = hol - (isn ? 1 : 0);
					Console.WriteLine(result);
					break;
				}
				else if (ix == range)
				{
					Console.WriteLine(hol);
					break;
				}
				else
				{
					prex = ix;
					hol += 2;
				}
			}
		}
	}
}