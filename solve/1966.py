from copyreg import constructor


class Page:
    def __init__(self, id, prior):
        self.id = id
        self.prior = prior
    
tc = int(input())
for i in range(tc):
    n, m = map(int, input().split())
    q = list()
    id = 1
    for snum in input().split():
        q.append(Page(id, int(snum)))
        id = id + 1

    targetId = q[m].id
    count = 0
    while len(q) > 0:
        current = q.pop(0)
        hasUpper = False

        for j in range(len(q)):
            if current.prior < q[j].prior:
                hasUpper = True
                break
        
        if hasUpper:
            q.append(current)
        else:
            count = count + 1
            if targetId == current.id:
                print(count)
                break