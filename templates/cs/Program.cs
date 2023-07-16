var nextLine = () => Console.ReadLine()?.Split().Select(x => int.Parse(x)).ToArray();
var line = nextLine();
var (a, b) = (line[0], line[1]);
Console.WriteLine($"{a}, {b}");