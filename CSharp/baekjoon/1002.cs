//1002

using System;

class Program
{
	public static void Main(string[] args)
	{
		var testCase = int.Parse(Console.ReadLine());
		
		for (int tc = 0; tc < testCase; tc++)
		{
			var spl = Console.ReadLine().Split(' ');
			
			var x1 = int.Parse(spl[0]);
			var y1 = int.Parse(spl[1]);
			var r1 = int.Parse(spl[2]);
			var x2 = int.Parse(spl[3]);
			var y2 = int.Parse(spl[4]);
			var r2 = int.Parse(spl[5]);
			
			if (r1 == r2 && x1 == x2 && y1 == y2)
			{
				Console.WriteLine("-1");
				continue;
			}
			
			var p = Math.Pow(x2 - x1 , 2) + Math.Pow(y2 - y1, 2);
		 	var d = Math.Sqrt(p);

			int result = 0;
			if (d + r2 == r1 || d + r1 == r2)
				result = 1;
			else if (d + r2 < r1 || d + r1 < r2)
				result = 0;
			else
			{
				var r = r1 + r2;
				
				if (r < d)
					result = 0;
				else if (r == d)
					result = 1;
				else if (r > d)
					result = 2;
			}
			Console.WriteLine(result);
		}
	}
}