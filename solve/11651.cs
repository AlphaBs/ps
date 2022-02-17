using System.Text;

int n = int.Parse(Console.ReadLine());
var locations = new Location[n];
for (int i = 0; i < n; i++)
{
    var s = Console.ReadLine().Split();
    locations[i] = new Location()
    {
        X = int.Parse(s[0]),
        Y = int.Parse(s[1])
    };
}

Array.Sort(locations, (Location t1, Location t2) =>
{
    if (t1.Y == t2.Y)
        return t1.X - t2.X;
    return t1.Y - t2.Y;
});

var sb = new StringBuilder();
foreach (var item in locations)
{
    sb.Append(item.X);
    sb.Append(' ');
    sb.Append(item.Y);
    sb.AppendLine();
}

Console.Write(sb.ToString());

struct Location
{
    public int X;
    public int Y;
}