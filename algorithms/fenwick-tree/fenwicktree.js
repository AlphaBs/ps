setInput(`
10
1
2
3
4
5
6
7
8
9
10`)

class FenwickTree {
    constructor(capacity) {
        this.tree = new Array(capacity + 1)
    }

    sum(pos) {
        pos++
        let res = 0
        while (pos > 0) {
            res += this.tree[pos]
            pos &= (pos - 1)
        }
    }

    add(pos, value) {
        pos++
        while (pos < this.tree.length) {
            if (!this.tree[pos]) { // prevent `undefined`
                this.tree[pos] = 0
            }

            this.tree[pos] += value
            pos += (pos & -pos)
        }
    }
}

function main() {
    const n = Number(readline())
    const tree = new FenwickTree(n)
    for (let i = 0; i < n; i++) {
        let input = Number(readLine())
        tree.add(i, input)
    }

    for (let i = 0; i < n; i++) {
        writeLine(tree.sum(i))
    }
}