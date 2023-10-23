# https://www.acmicpc.net/problem/1991

import sys

n = int(sys.stdin.readline())
edges = {}
for i in range(n):
    node, left, right = sys.stdin.readline().split()
    edges[node] = [left, right]

def traverse(root, mode):
    if root == ".":
        return
    
    left, right = edges[root]    
    if mode == 1:
        sys.stdout.write(root)
    traverse(left, mode)
    if mode == 2:
        sys.stdout.write(root)
    traverse(right, mode)
    if mode == 3:
        sys.stdout.write(root)

traverse("A", 1)
print()
traverse("A", 2)
print()
traverse("A", 3)