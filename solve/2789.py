n, m = map(int, input().split())
cards = list(map(int, input().split()))
sorted(cards, reverse=True)
targetCardNumber = 3
targetCards = [-1,-1,-1]

def find(targetIndex, startIndex, fn):
    for i in range(startIndex, len(cards)):
        foundCardNumber = cards[i]
        if fn < foundCardNumber:
            continue
        
        if (targetIndex >= targetCardNumber - 1):
            foundNextValue = foundCardNumber
        else:
            foundNextValue = find(targetIndex+1, i, fn - foundCardNumber)

        if foundNextValue:
            targetCards[targetIndex] = foundCardNumber
            return foundCardNumber

    return -1

find(0, 0, m)
print(targetCards)