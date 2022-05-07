import math

a, b, v = map(int, input().split()) # 5 1 6
result = math.ceil((v-a) / (a-b)) + 1 
print(result)
