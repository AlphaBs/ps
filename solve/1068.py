# https://www.acmicpc.net/problem/1068

import sys
sys.setrecursionlimit(111_111)
n = int(sys.stdin.readline()) # [1,50]

tree = [[] for i in range(55)]
parentsInput = list(map(int, sys.stdin.readline().split()))
nodeToRemove = int(sys.stdin.readline())

for i in range(n):
    if parentsInput[i] == -1:
        root = i
    elif i != nodeToRemove:
        tree[parentsInput[i]].append(i)

def findLeaves(node):
    children = tree[node]
    if len(children) == 0:
        return 1
    
    leaves = 0
    for child in children:
        leaves += findLeaves(child)
    return leaves

if root == nodeToRemove:
    print(0)
else:
    print(findLeaves(root))