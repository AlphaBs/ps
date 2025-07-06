# https://www.acmicpc.net/problem/22859

import sys
sys.setrecursionlimit(11111)
doc = sys.stdin.readline().strip()
pos = 0

def moveUntil(ch):
    global pos

    buf = []
    while pos < len(doc) and doc[pos] != ch:
        buf.append(doc[pos])
        pos += 1
    return "".join(buf)

def readTag():
    global pos

    pos += 1 # <
    if doc[pos] == '/':
        pos += 1
        tagName = moveUntil('>')
        pos += 1 # >
        return { "name": tagName, "isOpening": False }
    elif pos + 3 < len(doc) and \
            doc[pos + 0] == 'd' and \
            doc[pos + 1] == 'i' and \
            doc[pos + 2] == 'v' and \
            doc[pos + 3] == ' ':
        moveUntil('"')
        pos += 1
        title = moveUntil('"')
        moveUntil('>')
        pos += 1
        return { "name": "div", "isOpening": True, "title": title }
    else:
        tagName = moveUntil('>')
        pos += 1 # >
        return { "name": tagName, "isOpening": True }

def readParagraph():
    p = ""

    while pos < len(doc):
        token = moveUntil('<')
        p += token

        tag = readTag()
        if tag["name"] == 'p' and not tag["isOpening"]:
            break

    p = ' '.join(p.split())
    p = p.strip()

    return p

while pos < len(doc):
    tag = readTag()
    if tag["name"] == "main":
        continue
    elif tag["name"] == "div" and tag["isOpening"]:
        print("title : " + tag["title"])
    elif tag["name"] == "p" and tag["isOpening"]:
        p = readParagraph()
        print(p)