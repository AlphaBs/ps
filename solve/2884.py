i = input().split()
h = int(i[0])
m = int(i[1])

alarm = 45

mInterval = m - alarm

if (mInterval >= 0):
    print(h, mInterval)
else:
    h -= 1
    if (h < 0):
        h = 24 + h
    print(h, 60 + mInterval)