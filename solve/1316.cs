//1316

using System;

class Program
{
	public static void Main(string[] args)
	{
		const byte aChar = 97;
		
		var inputCount = int.Parse(Console.ReadLine());
		
		int groupCount = 0;
		
		for(int i = 0; i < inputCount; i++)
		{
			var input = Console.ReadLine()
				.ToCharArray();
			
			var alphabet = new bool[26];
			char preChar = '\0';
			bool result = true;
			
			for (int j = 0; j < input.Length; j++)
			{
				char nowChar = input[j];
				if (preChar != nowChar)
				{
					int arrIndex = nowChar - aChar;
					if (alphabet[arrIndex])
					{
						result = false;
						break;
					}
					else
						alphabet[arrIndex] = true;
				}
				preChar = nowChar;
			}
			
			if (result)
				groupCount++;
		}
		
		Console.Write(groupCount);
	}
}