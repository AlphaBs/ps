from math import sqrt

d, h, w = map(int, input().split())
dr = sqrt(w**2 + h**2)
r = d / dr
print(int(h*r), int(w*r))