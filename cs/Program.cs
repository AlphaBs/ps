var c = () => Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
var spl = c();
var (m, n) = (spl[0], spl[1]);

// 1: 익음, 0: 안익음, -1: 없음
var map = new int[m, n];
var initCount = 0;
for (int y = 0; y < n; y++)
{
    spl = c();
    for (int x = 0; x < m; x++)
    {
        if ((map[x, y] = spl[x]) == 0)
            initCount++;
    }
}

// xy: 익은 토마토의 좌표
// 주위 토마토를 익힘
int process((int, int) xy)
{
    (int x, int y) = xy;
    if (map[x, y] < 1)
        return 0;

    int updated = 0;
    var visited = new bool[m, n];
    visited[x, y] = true;

    var q = new Queue<(int, int)>();
    q.Enqueue((x, y));

    void enq(int x, int y)
    {
        if (map[x, y] == 0 && !visited[x, y])
        {
            updated++;
            map[x, y] = 1;
            visited[x, y] = true;
            q.Enqueue((x, y));
        }
    }

    while (q.Any())
    {
        (x, y) = q.Dequeue();
        if (x > 0) // LEFT
        {
            enq(x - 1, y);
        }
        if (x < m - 1) // RIGHT
        {
            enq(x + 1, y);
        }
        if (y > 0) // UP
        {
            enq(x, y - 1);
        }
        if (y < n - 1) // DOWN
        {
            enq(x, y + 1);
        }
    }

    return updated;
}

void writeMap()
{
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            Console.Write(map[x, y] + " ");
        }
        Console.WriteLine();
    }
}

int day = 0;
int updated = 0;
while (updated >= initCount)
{
    int updatedDay = 0;
    var q = new Queue<(int, int)>();
    var visited = new bool[m, n];

    void enq(int x, int y)
    {
        if (map[x, y] == 0 && !visited[x, y])
        {
            updatedDay++;
            map[x, y] = 1;
            visited[x, y] = true;
            q.Enqueue((x, y));
        }
    }

    for (int y = 0; y < n; y++)
        for (int x = 0; x < m; x++)
        {
            if (visited[x, y] || map[x, y] < 1)
                continue;

            visited[x, y] = true;
            q.Enqueue((x, y));

            while (q.Any())
            {
                (int a, int b) = q.Dequeue();
                if (a > 0) // LEFT
                {
                    enq(a - 1, b);
                }
                if (a < m - 1) // RIGHT
                {
                    enq(a + 1, b);
                }
                if (b > 0) // UP
                {
                    enq(a, b - 1);
                }
                if (b < n - 1) // DOWN
                {
                    enq(a, b + 1);
                }
            }
        }

    if (updatedDay == 0)
    {
        day = -1;
        break;
    }

    updated += updatedDay;
    day++;

    Console.WriteLine($"day={day}, updated={updated}");
    writeMap();
}

Console.WriteLine(day);
writeMap();