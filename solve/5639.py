# https://www.acmicpc.net/problem/5639

import sys
sys.setrecursionlimit(111_111)

trees = {}
root = None

def addNode(root, node):
    if root not in trees:
        trees[root] = [None, None]

    if root > node:
        if trees[root][0] is None:
            trees[root][0] = node
        else:
            addNode(trees[root][0], node)
    else:
        if trees[root][1] is None:
            trees[root][1] = node
        else:
            addNode(trees[root][1], node)

for line in sys.stdin:
    if root is None:
        root = int(line)
    else:
        addNode(root, int(line))

def traversal(root):
    if root is None:
        return
    if root in trees:
        traversal(trees[root][0])
        traversal(trees[root][1])
    sys.stdout.write(f'{root}\n')

traversal(root)