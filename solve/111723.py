n = int(input())
s = set()
for i in range(n):
    spl = input().split()
    cmd = spl[0]
    if len(spl) == 2:
        val = int(spl[1])
    if cmd == "add":
        s.add(val)
    elif cmd == "remove":
        if val in s:
            s.remove(val)
    elif cmd == "check":
        if val in s:
            print("1")
        else:
            print("0")
    elif cmd == "toggle":
        if cmd in s:
            s.remove(val)
        else:
            s.add(val)
    elif cmd == "all":
        s = set(range(1,21))
    elif cmd == "empty":
        s.clear()
