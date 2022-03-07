n, m = map(int, input().split())
cards = list(map(int, input().split()))
cards.sort(reverse=True)
targetCardNumber = 3
targetCards = [-1,-1,-1]
bestsum = 0

def find(targetIndex, startIndex, fn):
    global bestsum
    for i in range(startIndex, len(cards)):
        foundCardNumber = cards[i]
        if fn < foundCardNumber:
            continue
        
        targetCards[targetIndex] = foundCardNumber

        if (targetIndex >= targetCardNumber - 1):
            s = sum(targetCards)
            if bestsum < s:
                bestsum = s
        else:
            find(targetIndex+1, i+1, fn - foundCardNumber)

find(0, 0, m)
print(bestsum)