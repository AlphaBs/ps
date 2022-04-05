n = int(input())
points = list(map(lambda x: {"x1":int(x), "x2":0}, input().split()))
sortPoints = sorted(points, key=lambda x:x["x1"])

newPoint = 0
for i in range(0,n):
    sortPoints[i]["x2"] = newPoint
    if i != n - 1 and sortPoints[i]["x1"] != sortPoints[i+1]["x1"]:
        newPoint += 1


for i in range(n):
    print(points[i]["x2"], end=" ")