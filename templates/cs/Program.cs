var line = Console.ReadLine()!;
var me = Console.ReadLine()!;
Console.Write(
    line
        .Split(' ')
        .Select((score, i) => (score, i + 1))
        .First(e => e.score == me)
        .Item2 switch 
        {
            <=  5 => "A+",
            <= 15 => "A0",
            <= 30 => "B+",
            <= 35 => "B0",
            <= 45 => "C+",
            <= 48 => "C0",
            _ => "F"
        }
);