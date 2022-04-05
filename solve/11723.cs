using System.Text;
var sb = new StringBuilder();
var n = int.Parse(Console.ReadLine());
var s = new HashSet<byte>();
while (n-- > 0)
{
    var spl = Console.ReadLine().Split();
    var cmd = spl[0];
    byte val = 0;
    if (spl.Length == 2)
         val = byte.Parse(spl[1]);

    switch (cmd)
    {
        case "add":
            s.Add(val);
            break;
        case "remove":
            s.Remove(val);
            break;
        case "check":
            sb.AppendLine(s.Contains(val) ? "1" : "0");
            break;
        case "toggle":
            if (!s.Remove(val))
                s.Add(val);
            break;
        case "all":
            s = new HashSet<byte>();
            for (byte i = 1; i <= 20; i++)
                s.Add(i);
            break;
        case "empty":
            s.Clear();
            break;
    }
}
Console.WriteLine(sb.ToString());