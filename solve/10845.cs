using System.Text;
var sb = new StringBuilder();
var q = new Queue<int>();
var n = int.Parse(Console.ReadLine());
var back = -1;
while (n-->0)
{
    var spl = Console.ReadLine().Split();
    switch(spl[0])
    {
        case "push":
            back = int.Parse(spl[1]);
            q.Enqueue(back);
            break;
        case "pop":
            if (q.TryDequeue(out int v1))
                sb.AppendLine(v1.ToString());
            else
                sb.AppendLine("-1");
            break;
        case "size":
            sb.AppendLine(q.Count.ToString());
            break;
        case "empty":
            sb.AppendLine(q.Count == 0 ? "1" : "0");
            break;
        case "front":
            if (q.TryPeek(out int v2))
                sb.AppendLine(v2.ToString());
            else
                sb.AppendLine("-1");
            break;
        case "back":
            if (q.Count == 0)
                sb.AppendLine("-1");
            else
                sb.AppendLine(back.ToString());
            break;
    }
}
Console.WriteLine(sb.ToString());