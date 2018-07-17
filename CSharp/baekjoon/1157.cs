// save

using System;
using System.Text;

class Program
{
    public static void Main()
    {
      var input = Console.ReadLine().ToCharArray();
      var result = new int[26];
      foreach (char item in input)
      {
        byte ch = (byte)item;

        if (ch >= 97)
          ch -= 32;
        ch -= 65;

        result[ch]++;
      }
		
      int max = -1;
      int index = 0;
      for(int i = 0; i < result.Length; i++)
      {
		//Console.WriteLine("{0}은 {1}번 나옴", (char)(i+65),result[i]);
        if (max < result[i])
        {
          	max = result[i];
          	index = i;
			//Console.WriteLine("BIG {0},{1}", max, index);
        }
        else if (max == result[i])
        {
			index = -1;
        } 
      }
 
      if (index == -1)
        Console.Write("?");
      else
      {
        var chRs = (char)(index + 65);
        Console.Write(chRs);
      }
    }
}
