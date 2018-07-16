using System;

public class main {
	public static void Main() {
		var input = int.Parse(Console.ReadLine());
		for (int i = 0; i <= (input / 3 + 1); i++)
		{
			for (int j = 0; j <= (input / 5 + 1); j++)
			{
				Console.WriteLine("{0}, {1}", i ,j);
				int k = i * 3 + j * 5;
				if (k == input)
				{
					Console.Write(i + j);
					return;
				}
			}
		}
		Console.Write("-1");
	}
}