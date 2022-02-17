var n = int.Parse(Console.ReadLine());
var stack = new Stack<int>();
var lst = new List<char>();
var nextN = 1;
for (int i = 0; i < n; i++)
{
	var v = int.Parse(Console.ReadLine());
    while (nextN <= v)
    {
        lst.Add('+');
        stack.Push(nextN);
        nextN++;
    }
    if (stack.Count == 0 || stack.Peek() != v)
    {
        Console.WriteLine("NO");
        return;
    }
    lst.Add('-');
    stack.Pop();
}
Console.Write(string.Join('\n', lst));